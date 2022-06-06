#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setting.h"
#include "paintdoc.h"
#include "newcanvasdialog.h"
#include <QDebug>
#include <QMdiSubWindow>
#include <QFileDialog>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>

MainWindow* MainWindow::ins = nullptr;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), settingWidget{nullptr, nullptr, nullptr}, curWidget(nullptr),
    ui(new Ui::MainWindow)
{
    ins = this;
    ui->setupUi(this);

    statusLabel = new QLabel;
    ui->statusBar->addWidget(statusLabel);
    QLabel *verinfo = new QLabel("qt大作业—— easyPainter/made by lx_tyin.", this);
    verinfo->setStyleSheet("color: #adadad;");
    ui->statusBar->addPermanentWidget(verinfo);

    settingWidget[0] = new setting_pen;
    settingWidget[1] = new setting_eraser;
    settingWidget[2] = new setting_bucket;
    showSetting(0);
    ui->ToolList->setCurrentRow(0);

//    QWidget *titlebar = ui->ToolBox->titleBarWidget(); //偏方：删除工具箱的标题栏
//    if(titlebar) titlebar->setPalette(QPalette(QPalette::Window, Qt::white));

    connect(ui->ToolList, &QListWidget::itemPressed, [&](QListWidgetItem *item){ //选择工具
        showSetting(ui->ToolList->row(item));
    });
    connect(ui->ToolBox, &QDockWidget::visibilityChanged, [&](bool visable){ //开关工具箱
        if(!visable) ui->action_Tool->setChecked(false);
    });
    connect(ui->mdiArea, &QMdiArea::subWindowActivated, [&](QMdiSubWindow *sub){ //选中子文档
        if(!sub) return; //删除最后一个文档时 会激活Null?
        PaintDoc *doc = dynamic_cast<PaintDoc*>(sub->widget());
        statusLabel->setText(QString("当前画布大小：%1 x %2").arg(doc->width).arg(doc->height));
    });
}

void MainWindow::showSetting(int p) {
    if(curWidget){
        curWidget->setParent(nullptr);
        ui->toolBoxContent->layout()->removeWidget(curWidget);
    }
    curWidget = settingWidget[p];
    ui->toolBoxContent->layout()->addWidget(curWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete settingWidget[0];
    delete settingWidget[1];
    delete settingWidget[2];
}

void MainWindow::on_action_New_triggered() {
    newCanvasDialog dlg(this);
    QSize res;
    connect(&dlg, &newCanvasDialog::sizeConfirmed, [&](QSize size){
        res = size;
    });
    if(dlg.exec() != QDialog::Accepted) return;

    PaintDoc *ndoc = new PaintDoc(res.width(), res.height());
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(ndoc);
    child->setWindowTitle("未命名画布");
    child->show();
    ndoc->autoFixSize();
}

void MainWindow::on_action_Open_triggered(){
    QString path = QFileDialog::getOpenFileName(this, "打开一张图片", QDir::currentPath(),
                                                "图片文件(*.jpg *.png)");
    if(!path.isEmpty()){
        PaintDoc *ndoc = new PaintDoc(QImage(path));
        QMdiSubWindow *child = ui->mdiArea->addSubWindow(ndoc);
        child->setWindowTitle(path);
        child->show();
        ndoc->autoFixSize();
    }
}

void MainWindow::on_action_Save_triggered(){
    QString path = QFileDialog::getSaveFileName(this, "保存图片", QDir::currentPath(),
                                                "图片文件(*.jpg *.png)");
    if(!path.isEmpty()){
        PaintDoc *doc = dynamic_cast<PaintDoc*>(ui->mdiArea->currentSubWindow()->widget());
        auto img = doc->combinedImage();
        img.save(path);
        ui->mdiArea->currentSubWindow()->setWindowTitle(path);
    }
}

void MainWindow::on_action_Tool_triggered(bool checked) {
    if(checked) ui->ToolBox->show();
    else ui->ToolBox->close();
}

void MainWindow::on_action_Revoke_triggered(){
    PaintDoc *doc = dynamic_cast<PaintDoc*>(ui->mdiArea->currentSubWindow()->widget());
    if(doc) doc->revoke();
}

int MainWindow::currentTool() {
    for(int i=0;i<3;i++) if(ins->curWidget == ins->settingWidget[i]) return i;
    return -1;
}

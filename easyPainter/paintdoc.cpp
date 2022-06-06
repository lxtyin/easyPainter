
#include "paintdoc.h"
#include "ui_paintdoc.h"
#include "layer.h"
#include <QDebug>
#include <QPainter>
#include <QWheelEvent>
#include <QScrollBar>

PaintDoc::PaintDoc(int w, int h, QWidget *parent) :
        width(w), height(h), default_num(1), view_scale(1),
        QWidget(parent), ui(new Ui::PaintDoc) {

    ui->setupUi(this);
    ui->scrollArea->viewport()->installEventFilter(this);
    canvas = new Canvas(this, ui->layerList, ui->scrollAreaWidgetContents);

    Layer *layer = new Layer(width, height); //建一个初始图层 不记录历史
    layer->setText("图层" + QString::number(default_num++));
    ui->layerList->addItem(layer);
    ui->layerList->setCurrentItem(layer);
    ui->layerList->update();
    autoFixSize();
}

//从已有图像创建
PaintDoc::PaintDoc(QImage sor, QWidget *parent):
        PaintDoc(sor.width(), sor.height(), parent)
{
    delete ui->layerList->item(0);
    Layer *layer = new Layer(QPixmap::fromImage(sor));  //用图片作为图层
    layer->setText("图层" + QString::number(default_num++));
    ui->layerList->addItem(layer);
    ui->layerList->setCurrentItem(layer);
    ui->layerList->update();
}

PaintDoc::~PaintDoc() {
    delete canvas;
    delete ui;
}

//撤销
void PaintDoc::revoke(){
    if(hist.empty()) return;
    history cur = hist.back();
    cur.revoke();
    canvas->update();
    hist.pop_back();
}
void PaintDoc::addHistory(history _h){
    _h.from = ui->layerList;
    hist.push_back(_h);
    if(hist.count() > MAX_HISTORY) hist.pop_front();
}

void PaintDoc::autoFixSize(){
    //粗略估计一个初始缩放比例 恰好容纳画布
    ui->scaleSlider->setValue(std::max(ui->scrollArea->width() * 100 / width,
                                       ui->scrollArea->height() * 100 / height));
}

QSize PaintDoc::scaledSize() {
    return QSize(width * view_scale, height * view_scale);
}

QRect PaintDoc::canvasShowRect(){
    QRect res = QRect(-canvas->geometry().topLeft()
                - ui->scrollAreaWidgetContents->geometry().topLeft(),
                      ui->scrollArea->size());
    return res.intersected(canvas->rect());
}

//所有图层叠加
QImage PaintDoc::combinedImage(){
    QImage final = QImage(width, height, QImage::Format_ARGB32);
    final.fill(QColor(0, 0, 0, 0));
    QPainter p(&final);
    for(int i=ui->layerList->count()-1;i>=0;i--){
        auto *item = dynamic_cast<Layer*>(ui->layerList->item(i));
        if(item->visible) p.drawImage(0, 0, *item->img);
    }
    return final;
}

void PaintDoc::on_addLayerButton_clicked() {
    Layer *layer = new Layer(width, height);
    layer->setText("图层" + QString::number(default_num++));
    ui->layerList->addItem(layer);
    ui->layerList->setCurrentItem(layer);
    ui->layerList->update();

    addHistory(history('+', layer));
}

void PaintDoc::on_delLayerButton_clicked() {
    if(ui->layerList->count() > 1){
        auto *layer = dynamic_cast<Layer*>(ui->layerList->currentItem());
        addHistory(history('-', layer));
        ui->layerList->takeItem(ui->layerList->row(layer));
        emit ui->layerList->layerChanged();
    }
}

void PaintDoc::on_hideLayerButton_clicked() {
    Layer *layer = dynamic_cast<Layer*>(ui->layerList->currentItem());
    layer->visible = !layer->visible;
    layer->updateStyle();
    emit ui->layerList->layerChanged();
}

void PaintDoc::on_scaleSlider_valueChanged(int val){

    QWidget *view = ui->scrollArea->viewport(); //视口
    QPoint curpos = QCursor::pos(); //鼠标位置
    QPoint foucs = view->mapFromGlobal(curpos); //视口焦点
    if(!QRect(0, 0, view->width(), view->height()).contains(foucs)){
        foucs = {view->width() / 2, //鼠标在视口之外
                  view->height() / 2};
    }
    QPoint pixpos = canvas->mapFromGlobal(view->mapToGlobal(foucs)) / view_scale; //像素焦点

    //缩放
    view_scale = val * 1.0 / 100;
    int w = width * view_scale, cw = fmax(w * 1.2, view->width());
    int h = height * view_scale, ch = fmax(h * 1.2, view->height());
    ui->scrollAreaWidgetContents->setMinimumSize(cw, ch);
    canvas->setGeometry(cw/2 - w/2, ch/2 - h/2, w, h);

    //缩放后 像素所处的视口位置
    QPoint foucs2 = view->mapFromGlobal(canvas->mapToGlobal(pixpos * view_scale));
//    qDebug() << foucs2;

    int wvalue = ui->scrollArea->horizontalScrollBar()->value() - foucs.x() + foucs2.x();
    wvalue = std::min(ui->scrollArea->horizontalScrollBar()->maximum(), wvalue);
    wvalue = std::max(0, wvalue);
    int hvalue = ui->scrollArea->verticalScrollBar()->value() - foucs.y() + foucs2.y();
    hvalue = std::min(ui->scrollArea->verticalScrollBar()->maximum(), hvalue);
    hvalue = std::max(0, hvalue);
    ui->scrollArea->horizontalScrollBar()->setValue(wvalue);
    ui->scrollArea->verticalScrollBar()->setValue(hvalue);

//    QPoint foucs3 = view->mapFromGlobal(canvas->mapToGlobal(pixpos * view_scale));
//    qDebug() << foucs3;
}

void PaintDoc::wheelEvent(QWheelEvent *ev){
    if(QApplication::keyboardModifiers() == Qt::AltModifier){
        float sc = ui->scaleSlider->value();
        ui->scaleSlider->setValue(sc + float(ev->delta()) / 15);
    }
}

//针对水平滚动条的过滤器 让alt+滚轮触发PaintDoc的事件
bool PaintDoc::eventFilter(QObject *obj, QEvent *ev){
    if(obj == ui->scrollArea->viewport()){
        if(ev->type() == QEvent::Wheel && QApplication::keyboardModifiers() == Qt::AltModifier){
            return true; //采取PaintDoc的滚动事件
        }
    }
    return false;
}


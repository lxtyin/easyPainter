//
// Created by lx_tyin on 2022/5/13.
//

#include "layer.h"
#include "setting.h"
#include <Qimage>
#include <QPainter>
#include <QDropEvent>
#include "mainwindow.h"
#include <QDebug>
#include <QQueue>

Layer::Layer(int w, int h, QListWidget *parent):
    visible(true), QListWidgetItem(parent), img(new QImage(w, h, QImage::Format_ARGB32)) {

    buff = QPainterPath();
    onepot = QPoint(-1, -1);

    QFont font;
    font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")); //微软雅黑
    font.setPointSize(14);
    setFont(font);
    updateStyle();

    setFlags(Qt::ItemIsSelectable|
             Qt::ItemIsEditable|
             Qt::ItemIsDragEnabled|
             Qt::ItemIsUserCheckable|
             Qt::ItemIsEnabled); //设置可编辑，可调换顺序等

    img->fill(QColor(0, 0, 0, 0));
    setIcon(QIcon(QPixmap::fromImage(*img)));

}

Layer::Layer(const QPixmap &pix, QListWidget *parent):
    Layer(pix.width(), pix.height(), parent)
{
    *img = pix.toImage();
    setIcon(QIcon(QPixmap::fromImage(*img)));
}

Layer::~Layer() {
    delete img;
}

//返回是否有未绘制的内容
bool Layer::hasBuff(){
    return onepot.x() >= 0 || !buff.isEmpty();
}

void Layer::updateStyle() {
    if(visible){
        QBrush brush(QColor(117, 195, 255, 255));
        brush.setStyle(Qt::BDiagPattern);
        setTextColor(QColor(0, 0, 0));
        setBackground(brush);
    }else{
        QBrush brush(QColor(234, 227, 227, 255));
        brush.setStyle(Qt::BDiagPattern);
        setTextColor(QColor(100, 100, 100));
        setBackground(brush);
    }
}

void Layer::pushBuffTo(QImage *tar) {
    if(!hasBuff()) return;
    switch (MainWindow::currentTool()) {
        case TOOL_PEN:{
            QPainter p(tar);
            p.setPen(QPen(QBrush(setting_pen::color, Qt::BrushStyle(setting_pen::sparse+1)), setting_pen::size,
                          Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            if(onepot.x() >= 0) p.drawPoint(onepot); //单点处理
            else p.drawPath(buff);
            break;
        }
        case TOOL_ERASER:{
            QPainter p(tar);
            p.setCompositionMode(QPainter::CompositionMode_DestinationOut);
            QColor era(255, 255, 255, setting_eraser::soft);
            p.setPen(QPen(QBrush(era, Qt::SolidPattern), setting_eraser::size,
                          Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            if(onepot.x() >= 0) p.drawPoint(onepot); //单点处理
            else p.drawPath(buff);
            break;
        }
    }
}

//松开时绘制，更新图标
void Layer::releaseEnd(QPoint pot){
    pushBuffTo(img);
    buff = QPainterPath();
    onepot = QPoint(-1, -1);
    setIcon(QIcon(QPixmap::fromImage(*img)));
}

void Layer::clickStart(QPoint pot) {
    onepot = pot;
    buff = QPainterPath();
    buff.moveTo(pot);
}

//颜料桶绘制
void Layer::paintBucket(QPoint pot){
    auto diff = [](const QColor &a, const QColor &b){
        return sqrt((a.red()-b.red()) * (a.red()-b.red()) +
                    (a.green()-b.green()) * (a.green()-b.green()) +
                    (a.blue()-b.blue()) * (a.blue()-b.blue()) +
                    (a.alpha()-b.alpha()) * (a.alpha()-b.alpha()));
    };
    QPoint dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int toler = setting_bucket::toler, w = img->width(), h = img->height();
    QImage buff(w, h, QImage::Format_ARGB32); // 同样采用一个buff暂存的形式 做到几次填涂可叠加
    buff.fill(QColor(0, 0, 0, 0));
    QQueue<QPoint> q;
    q.enqueue(pot);

    while(!q.isEmpty()){
        QPoint p = q.dequeue();
        for(int i=0;i<4;i++){
            QPoint v = p;
            v += dir[i];
            if(v.x() >= 0 && v.y() >= 0 && v.x() < w && v.y() < h &&
               buff.pixelColor(v) == QColor(0, 0, 0, 0) &&
               diff(img->pixelColor(v), img->pixelColor(p)) <= toler){
                buff.setPixelColor(v, setting_bucket::color);
                q.enqueue(v);
            }
        }
    }
    QPainter p(img);
    p.drawImage(0, 0, buff);
}

//buff中添加一个拖拽点
void Layer::dragPoint(QPoint p){
    onepot = QPoint(-1, -1);
    buff.lineTo(p);
}
//
// Created by lx_tyin on 2022/5/13.
//

#include "canvas.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include "layer.h"
#include "paintdoc.h"
#include "mainwindow.h"
#include "setting.h"

Canvas::Canvas(PaintDoc *_fromDoc, LayerList *_layers,QWidget *parent):
    QWidget(parent), fromDoc(_fromDoc), layers(_layers) {
    setStyleSheet("background-image: url(:/images/img/back.png);");

    connect(layers, &LayerList::layerChanged, [&](){update();}); // 图层切换绑定刷新
}

// 由canvas接受消息，比例缩放后，传递给当前图层
void Canvas::mousePressEvent(QMouseEvent *event) {
    QPoint pos = event->pos() / fromDoc->view_scale;
    Layer *layer = dynamic_cast<Layer*>(layers->currentItem());
    if(MainWindow::currentTool() == TOOL_BUCKET){
        fromDoc->addHistory(history('*', layer, layer->img));
        layer->paintBucket(pos);
    }else{
        layer->clickStart(pos);
    }
    update();
    QWidget::mouseMoveEvent(event);
}

void Canvas::mouseReleaseEvent(QMouseEvent *event){
    Layer *layer = dynamic_cast<Layer*>(layers->currentItem());
    if(layer->hasBuff()){
        fromDoc->addHistory(history('*', layer, layer->img));
        layer->releaseEnd(event->pos() / fromDoc->view_scale);
        update();
    }
    QWidget::mouseReleaseEvent(event);
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton){ //按下左键
        dynamic_cast<Layer*>(layers->currentItem())->dragPoint(event->pos() / fromDoc->view_scale);
        update();
    }
    QWidget::mouseMoveEvent(event);
}

// 在画布上显示所有图层
void Canvas::paintEvent(QPaintEvent *event){

    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setClipRegion(event->region().intersected(fromDoc->canvasShowRect()));
    //绘制样式表（方格透明背景
    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    QPixmap final = QPixmap(fromDoc->width, fromDoc->height); //绘制可能pixmap比较快？
    final.fill(QColor(0, 0, 0, 0));
    QPainter painter2(&final); //先将所有图叠一起，再一并缩放
    for(int i=layers->count()-1;i>=0;i--){
        auto *item = dynamic_cast<Layer*>(layers->item(i));
        if(item->visible){
            auto img = *item->img;
            item->pushBuffTo(&img);
            painter2.drawPixmap(0, 0, QPixmap::fromImage(img));
        }
    }
    painter.drawPixmap(0, 0, final.scaled(fromDoc->scaledSize()));
}

void Canvas::enterEvent(QEvent *event) {
    QWidget::enterEvent(event);

    switch(MainWindow::currentTool()){
        case TOOL_BUCKET:{
            setCursor(QCursor(QPixmap(":/images/img/bucket_cursor.png")));
            break;
        }
        case TOOL_PEN:{
            int len = qMax(int(fromDoc->view_scale * setting_pen::size), 5);//最少5x5大小 防止看不清
            QPixmap pix(len, len);
            pix.fill(QColor(0, 0, 0, 0));
            QPainter p(&pix);
            p.setPen(QPen(QBrush(Qt::black), 2));
            p.drawEllipse(0, 0, len, len);
            setCursor(QCursor(pix));
            break;
        }
        case TOOL_ERASER:{
            int len = qMax(int(fromDoc->view_scale * setting_eraser::size), 5);//最少5x5大小 防止看不清
            QPixmap pix(len, len);
            pix.fill(QColor(0, 0, 0, 0));
            QPainter p(&pix);
            p.setPen(QPen(QBrush(Qt::black), 2));
            p.drawEllipse(0, 0, len, len);
            setCursor(QCursor(pix));
            break;
        }
        default:{
            setCursor(Qt::ArrowCursor);
        }
    }
}

void Canvas::leaveEvent(QEvent *event) {
    QWidget::leaveEvent(event);
    QApplication::restoreOverrideCursor();
}
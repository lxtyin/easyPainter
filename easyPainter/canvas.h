//
// Created by lx_tyin on 2022/5/13.
//

#ifndef MAIN_CPP_CANVAS_H
#define MAIN_CPP_CANVAS_H

#include <QWidget>
#include "layerlist.h"

class PaintDoc;

class Canvas: public QWidget {
    Q_OBJECT;
    PaintDoc *fromDoc; //所属文档，从此获取显示比例等设置属性
    LayerList *layers; //源图层列表
public:
    Canvas(PaintDoc *_fromDoc, LayerList *_layers, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);        //重载绘图事件
    void mousePressEvent(QMouseEvent *event);   //重载各种鼠标事件，主要要在画布阶段检测用户操作，
    void mouseReleaseEvent(QMouseEvent *event); //应用缩放和一些必要的处理后直接把具体的绘图指令传递给Layer
    void mouseMoveEvent(QMouseEvent *event);

    void enterEvent(QEvent *event);  //重载鼠标进入离开事件，实现鼠标在画布内时改变鼠标样式
    void leaveEvent(QEvent *event);  
};


#endif //MAIN_CPP_CANVAS_H

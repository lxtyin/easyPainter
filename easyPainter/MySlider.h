//
// Created by lx_tyin on 2022/5/17.
//

#ifndef MAIN_CPP_MYSLIDER_H
#define MAIN_CPP_MYSLIDER_H

#include <QSlider>
#include <QLabel>
#include <QMouseEvent>

class MySlider: public QSlider {
    Q_OBJECT
    QLabel *hint;
public:
    int (*valuefunc)(int); //值函数

    MySlider(QWidget *parent = nullptr);
    int realVal();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};


#endif //MAIN_CPP_MYSLIDER_H

//
// Created by lx_tyin on 2022/5/17.
//

#include "MySlider.h"

MySlider::MySlider(QWidget *parent):
    QSlider(parent){

    valuefunc = [](int x){return x;};

    hint = new QLabel(this);
    hint->setFixedSize(24, 15);
    hint->setVisible(false);
    hint->setStyleSheet("font: 9pt \"Consolas\";\n"
                        "color: rgb(32, 207, 255);");
    hint->setAlignment(Qt::AlignCenter);
}

int MySlider::realVal() {
    return valuefunc(value());
}

void MySlider::mousePressEvent(QMouseEvent *event) {
    setSliderPosition((maximum() - minimum()) * event->pos().x() / width() + minimum());
    hint->setVisible(true);
    hint->setText(QString::number(realVal()));
    hint->move((width() - hint->width()) * (value()-minimum())/(maximum()-minimum()) , height()/2 - hint->height());

    QSlider::mousePressEvent(event); //默认event后置 可以使鼠标按下后继续拖动
}

void MySlider::mouseReleaseEvent(QMouseEvent *event) {
    QSlider::mouseReleaseEvent(event);
    hint->setVisible(false);
}

void MySlider::mouseMoveEvent(QMouseEvent *event) {
    QSlider::mouseMoveEvent(event);
    if(event->buttons() & Qt::LeftButton){
        hint->setText(QString::number(realVal()));
        hint->move((width() - hint->width()) * (value()-minimum())/(maximum()-minimum()) , height()/2 - hint->height());
    }
}

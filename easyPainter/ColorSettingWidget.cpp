//
// Created by lx_tyin on 2022/5/17.
//

#include "ColorSettingWidget.h"
#include "ColorPicker/ColorPicker.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>

ColorSettingWidget::ColorSettingWidget(QWidget *parent): QWidget(parent){

    back = new QLabel(this);
    button = new QPushButton(this);
    color = QColor(0, 0, 0, 255);

    button->setGeometry(QRect(QPoint(0, 0), size()));
    back->setGeometry(QRect(QPoint(0, 0), size()));

    back->setStyleSheet("background-image: url(:/images/img/back.png);");
    button->setStyleSheet("QPushButton{\n"
                          "border: 4px solid #e3e5ee;\n"
                          "background-color: #ff000000;\n"
                          "}");

    connect(button, &QPushButton::clicked, this, &ColorSettingWidget::buttonClicked);
}

ColorSettingWidget::~ColorSettingWidget() noexcept{
    delete button;
}

void ColorSettingWidget::resizeEvent(QResizeEvent *ev){
    QWidget::resizeEvent(ev);
    button->resize(size());
    back->resize(size());
}

void ColorSettingWidget::buttonClicked() {
    ColorPickDialog *dlg = new ColorPickDialog(this);
    dlg->setColor(color);

    QPoint tmpPos = mapToGlobal(QPoint(width()/2, height()/2));
    tmpPos += QPoint(-dlg->width() / 2, height() / 2 + 5);
    dlg->move(tmpPos);

    connect(dlg, &ColorPickDialog::sig_colorChanged, [&](const QColor &c){
        color = c;
        emit colorChanged(c);
        button->setStyleSheet("QPushButton{\n"
                              "border: 4px solid #e3e5ee;\n"
                              "background-color:" + c.name(QColor::HexArgb) + ";\n"
                              "}");
    });

    dlg->open();
}

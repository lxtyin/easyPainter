//
// Created by lx_tyin on 2022/5/17.
//

#ifndef MAIN_CPP_COLORSETTINGWIDGET_H
#define MAIN_CPP_COLORSETTINGWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QResizeEvent>
#include <QPaintEvent>

class ColorSettingWidget: public QWidget{
    Q_OBJECT
    QLabel *back;
    QPushButton *button;
    QColor color;
public:
    ColorSettingWidget(QWidget *parent = nullptr);
    ~ColorSettingWidget();

    void resizeEvent(QResizeEvent *ev);

signals:
    void colorChanged(const QColor &col);

public slots:
    void buttonClicked();

};


#endif //MAIN_CPP_COLORSETTINGWIDGET_H

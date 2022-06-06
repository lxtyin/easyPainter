//
// Created by lx_tyin on 2022/5/13.
//

#ifndef MAIN_CPP_PAINTDOC_H
#define MAIN_CPP_PAINTDOC_H

#include <QWidget>
#include "canvas.h"
#include "layer.h"
#include "history.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class PaintDoc; }
QT_END_NAMESPACE

const int MAX_HISTORY = 10; //最大容纳历史记录数量

class PaintDoc : public QWidget {
    Q_OBJECT
    Ui::PaintDoc *ui;
    Canvas *canvas;      //画布
    QList<history> hist; //历史记录列表
public:
    float view_scale;    //显示比例
    int width, height;   //画布大小
    int default_num;     //图层自动名称编号值

    PaintDoc(int w, int h, QWidget *parent = nullptr);
    PaintDoc(QImage sor, QWidget *parent = nullptr);
    ~PaintDoc() override;
    
    void revoke();              //撤销
    void addHistory(history _h);//新增历史记录

    void autoFixSize();     //自动调整显示比例以符合画布大小
    QSize scaledSize();     //返回按显示比例缩放后应有的尺寸
    QRect canvasShowRect(); //canvas在视口中截面的rect
    QImage combinedImage(); //将所有图层组合得到一个img
protected:
    void wheelEvent(QWheelEvent *ev) override;          //重载滚轮事件 实现Alt+滚轮定焦缩放
    bool eventFilter(QObject *obj, QEvent *ev) override;//scrollArea自带滚轮事件的处理，将其过滤掉

public slots:
    //几个图层按钮的槽函数
    void on_addLayerButton_clicked();   //创建图层
    void on_delLayerButton_clicked();   //删除图层，应用于当前图层
    void on_hideLayerButton_clicked();  //隐藏图层，应用于当前图层
    void on_scaleSlider_valueChanged(int val); //滑动条改变值的槽函数，处理缩放和定焦缩放
};

#endif //MAIN_CPP_PAINTDOC_H

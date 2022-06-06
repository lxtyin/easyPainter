//
// Created by lx_tyin on 2022/5/13.
//

#ifndef MAIN_CPP_LAYER_H
#define MAIN_CPP_LAYER_H

#include <QListWidgetItem>
#include <QPainterPath>

class Layer: public QListWidgetItem {
public:
    bool visible; //是否可见
    QImage *img;  //图像
    QPoint onepot; //单点绘制特判
    QPainterPath buff; //绘制笔迹缓存区

    Layer(int w, int h, QListWidget *parent = nullptr);
    Layer(const QPixmap &pix, QListWidget *parent = nullptr);
    ~Layer();

    void pushBuffTo(QImage *tar); //将缓存绘制到目标图
    void updateStyle(); //根据visible更改显示样式

    bool hasBuff(); //是否有未绘制的内容（buff或onepot）

    //具体绘制命令
    void releaseEnd(QPoint p); //鼠标释放，将缓存绘制到图像上
    void clickStart(QPoint p); //鼠标按下，开始记录笔迹
    void paintBucket(QPoint p);//油漆桶绘制
    void dragPoint(QPoint p);  //鼠标拖拽，添加一个笔迹点
};


#endif //MAIN_CPP_LAYER_H

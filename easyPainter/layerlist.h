//
// Created by lx_tyin on 2022/5/15.
//

#ifndef MAIN_CPP_LAYERLIST_H
#define MAIN_CPP_LAYERLIST_H

#include <QListWidget>
#include "layer.h"

const int ITEM_WIDTH = 240;
const int ITEM_HEIGHT = 30;

class LayerList: public QListWidget{
    Q_OBJECT
    bool isdragging;  //是否在拖拽
    int curInsertRow; //拖拽时，即将插入的行号
public:
    LayerList(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event); //重载各类事件 都是为了实现图层拖拽
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

    void updateInsertRow(int row); //拖拽鼠标移动时 要实时更新即将插入的行

signals:
    void layerChanged(); //图层变动信号 -> Canvas刷新

};


#endif //MAIN_CPP_LAYERLIST_H

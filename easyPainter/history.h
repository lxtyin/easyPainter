//
// Created by lx_tyin on 2022/5/21.
//

#ifndef MAIN_CPP_HISTORY_H
#define MAIN_CPP_HISTORY_H

#include "layer.h"
#include "layerlist.h"

//记录类型：绘制(*)，增加图层(+)，删除图层(-)
//撤销：对于删除图层的重做，仅将图层恢复到最底部，不会考虑顺序
//此类仅作为历史记录 不做恢复处理

//历史记录类
class history{
    char type;     //记录类型，'+'，'-'，'*'
    Layer *target; //操作图层
    QImage oriImg; //对于绘制操作，暴力存储绘前图像
public:
    LayerList *from; //所操作图层来自的layerlist

    history(char _t, Layer* _tar);
    history(char _t, Layer* _tar, QImage *_ori);
    ~history();    //析构函数中分情况处理图层的销毁
    void revoke(); //撤销此条记录
};

#endif //MAIN_CPP_HISTORY_H

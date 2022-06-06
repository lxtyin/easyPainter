//
// Created by lx_tyin on 2022/5/21.
//

#include "history.h"
#include <QDebug>

history::history(char _t, Layer *_tar): type(_t), target(_tar) {}
history::history(char _t, Layer *_tar, QImage *_ori): history(_t, _tar){
    oriImg = *_ori;
}
history::~history(){
    if(type == '-'){
        //被删除的图层，仅当其删除历史记录也被删除时，才彻底消失
        if(from->row(target) < 0) delete target; //画布中不存在
    }
}

void history::revoke(){
    switch(type){
        case '+':{
            delete target;
            break;
        }
        case '-':{
            from->addItem(target);
            from->setCurrentItem(target);
            break;
        }
        case '*':{
            *target->img = oriImg;
            break;
        }
    }
}

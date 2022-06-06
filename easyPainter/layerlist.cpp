//
// Created by lx_tyin on 2022/5/15.
// Mainly dealing with drag and drop
//

#include "layerlist.h"
#include "layer.h"
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QDrag>
#include <QDebug>
#include <assert.h>
#include <QPainter>

LayerList::LayerList(QWidget *parent): QListWidget(parent) {
    curInsertRow = -1;
    setAcceptDrops(true);
    setDragEnabled(true);
}

void LayerList::mousePressEvent(QMouseEvent *event){
    QListWidget::mousePressEvent(event);

    Layer *item = dynamic_cast<Layer*>(itemAt(event->pos())); //获取鼠标点击位置的Layer
    if(!item) return;
    isdragging = true;
}

void LayerList::mouseReleaseEvent(QMouseEvent *event) {
    QListWidget::mouseReleaseEvent(event);
    updateInsertRow(-1);
    isdragging = false;
}

void LayerList::mouseMoveEvent(QMouseEvent *event) { //在move中exec, 避免阻塞双击事件
    if(!isdragging) return;

    Layer *item = dynamic_cast<Layer*>(itemAt(event->pos())); //获取鼠标点击位置的Layer
    if(!item) return;

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << QPixmap::fromImage(*item->img) << item->visible << item->text(); // 获取这张图片，拖拽时传递图片和是否可见（即Layer的全部信息）
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("Drag_Layer", itemData); //自定义类型，便于接收方检测

    QPixmap pix = QPixmap(ITEM_WIDTH, ITEM_HEIGHT); //设定拖拽时显示的图片样式
    pix.fill(QColor(127, 127, 127, 50));
    QFont font;
    font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")); //微软雅黑
    font.setPointSize(14);
    QPainter painter(&pix);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(pix.rect(), Qt::AlignCenter, item->text());

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pix);
    drag->setHotSpot(QPoint(pix.width() / 2, pix.height() / 2)); // 设置鼠标固定在缩略图上的位置

    int fromrow = row(item); //拖拽时先拿走，如放弃拖拽再塞回来
    takeItem(fromrow);
    if(drag->exec(Qt::MoveAction | Qt::CopyAction) == Qt::MoveAction){ // 如要移动 直接删除原有的
        assert(item);
        delete item;
    }else{ //否则放回
        assert(item);
        insertItem(fromrow, item);
    }
}

void LayerList::dragEnterEvent(QDragEnterEvent *event) {
    if(event->mimeData()->hasFormat("Drag_Layer")){
        if(event->source() == this) event->setDropAction(Qt::MoveAction);
        else event->setDropAction(Qt::CopyAction); //如果拖到其他文档的图层列表中，就是Copy
        event->accept();
    }else{
        event->ignore();
    }
}

void LayerList::dragMoveEvent(QDragMoveEvent *event) { //计算当前插入位置
    if(event->mimeData()->hasFormat("Drag_Layer")){
        auto *cur = itemAt(event->pos() + QPoint(0, ITEM_HEIGHT / 2));
        if(!cur) cur = itemAt(event->pos()); //当恰好遇到间隔时取不到，上下随便取哪个，向上取半层必定不是间隔
        if(!cur) cur = item(count() - 1); //最下面
        if(row(cur) != curInsertRow){
            updateInsertRow(row(cur)); //重绘指示针
        }
        event->accept();
    }else event->ignore();
}

void LayerList::dragLeaveEvent(QDragLeaveEvent *event) {
    updateInsertRow(-1);
}

void LayerList::dropEvent(QDropEvent *event) {
    if(event->mimeData()->hasFormat("Drag_Layer")){
        QByteArray itemData = event->mimeData()->data("Drag_Layer");
        QDataStream dataStram(&itemData, QIODevice::ReadOnly);
        QPixmap pix;
        bool visible;
        QString str;
        dataStram >> pix >> visible >> str;

        Layer *item = new Layer(pix /*, this*/);
        item->visible = visible;
        item->setText(str);
        item->updateStyle();

        delete takeItem(curInsertRow);
        insertItem(curInsertRow, item); //替换掉待插入块
        curInsertRow = -1;
        setCurrentItem(item); //先插入，再删除
        emit layerChanged();

        if(event->source() == this) event->setDropAction(Qt::MoveAction);
        else event->setDropAction(Qt::CopyAction); //如果拖到其他文档的图层列表中，就是Copy
        event->accept();
    }else{
        event->ignore();
    }
}

void LayerList::updateInsertRow(int row) { //更新插入指示块（绿色插入块）
    if(curInsertRow != -1){
        delete takeItem(curInsertRow);
    }
    curInsertRow = row;
    if(row != -1){
        QListWidgetItem *newItem = new QListWidgetItem;
        QBrush brush(QColor(38, 255, 45, 127));
        brush.setStyle(Qt::BDiagPattern);
        newItem->setBackground(brush);
        insertItem(row, newItem);
        setCurrentItem(newItem); //绿色插入块存在时，始终高亮
    }
}
//
// Created by lx_tyin on 2022/5/18.
//

#ifndef MAIN_CPP_NEWCANVASDIALOG_H
#define MAIN_CPP_NEWCANVASDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui{ class newCanvasDialog; }
QT_END_NAMESPACE

class newCanvasDialog : public QDialog{
Q_OBJECT

    float lockedRate; //锁定宽高比，宽/高
    int width, height;
public:

    explicit newCanvasDialog(QWidget *parent = nullptr);

    void updateText();
    ~newCanvasDialog() override;

    signals:
    void sizeConfirmed(QSize size);

private:
    Ui::newCanvasDialog *ui;
};


#endif //MAIN_CPP_NEWCANVASDIALOG_H

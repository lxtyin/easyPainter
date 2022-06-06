//
// Created by lx_tyin on 2022/5/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_newCanvasDialog.h" resolved

#include "newcanvasdialog.h"
#include "ui_newCanvasDialog.h"
#include <QKeyEvent>

newCanvasDialog::newCanvasDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::newCanvasDialog){
    ui->setupUi(this);
    width = 400, height = 300;
    updateText();

    lockedRate = -1;

    connect(ui->lockButton, &QPushButton::clicked, [&](){
        if(lockedRate > 0) lockedRate = -1;
        else lockedRate = 1.0 * width / height;
        if(lockedRate > 0) ui->lockButton->setIcon(QIcon(":/images/img/lock.png"));
        else ui->lockButton->setIcon(QIcon(":/images/img/unlock.png"));
    });

    connect(ui->widthlineEdit, &QLineEdit::textEdited, [&](const QString &str){
        int x = str.toInt(), y = height;
        if(lockedRate > 0) y = x / lockedRate;
        if(x <= 0 || x > 5000 || y <= 0 || y > 5000){
            updateText(); //不更改 复原
            return;
        }
        width = x, height = y;
        updateText();
    });

    connect(ui->heightlineEdit, &QLineEdit::textEdited, [&](const QString &str){
        int x = width, y = str.toInt();
        if(lockedRate > 0) x = y * lockedRate;
        if(x <= 0 || x > 5000 || y <= 0 || y > 5000){
            updateText(); //不更改 复原
            return;
        }
        width = x, height = y;
        updateText();
    });

    connect(ui->okButton, &QPushButton::clicked, [&](){
        emit sizeConfirmed(QSize(width, height));
        accept();
    });
}

void newCanvasDialog::updateText() {
    ui->widthlineEdit->setText(QString::number(width));
    ui->heightlineEdit->setText(QString::number(height));
}

newCanvasDialog::~newCanvasDialog(){
    delete ui;
}

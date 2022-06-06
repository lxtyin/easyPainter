//
// Created by lx_tyin on 2022/5/15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_setting_pen.h" resolved

#include "setting.h"
#include "ui_setting_pen.h"
#include "ui_setting_eraser.h"
#include "ui_setting_bucket.h"
#include "ColorSettingWidget.h"

int setting_pen::sparse = 0;
int setting_pen::size = 1;
QColor setting_pen::color = Qt::black;
setting_pen::setting_pen(QWidget *parent) :
        QWidget(parent), ui(new Ui::setting_pen) {
    ui->setupUi(this);

    ui->sizeSlider->valuefunc = [](int x){
        if(x <= 50) return x;
        else return int(pow(1.0589, x)) + 33;
    }; //size增长函数

    connect(ui->sizeSlider, &QSlider::valueChanged, [&](int val){size = ui->sizeSlider->realVal();});
    connect(ui->sparseSlider, &QSlider::valueChanged, [&](int val){sparse = val;});
    connect(ui->colorWidget, &ColorSettingWidget::colorChanged, [&](const QColor &col){
        color = col;
    });
}
setting_pen::~setting_pen() { delete ui;}

int setting_eraser::soft = 255;
int setting_eraser::size = 1;
setting_eraser::setting_eraser(QWidget *parent) :
        QWidget(parent), ui(new Ui::setting_eraser) {
    ui->setupUi(this);

    ui->sizeSlider->valuefunc = [](int x){
        if(x <= 50) return x;
        else return int(pow(1.0589, x)) + 33;
    }; //size增长函数
    connect(ui->sizeSlider, &QSlider::valueChanged, [&](int val){size = ui->sizeSlider->realVal();});
    connect(ui->softSlider, &QSlider::valueChanged, [&](int val){soft = val;});
}

setting_eraser::~setting_eraser() { delete ui;}

int setting_bucket::toler = 0;
QColor setting_bucket::color = Qt::black;
setting_bucket::setting_bucket(QWidget *parent) :
        QWidget(parent), ui(new Ui::setting_bucket) {
    ui->setupUi(this);

    connect(ui->tolerSlider, &QSlider::valueChanged, [&](int val){toler = val;});
    connect(ui->colorWidget, &ColorSettingWidget::colorChanged, [&](const QColor &col){
        color = col;
    });
}

setting_bucket::~setting_bucket() { delete ui;}


//
// Created by lx_tyin on 2022/5/15.
//

#ifndef MAIN_CPP_SETTING_H
#define MAIN_CPP_SETTING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class setting_pen; }
namespace Ui { class setting_eraser; }
namespace Ui { class setting_bucket; }
QT_END_NAMESPACE

class setting_pen : public QWidget {
Q_OBJECT
public:
    static int size;
    static int sparse;
    static QColor color;

    explicit setting_pen(QWidget *parent = nullptr);
    ~setting_pen() override;
private:
    Ui::setting_pen *ui;
};


class setting_eraser : public QWidget {
Q_OBJECT

public:
    static int size;
    static int soft;
    explicit setting_eraser(QWidget *parent = nullptr);

    ~setting_eraser() override;

private:
    Ui::setting_eraser *ui;
};


class setting_bucket : public QWidget {
Q_OBJECT

public:
    static int toler;
    static QColor color;
    explicit setting_bucket(QWidget *parent = nullptr);

    ~setting_bucket() override;

private:
    Ui::setting_bucket *ui;
};

#endif //MAIN_CPP_SETTING_H

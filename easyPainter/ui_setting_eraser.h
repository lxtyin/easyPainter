/********************************************************************************
** Form generated from reading UI file 'setting_eraser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_ERASER_H
#define UI_SETTING_ERASER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MySlider.h"

QT_BEGIN_NAMESPACE

class Ui_setting_eraser
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    MySlider *sizeSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    MySlider *softSlider;
    QLabel *label_5;

    void setupUi(QWidget *setting_eraser)
    {
        if (setting_eraser->objectName().isEmpty())
            setting_eraser->setObjectName(QStringLiteral("setting_eraser"));
        setting_eraser->resize(219, 388);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(setting_eraser->sizePolicy().hasHeightForWidth());
        setting_eraser->setSizePolicy(sizePolicy);
        setting_eraser->setStyleSheet(QLatin1String("QWidget#setting_eraser\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(setting_eraser);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(setting_eraser);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 40));

        horizontalLayout->addWidget(label);

        sizeSlider = new MySlider(setting_eraser);
        sizeSlider->setObjectName(QStringLiteral("sizeSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sizeSlider->sizePolicy().hasHeightForWidth());
        sizeSlider->setSizePolicy(sizePolicy1);
        sizeSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal{\n"
"	height:6px; left:0px; right:0px; border:0px; border-		radius:6px; background:rgb(242,242,242);\n"
"} \n"
"QSlider::handle:horizontal{\n"
"	width:24px; background:#1644B0; border-radius:5px; 	margin:-3px 0px;\n"
"}\n"
"QSlider::sub-page:horizontal{\n"
"	background:#4C85FB; border:0px; border-radius:6px;\n"
"}\n"
""));
        sizeSlider->setMinimum(1);
        sizeSlider->setMaximum(120);
        sizeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sizeSlider);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(setting_eraser);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(30, 40));

        horizontalLayout_3->addWidget(label_4);

        softSlider = new MySlider(setting_eraser);
        softSlider->setObjectName(QStringLiteral("softSlider"));
        sizePolicy1.setHeightForWidth(softSlider->sizePolicy().hasHeightForWidth());
        softSlider->setSizePolicy(sizePolicy1);
        softSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal{\n"
"	height:6px; left:0px; right:0px; border:0px; border-		radius:6px; background:rgb(242,242,242);\n"
"} \n"
"QSlider::handle:horizontal{\n"
"	width:24px; background:#1644B0; border-radius:5px; 	margin:-3px 0px;\n"
"}\n"
"QSlider::sub-page:horizontal{\n"
"	background:#4C85FB; border:0px; border-radius:6px;\n"
"}\n"
""));
        softSlider->setMaximum(255);
        softSlider->setValue(255);
        softSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(softSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        label_5 = new QLabel(setting_eraser);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_5);


        retranslateUi(setting_eraser);

        QMetaObject::connectSlotsByName(setting_eraser);
    } // setupUi

    void retranslateUi(QWidget *setting_eraser)
    {
        setting_eraser->setWindowTitle(QApplication::translate("setting_eraser", "setting_eraser", Q_NULLPTR));
        label->setText(QApplication::translate("setting_eraser", "\345\244\247\345\260\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("setting_eraser", "\345\274\272\345\272\246", Q_NULLPTR));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class setting_eraser: public Ui_setting_eraser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_ERASER_H

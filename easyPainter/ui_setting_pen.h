/********************************************************************************
** Form generated from reading UI file 'setting_pen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_PEN_H
#define UI_SETTING_PEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ColorSettingWidget.h"
#include "MySlider.h"

QT_BEGIN_NAMESPACE

class Ui_setting_pen
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    MySlider *sizeSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    MySlider *sparseSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    ColorSettingWidget *colorWidget;
    QLabel *label_5;

    void setupUi(QWidget *setting_pen)
    {
        if (setting_pen->objectName().isEmpty())
            setting_pen->setObjectName(QStringLiteral("setting_pen"));
        setting_pen->resize(194, 380);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(setting_pen->sizePolicy().hasHeightForWidth());
        setting_pen->setSizePolicy(sizePolicy);
        setting_pen->setStyleSheet(QLatin1String("QWidget#setting_pen{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(setting_pen);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(setting_pen);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 40));

        horizontalLayout->addWidget(label);

        sizeSlider = new MySlider(setting_pen);
        sizeSlider->setObjectName(QStringLiteral("sizeSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(10);
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
        sizeSlider->setValue(1);
        sizeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sizeSlider);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(setting_pen);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(30, 40));

        horizontalLayout_3->addWidget(label_4);

        sparseSlider = new MySlider(setting_pen);
        sparseSlider->setObjectName(QStringLiteral("sparseSlider"));
        sizePolicy1.setHeightForWidth(sparseSlider->sizePolicy().hasHeightForWidth());
        sparseSlider->setSizePolicy(sizePolicy1);
        sparseSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal{\n"
"	height:6px; left:0px; right:0px; border:0px; border-		radius:6px; background:rgb(242,242,242);\n"
"} \n"
"QSlider::handle:horizontal{\n"
"	width:24px; background:#1644B0; border-radius:5px; 	margin:-3px 0px;\n"
"}\n"
"QSlider::sub-page:horizontal{\n"
"	background:#4C85FB; border:0px; border-radius:6px;\n"
"}\n"
""));
        sparseSlider->setMinimum(0);
        sparseSlider->setMaximum(7);
        sparseSlider->setPageStep(8);
        sparseSlider->setValue(0);
        sparseSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sparseSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(setting_pen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(30, 40));

        horizontalLayout_2->addWidget(label_2);

        colorWidget = new ColorSettingWidget(setting_pen);
        colorWidget->setObjectName(QStringLiteral("colorWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(colorWidget->sizePolicy().hasHeightForWidth());
        colorWidget->setSizePolicy(sizePolicy2);
        colorWidget->setMaximumSize(QSize(16777215, 30));
        colorWidget->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(colorWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        label_5 = new QLabel(setting_pen);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_5);


        retranslateUi(setting_pen);

        QMetaObject::connectSlotsByName(setting_pen);
    } // setupUi

    void retranslateUi(QWidget *setting_pen)
    {
        setting_pen->setWindowTitle(QApplication::translate("setting_pen", "setting_pen", Q_NULLPTR));
        label->setText(QApplication::translate("setting_pen", "\345\244\247\345\260\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("setting_pen", "\347\250\200\347\226\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("setting_pen", "\351\242\234\350\211\262", Q_NULLPTR));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class setting_pen: public Ui_setting_pen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_PEN_H

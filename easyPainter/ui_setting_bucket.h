/********************************************************************************
** Form generated from reading UI file 'setting_bucket.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_BUCKET_H
#define UI_SETTING_BUCKET_H

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

class Ui_setting_bucket
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    ColorSettingWidget *colorWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    MySlider *tolerSlider;
    QLabel *label_5;

    void setupUi(QWidget *setting_bucket)
    {
        if (setting_bucket->objectName().isEmpty())
            setting_bucket->setObjectName(QStringLiteral("setting_bucket"));
        setting_bucket->resize(221, 339);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(setting_bucket->sizePolicy().hasHeightForWidth());
        setting_bucket->setSizePolicy(sizePolicy);
        setting_bucket->setStyleSheet(QLatin1String("QWidget#setting_bucket\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(setting_bucket);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(setting_bucket);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(30, 40));

        horizontalLayout->addWidget(label_3);

        colorWidget = new ColorSettingWidget(setting_bucket);
        colorWidget->setObjectName(QStringLiteral("colorWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorWidget->sizePolicy().hasHeightForWidth());
        colorWidget->setSizePolicy(sizePolicy1);
        colorWidget->setMaximumSize(QSize(16777215, 30));
        colorWidget->setStyleSheet(QLatin1String("QWidget#colorWidget{\n"
"	border: 4px solid #e3e5ee;\n"
"}"));

        horizontalLayout->addWidget(colorWidget);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(setting_bucket);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(30, 40));

        horizontalLayout_3->addWidget(label_4);

        tolerSlider = new MySlider(setting_bucket);
        tolerSlider->setObjectName(QStringLiteral("tolerSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tolerSlider->sizePolicy().hasHeightForWidth());
        tolerSlider->setSizePolicy(sizePolicy2);
        tolerSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal{\n"
"	height:6px; left:0px; right:0px; border:0px; border-		radius:6px; background:rgb(242,242,242);\n"
"} \n"
"QSlider::handle:horizontal{\n"
"	width:24px; background:#1644B0; border-radius:5px; 	margin:-3px 0px;\n"
"}\n"
"QSlider::sub-page:horizontal{\n"
"	background:#4C85FB; border:0px; border-radius:6px;\n"
"}\n"
""));
        tolerSlider->setMaximum(200);
        tolerSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(tolerSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        label_5 = new QLabel(setting_bucket);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_5);


        retranslateUi(setting_bucket);

        QMetaObject::connectSlotsByName(setting_bucket);
    } // setupUi

    void retranslateUi(QWidget *setting_bucket)
    {
        setting_bucket->setWindowTitle(QApplication::translate("setting_bucket", "setting_bucket", Q_NULLPTR));
        label_3->setText(QApplication::translate("setting_bucket", "\351\242\234\350\211\262", Q_NULLPTR));
        label_4->setText(QApplication::translate("setting_bucket", "\345\256\271\345\267\256", Q_NULLPTR));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class setting_bucket: public Ui_setting_bucket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_BUCKET_H

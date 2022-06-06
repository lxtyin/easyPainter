/********************************************************************************
** Form generated from reading UI file 'newcanvasdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCANVASDIALOG_H
#define UI_NEWCANVASDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newCanvasDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLineEdit *widthlineEdit;
    QPushButton *lockButton;
    QLineEdit *heightlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okButton;

    void setupUi(QDialog *newCanvasDialog)
    {
        if (newCanvasDialog->objectName().isEmpty())
            newCanvasDialog->setObjectName(QStringLiteral("newCanvasDialog"));
        newCanvasDialog->resize(315, 242);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        newCanvasDialog->setFont(font);
        newCanvasDialog->setStyleSheet(QLatin1String("QDialog{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}"));
        verticalLayout = new QVBoxLayout(newCanvasDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(newCanvasDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(newCanvasDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 50));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(30, -1, 30, -1);
        widthlineEdit = new QLineEdit(newCanvasDialog);
        widthlineEdit->setObjectName(QStringLiteral("widthlineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widthlineEdit->sizePolicy().hasHeightForWidth());
        widthlineEdit->setSizePolicy(sizePolicy);
        widthlineEdit->setMinimumSize(QSize(0, 40));
        widthlineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 4px solid #b5c2ee\n"
"}\n"
""));
        widthlineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(widthlineEdit);

        lockButton = new QPushButton(newCanvasDialog);
        lockButton->setObjectName(QStringLiteral("lockButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lockButton->sizePolicy().hasHeightForWidth());
        lockButton->setSizePolicy(sizePolicy1);
        lockButton->setMinimumSize(QSize(30, 30));
        lockButton->setMaximumSize(QSize(30, 30));
        lockButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}\n"
"QPushButton:hover{\n"
"	border: 4px solid #b5c2ee\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/unlock.png"), QSize(), QIcon::Normal, QIcon::Off);
        lockButton->setIcon(icon);

        horizontalLayout->addWidget(lockButton);

        heightlineEdit = new QLineEdit(newCanvasDialog);
        heightlineEdit->setObjectName(QStringLiteral("heightlineEdit"));
        sizePolicy.setHeightForWidth(heightlineEdit->sizePolicy().hasHeightForWidth());
        heightlineEdit->setSizePolicy(sizePolicy);
        heightlineEdit->setMinimumSize(QSize(0, 40));
        heightlineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 4px solid #b5c2ee\n"
"}\n"
""));
        heightlineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(heightlineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(30, 30, 30, 30);
        okButton = new QPushButton(newCanvasDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy2);
        okButton->setMaximumSize(QSize(300, 40));
        okButton->setFont(font1);
        okButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}\n"
"QPushButton:hover{\n"
"	border: 4px solid #b5c2ee\n"
"}\n"
""));

        horizontalLayout_3->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_3);

        QWidget::setTabOrder(okButton, lockButton);
        QWidget::setTabOrder(lockButton, heightlineEdit);
        QWidget::setTabOrder(heightlineEdit, widthlineEdit);

        retranslateUi(newCanvasDialog);

        QMetaObject::connectSlotsByName(newCanvasDialog);
    } // setupUi

    void retranslateUi(QDialog *newCanvasDialog)
    {
        newCanvasDialog->setWindowTitle(QApplication::translate("newCanvasDialog", "\345\210\233\345\273\272\347\224\273\345\270\203", Q_NULLPTR));
        label_4->setText(QApplication::translate("newCanvasDialog", "\345\256\275(px)", Q_NULLPTR));
        label_5->setText(QApplication::translate("newCanvasDialog", "\351\253\230(px)", Q_NULLPTR));
        widthlineEdit->setText(QString());
        lockButton->setText(QString());
        okButton->setText(QApplication::translate("newCanvasDialog", "\347\241\256\350\256\244\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newCanvasDialog: public Ui_newCanvasDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCANVASDIALOG_H

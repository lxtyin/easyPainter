/********************************************************************************
** Form generated from reading UI file 'paintdoc.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTDOC_H
#define UI_PAINTDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "layerlist.h"

QT_BEGIN_NAMESPACE

class Ui_PaintDoc
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSlider *scaleSlider;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addLayerButton;
    QPushButton *delLayerButton;
    QPushButton *hideLayerButton;
    LayerList *layerList;

    void setupUi(QWidget *PaintDoc)
    {
        if (PaintDoc->objectName().isEmpty())
            PaintDoc->setObjectName(QStringLiteral("PaintDoc"));
        PaintDoc->resize(896, 564);
        PaintDoc->setMinimumSize(QSize(60, 0));
        horizontalLayout_2 = new QHBoxLayout(PaintDoc);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        scaleSlider = new QSlider(PaintDoc);
        scaleSlider->setObjectName(QStringLiteral("scaleSlider"));
        scaleSlider->setStyleSheet(QStringLiteral(""));
        scaleSlider->setMinimum(10);
        scaleSlider->setMaximum(1000);
        scaleSlider->setValue(100);

        horizontalLayout_2->addWidget(scaleSlider);

        scrollArea = new QScrollArea(PaintDoc);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(400, 300));
        scrollArea->setStyleSheet(QLatin1String("QScrollArea{\n"
"	border: 4px solid #e3e5ee;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 588, 534));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addLayerButton = new QPushButton(PaintDoc);
        addLayerButton->setObjectName(QStringLiteral("addLayerButton"));
        addLayerButton->setEnabled(true);
        addLayerButton->setMinimumSize(QSize(70, 0));
        addLayerButton->setMaximumSize(QSize(70, 16777215));
        addLayerButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}\n"
"QPushButton:hover{\n"
"	border: 4px solid #b5c2ee\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        addLayerButton->setIcon(icon);
        addLayerButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(addLayerButton);

        delLayerButton = new QPushButton(PaintDoc);
        delLayerButton->setObjectName(QStringLiteral("delLayerButton"));
        delLayerButton->setEnabled(true);
        delLayerButton->setMinimumSize(QSize(70, 0));
        delLayerButton->setMaximumSize(QSize(70, 16777215));
        delLayerButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}\n"
"QPushButton:hover{\n"
"	border: 4px solid #b5c2ee\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/img/del.png"), QSize(), QIcon::Normal, QIcon::Off);
        delLayerButton->setIcon(icon1);
        delLayerButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(delLayerButton);

        hideLayerButton = new QPushButton(PaintDoc);
        hideLayerButton->setObjectName(QStringLiteral("hideLayerButton"));
        hideLayerButton->setEnabled(true);
        hideLayerButton->setMinimumSize(QSize(70, 0));
        hideLayerButton->setMaximumSize(QSize(70, 16777215));
        hideLayerButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 4px solid #e3e5ee;\n"
"}\n"
"QPushButton:hover{\n"
"	border: 4px solid #b5c2ee\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/img/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        hideLayerButton->setIcon(icon2);
        hideLayerButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(hideLayerButton);


        verticalLayout->addLayout(horizontalLayout);

        layerList = new LayerList(PaintDoc);
        layerList->setObjectName(QStringLiteral("layerList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layerList->sizePolicy().hasHeightForWidth());
        layerList->setSizePolicy(sizePolicy);
        layerList->setMinimumSize(QSize(240, 300));
        layerList->setMaximumSize(QSize(240, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(14);
        layerList->setFont(font);
        layerList->setStyleSheet(QLatin1String("\n"
"border: 4px solid #e3e5ee;"));
        layerList->setEditTriggers(QAbstractItemView::DoubleClicked);
        layerList->setProperty("showDropIndicator", QVariant(true));
        layerList->setDragEnabled(true);
        layerList->setDragDropMode(QAbstractItemView::DragOnly);
        layerList->setDefaultDropAction(Qt::MoveAction);
        layerList->setMovement(QListView::Free);
        layerList->setProperty("isWrapping", QVariant(false));
        layerList->setResizeMode(QListView::Fixed);
        layerList->setLayoutMode(QListView::Batched);
        layerList->setSpacing(5);
        layerList->setViewMode(QListView::ListMode);
        layerList->setModelColumn(0);
        layerList->setUniformItemSizes(false);
        layerList->setBatchSize(200);
        layerList->setWordWrap(false);
        layerList->setSelectionRectVisible(true);
        layerList->setSortingEnabled(false);

        verticalLayout->addWidget(layerList);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(PaintDoc);

        QMetaObject::connectSlotsByName(PaintDoc);
    } // setupUi

    void retranslateUi(QWidget *PaintDoc)
    {
        PaintDoc->setWindowTitle(QApplication::translate("PaintDoc", "PaintWidget", Q_NULLPTR));
        addLayerButton->setText(QString());
        delLayerButton->setText(QString());
        hideLayerButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PaintDoc: public Ui_PaintDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTDOC_H

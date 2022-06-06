/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Tool;
    QAction *action_Revoke;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_T;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *ToolBox;
    QWidget *toolBoxContent;
    QVBoxLayout *verticalLayout;
    QListWidget *ToolList;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1089, 680);
        MainWindow->setMinimumSize(QSize(0, 0));
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/new_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/img/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/img/save_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon2);
        action_Tool = new QAction(MainWindow);
        action_Tool->setObjectName(QStringLiteral("action_Tool"));
        action_Tool->setCheckable(true);
        action_Tool->setChecked(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/img/tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Tool->setIcon(icon3);
        action_Revoke = new QAction(MainWindow);
        action_Revoke->setObjectName(QStringLiteral("action_Revoke"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/img/revoke.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Revoke->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(false);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);

        horizontalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1089, 26));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_T = new QMenu(menuBar);
        menu_T->setObjectName(QStringLiteral("menu_T"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        ToolBox = new QDockWidget(MainWindow);
        ToolBox->setObjectName(QStringLiteral("ToolBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ToolBox->sizePolicy().hasHeightForWidth());
        ToolBox->setSizePolicy(sizePolicy);
        ToolBox->setMinimumSize(QSize(210, 500));
        ToolBox->setMaximumSize(QSize(210, 524287));
        ToolBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ToolBox->setFeatures(QDockWidget::AllDockWidgetFeatures);
        ToolBox->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        toolBoxContent = new QWidget();
        toolBoxContent->setObjectName(QStringLiteral("toolBoxContent"));
        verticalLayout = new QVBoxLayout(toolBoxContent);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        ToolList = new QListWidget(toolBoxContent);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/img/pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush(QColor(144, 255, 239, 255));
        brush.setStyle(Qt::BDiagPattern);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(ToolList);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush);
        __qlistwidgetitem->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/img/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush1(QColor(245, 185, 255, 255));
        brush1.setStyle(Qt::BDiagPattern);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(ToolList);
        __qlistwidgetitem1->setFont(font);
        __qlistwidgetitem1->setBackground(brush1);
        __qlistwidgetitem1->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/img/bucket.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush2(QColor(255, 224, 112, 255));
        brush2.setStyle(Qt::BDiagPattern);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(ToolList);
        __qlistwidgetitem2->setFont(font);
        __qlistwidgetitem2->setBackground(brush2);
        __qlistwidgetitem2->setIcon(icon7);
        ToolList->setObjectName(QStringLiteral("ToolList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ToolList->sizePolicy().hasHeightForWidth());
        ToolList->setSizePolicy(sizePolicy1);
        ToolList->setMinimumSize(QSize(180, 150));
        ToolList->setMaximumSize(QSize(16777215, 150));
        ToolList->setStyleSheet(QLatin1String("\n"
"border: 4px solid #e3e5ee;"));
        ToolList->setSpacing(5);

        verticalLayout->addWidget(ToolList);

        label = new QLabel(toolBoxContent);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QLatin1String("font: 12pt \"Consolas\";\n"
"color: rgb(169, 179, 222);\n"
""));

        verticalLayout->addWidget(label);

        ToolBox->setWidget(toolBoxContent);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), ToolBox);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_T->menuAction());
        menu_F->addAction(action_New);
        menu_F->addAction(action_Open);
        menu_F->addAction(action_Save);
        menu_E->addAction(action_Revoke);
        menu_T->addAction(action_Tool);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_Revoke);
        mainToolBar->addAction(action_Tool);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "easyPainter", Q_NULLPTR));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_New->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Tool->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", Q_NULLPTR));
        action_Revoke->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&Z)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Revoke->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", Q_NULLPTR));
        menu_T->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", Q_NULLPTR));
        ToolBox->setWindowTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", Q_NULLPTR));

        const bool __sortingEnabled = ToolList->isSortingEnabled();
        ToolList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = ToolList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "\351\223\205\347\254\224", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = ToolList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "\346\251\241\347\232\256", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = ToolList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "\351\242\234\346\226\231\346\241\266", Q_NULLPTR));
        ToolList->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("MainWindow", "Setting  \342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

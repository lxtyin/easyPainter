#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

const int TOOL_PEN = 0;
const int TOOL_ERASER = 1;
const int TOOL_BUCKET = 2;

class MainWindow : public QMainWindow {
    Q_OBJECT
    Ui::MainWindow *ui;
    QWidget *settingWidget[3], *curWidget; //三种工具的设置面板，当前面板指针
    QLabel *statusLabel; //下方状态栏内容
public:

    static MainWindow *ins;   //单例模式
    static int currentTool(); //返回当前所用工具编号

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showSetting(int p);  //设置面板切换为工具p的

public slots:
    //各种菜单栏中的action触发槽函数
    void on_action_New_triggered();  //新建画布
    void on_action_Open_triggered(); //打开图片
    void on_action_Save_triggered(); //保存图片
    void on_action_Tool_triggered(bool); //开/关工具箱
    void on_action_Revoke_triggered(); //撤销按钮

};

#endif // MAINWINDOW_H

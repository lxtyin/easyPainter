#-------------------------------------------------
#
# Project created by QtCreator 2022-05-27T20:51:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = easyPainter
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    ColorPicker/ColorPicker.cpp\
    main.cpp\
    canvas.cpp\
    ColorSettingWidget.cpp\
    history.cpp\
    layer.cpp\
    layerlist.cpp\
    mainwindow.cpp\
    MySlider.cpp\
    newcanvasdialog.cpp\
    paintdoc.cpp\
    setting.cpp

HEADERS += \
    canvas.h\
    ColorPicker/ColorPicker.h\
    ColorSettingWidget.h\
    history.h\
    layer.h\
    layerlist.h\
    mainwindow.h\
    MySlider.h\
    newcanvasdialog.h\
    paintdoc.h\
    setting.h

FORMS += \
    setting_bucket.ui\
    setting_eraser.ui\
    paintdoc.ui\
    mainwindow.ui\
    newcanvasdialog.ui\
    setting_pen.ui\
    mainwindow.ui

RESOURCES += \
    resource.qrc

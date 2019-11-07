#-------------------------------------------------
#
# Project created by QtCreator 2019-10-09T09:27:23
#
#-------------------------------------------------

QT       += core gui sql quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AgvCtrlSys
TEMPLATE = app
RC_ICONS = ./res/icon/logo.ico
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    MapForm.cpp \
    TaskForm.cpp \
    TitleBarEx.cpp \
    DeviceStateForm.cpp \
    UserForm.cpp \
    HistoryForm.cpp \
    AbnormalForm.cpp \
    ConfigForm.cpp \
    PushButtonEx.cpp \
    LineEditEx.cpp \
    ComboBoxEx.cpp \
    TableViewEx.cpp \
    CustomTableModel.cpp \
    CustomJsonModel.cpp \
    LoginForm.cpp \
    MsgBoxEx.cpp \
    LoginSetForm.cpp \
    Config.cpp \
    LabelEx.cpp \
    GroupBoxEx.cpp \
    xml/tinystr.cpp \
    xml/tinyxml.cpp \
    xml/TinyxmlEngine.cpp \
    xml/tinyxmlerror.cpp \
    xml/tinyxmlparser.cpp \
    graphic/Graphic.cpp \
    graphic/GraphicBg.cpp \
    graphic/GraphicCharger.cpp \
    graphic/GraphicMap.cpp \
    graphic/GraphicMark.cpp \
    graphic/GraphicRest.cpp \
    graphic/GraphicStation.cpp \
    graphic/GraphicTrack.cpp \
    graphic/GraphicAgv.cpp \
    ModulesForm.cpp

HEADERS += \
        MainWindow.h \
    MapForm.h \
    TaskForm.h \
    TitleBarEx.h \
    CustomTabStyle.h \
    DeviceStateForm.h \
    UserForm.h \
    HistoryForm.h \
    AbnormalForm.h \
    ConfigForm.h \
    PushButtonEx.h \
    LineEditEx.h \
    ComboBoxEx.h \
    TableViewEx.h \
    CustomTableModel.h \
    CustomJsonModel.h \
    LoginForm.h \
    MsgBoxEx.h \
    LoginSetForm.h \
    Config.h \
    LabelEx.h \
    GroupBoxEx.h \
    CustomData.h \
    xml/tinystr.h \
    xml/tinyxml.h \
    xml/TinyxmlEngine.h \
    graphic/Graphic.h \
    graphic/GraphicBg.h \
    graphic/GraphicCharger.h \
    graphic/GraphicMap.h \
    graphic/GraphicMark.h \
    graphic/GraphicRest.h \
    graphic/GraphicsAgv.h \
    graphic/GraphicStation.h \
    graphic/GraphicTrack.h \
    graphic/GraphicAgv.h \
    ModulesForm.h

FORMS += \
        MainWindow.ui \
    MapForm.ui \
    TaskForm.ui \
    DeviceStateForm.ui \
    UserForm.ui \
    HistoryForm.ui \
    AbnormalForm.ui \
    ConfigForm.ui \
    LoginForm.ui \
    LoginSetForm.ui \
    ModulesForm.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

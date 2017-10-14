QT += \
    core \
    gui

greaterThan(QT_MAJOR_VERSION, 4):
QT += \
    widgets

TARGET = comment-remover
TEMPLATE = app
CONFIG += \
    c++11

SOURCES += \
    main.cpp\
    MainWindow.cpp \
    CommentRemover.cpp

HEADERS  += \
    MainWindow.h \
    CommentRemover.h

FORMS += \
    MainWindow.ui

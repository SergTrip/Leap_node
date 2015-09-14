QT       += core gui

HEADERS += \
    include/qnode.hpp \
    include/simplelistener.h \
    include/LeapTestDialog.h

SOURCES += \
    src/qnode.cpp \
    src/simplelistener.cpp \
    src/LeapTestDialog.cpp \
    src/main.cpp

FORMS += \
    ui/dialog.ui

INCLUDEPATH += /home/sergey/libs/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/include
LIBS        += -L/home/sergey/libs/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/lib/x64 -lLeap

DISTFILES += \
    package.xml \
    CMakeLists.txt

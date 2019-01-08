#-------------------------------------------------
#
# Project created by QtCreator 2019-01-08T19:17:04
#
#-----注意：应该编译为共享库，因为pcl的所有库都是个共享库-----------------------------
include (../OREZ.pri)
QT       -= gui

TARGET = OREZ_IO
TEMPLATE = lib

DEFINES += OREZ_IO_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        orezio.cpp

HEADERS += \
        orezio.h \
        orez_io_global.h \ 
    ../common.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

#-------------------------------------------------
#
# Project created by QtCreator 2019-01-05T08:58:09
#
#-------------------------------------------------
include (../OREZ.pri)
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OREZ
TEMPLATE = app

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
        main.cpp \
        orez.cpp \
    normalestdialog.cpp \
    boundarydialog.cpp \
    filtervoxeldialog.cpp \
    poissonreconstructiondialog.cpp \
    mlsnormaldialog.cpp

HEADERS += \
        orez.h \
    normalestdialog.h \
    boundarydialog.h \
    filtervoxeldialog.h \
    poissonreconstructiondialog.h \
    mlsnormaldialog.h

FORMS += \
        orez.ui \
    normalestdialog.ui \
    boundarydialog.ui \
    filtervoxeldialog.ui \
    poissonreconstructiondialog.ui \
    mlsnormaldialog.ui

DISTFILES += \
    ../OREZ.pri

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../OREZ_IO/release/ -lOREZ_IO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../OREZ_IO/debug/ -lOREZ_IO
else:unix: LIBS += -L$$OUT_PWD/../OREZ_IO/ -lOREZ_IO

INCLUDEPATH += $$PWD/../OREZ_IO
DEPENDPATH += $$PWD/../OREZ_IO

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Common/release/ -lCommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Common/debug/ -lCommon
else:unix: LIBS += -L$$OUT_PWD/../Common/ -lCommon

INCLUDEPATH += $$PWD/../Common
DEPENDPATH += $$PWD/../Common


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../OREZ_Reconstruct/release/ -lOREZ_Reconstruct
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../OREZ_Reconstruct/debug/ -lOREZ_Reconstruct
else:unix: LIBS += -L$$OUT_PWD/../OREZ_Reconstruct/ -lOREZ_Reconstruct

INCLUDEPATH += $$PWD/../OREZ_Reconstruct
DEPENDPATH += $$PWD/../OREZ_Reconstruct

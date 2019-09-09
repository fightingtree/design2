#-------------------------------------------------
#
# Project created by QtCreator 2019-09-01T05:23:56
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jiami_server
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    caesar_jia.cpp \
    affine_jia.cpp \
    vigenere_jia.cpp \
    playfair_jia.cpp \
    permutation_jia.cpp \
    column_jia.cpp \
    rc4_jia.cpp \
    des_jia.cpp \
    rsa_jia.cpp \
    dh_jia.cpp \
    content.cpp

HEADERS += \
        mainwindow.h \
    caesar_jia.h \
    affine_jia.h \
    vigenere_jia.h \
    playfair_jia.h \
    permutation_jia.h \
    column_jia.h \
    rc4_jia.h \
    des_jia.h \
    rsa_jia.h \
    dh_jia.h \
    content.h

FORMS += \
        mainwindow.ui \
    caesar_jia.ui \
    affine_jia.ui \
    vigenere_jia.ui \
    playfair_jia.ui \
    permutation_jia.ui \
    column_jia.ui \
    rc4_jia.ui \
    des_jia.ui \
    rsa_jia.ui \
    dh_jia.ui \
    content.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

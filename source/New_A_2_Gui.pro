#-------------------------------------------------
#
# Project created by QtCreator 2017-08-17T11:50:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = New_A_2_Gui
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
        main.cpp \
        account_management.cpp \
        UsrInfo.cpp \
        Account.cpp \
        login.cpp \
        book_search.cpp \
        Book.cpp \
        edit_book.cpp \
        user_page.cpp \
        Request.cpp

HEADERS += \
        account_management.h \
        Account.h \
        UsrInfo.h \
        login.h \
        book_search.h \
        Book.h \
        edit_book.h \
        user_page.h \
        Request.h

FORMS += \
        account_management.ui \
        login.ui \
        book_search.ui \
        edit_book.ui \
        user_page.ui

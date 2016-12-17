#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T16:30:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BAG
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    model_contenitore.cpp \
    model_bagaglio.cpp \
    model_proprietario.cpp \
    model_viaggio.cpp \
    model_bagaglio_a_mano.cpp \
    model_bagaglio_in_stiva.cpp \
    model_bagaglio_vivente.cpp \
    model_bagaglio_animale_pericoloso.cpp \
    model_bagaglio_animale.cpp \
    model_bagaglio_animale_mansueto.cpp \
    model_bagaglio_pianta.cpp \
    model_bagaglio_non_vivente.cpp \
    model_bagaglio_non_vivente_normale.cpp \
    model_bagaglio_non_vivente_speciale.cpp \
    controller_lista_bagagli.cpp \
    view_lista_bagagli.cpp \
    view_add_bagagli.cpp \
    qwidget_add_lug.cpp \
    qwidget_add_owner.cpp \
    qwidget_add_travel.cpp \
    qdialog_info.cpp \
    qdialog_search.cpp \
    data.cpp

HEADERS  += mainwindow.h \
    model_contenitore.h \
    model_bagaglio.h \
    model_proprietario.h \
    model_viaggio.h \
    model_bagaglio_a_mano.h \
    model_bagaglio_in_stiva.h \
    model_bagaglio_vivente.h \
    model_bagaglio_animale_pericoloso.h \
    model_bagaglio_animale.h \
    model_bagaglio_animale_mansueto.h \
    model_bagaglio_pianta.h \
    model_bagaglio_non_vivente.h \
    model_bagaglio_non_vivente_normale.h \
    model_bagaglio_non_vivente_speciale.h \
    controller_lista_bagagli.h \
    view_lista_bagagli.h \
    view_add_bagagli.h \
    qwidget_add_lug.h \
    qwidget_add_owner.h \
    qwidget_add_travel.h \
    qdialog_info.h \
    qdialog_search.h \
    data.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

OTHER_FILES +=

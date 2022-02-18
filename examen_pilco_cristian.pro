QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
        agregar_tarea.cpp \
        fecha.cpp \
        main.cpp \
        tarea.cpp \
        tareas_ventana.cpp

HEADERS += \
    agregar_tarea.h \
    fecha.h \
    tarea.h \
    tareas_ventana.h

FORMS += \
    agregar_tarea.ui \
    tareas_ventana.ui

RESOURCES += \
    res.qrc \
    traducciones.qrc

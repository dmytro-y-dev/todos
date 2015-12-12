TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    ScreenResolutionManager.cpp \
    Engine.cpp \
    Task.cpp \
    lib/qobjectlistmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ScreenResolutionManager.h \
    Engine.h \
    Task.h \
    lib/qobjectlistmodel.h \
    lib/qquicklist.h

CONFIG += c++11

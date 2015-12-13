CONFIG += C++14

QT += core
QT -= gui

TARGET = test-todos
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../ \
    ../../contrib/sqlite/source/ \
    ../../contrib/googletest/ \
    ../../contrib/googletest/include

SOURCES += main.cpp \
    ../../contrib/sqlite/source/sqlite3.c \
    ../../contrib/googletest/src/gtest-all.cc \
    ../../model/entity/Category.cpp \
    ../../model/entity/Task.cpp \
    ../../model/entity/User.cpp \
    ../../model/schema/Schema.cpp \
    ../../test/unit/TestModelSchemaSchema.cpp \
    ../../test/unit/TestModelEntityCategory.cpp \
    ../../test/unit/TestModelEntityTask.cpp \
    ../../test/unit/TestModelEntityUser.cpp \
    ../../model/entity/Commentary.cpp \
    ../../test/unit/TestModelEntityCommentary.cpp

HEADERS += \
    ../../model/entity/Category.h \
    ../../model/entity/Task.h \
    ../../model/entity/User.h \
    ../../model/schema/Schema.h \
    ../../model/entity/Commentary.h


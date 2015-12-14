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
    ../../model/entity/category/Category.cpp \
    ../../model/entity/task/Task.cpp \
    ../../model/entity/user/User.cpp \
    ../../model/schema/Schema.cpp \
    ../../test/unit/TestModelSchemaSchema.cpp \
    ../../test/unit/TestModelEntityCategory.cpp \
    ../../test/unit/TestModelEntityTask.cpp \
    ../../test/unit/TestModelEntityUser.cpp \
    ../../model/entity/commentary/Commentary.cpp \
    ../../test/unit/TestModelEntityCommentary.cpp \
    ../../model/repository/category/CategoryRepository.cpp \
    ../../model/repository/commentary/CommentaryRepository.cpp \
    ../../model/repository/task/TaskRepository.cpp \
    ../../model/repository/user/UserRepository.cpp

HEADERS += \
    ../../model/entity/category/Category.h \
    ../../model/entity/task/Task.h \
    ../../model/entity/user/User.h \
    ../../model/schema/Schema.h \
    ../../model/entity/commentary/Commentary.h \
    ../../model/repository/category/CategoryRepository.h \
    ../../model/repository/commentary/CommentaryRepository.h \
    ../../model/repository/task/TaskRepository.h \
    ../../model/repository/user/UserRepository.h


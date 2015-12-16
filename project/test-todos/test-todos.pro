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
    ../../model/repository/user/UserRepository.cpp \
    ../../model/repository/BaseRepository.cpp \
    ../../test/unit/TestModelRepositoryUserRepository.cpp \
    ../../model/traits/user/UserTraits.cpp \
    ../../model/traits/IEntityTraits.cpp \
    ../../model/entity/IEntity.cpp \
    ../../model/factory/user/UserFactory.cpp \
    ../../model/traits/category/CategoryTraits.cpp \
    ../../model/traits/commentary/CommentaryTraits.cpp \
    ../../model/traits/task/TaskTraits.cpp \
    ../../model/factory/category/CategoryFactory.cpp \
    ../../model/factory/commentary/CommentaryFactory.cpp \
    ../../model/factory/task/TaskFactory.cpp \
    ../../test/unit/TestModelRepositoryCategoryRepository.cpp \
    ../../test/unit/TestModelRepositoryCommentaryRepository.cpp \
    ../../test/unit/TestModelRepositoryTaskRepository.cpp \
    ../../model/repository/task/TaskFilterSettings.cpp \
    ../../utility/StringConversions.cpp

HEADERS += \
    ../../model/entity/category/Category.h \
    ../../model/entity/task/Task.h \
    ../../model/entity/user/User.h \
    ../../model/schema/Schema.h \
    ../../model/entity/commentary/Commentary.h \
    ../../model/repository/category/CategoryRepository.h \
    ../../model/repository/commentary/CommentaryRepository.h \
    ../../model/repository/task/TaskRepository.h \
    ../../model/repository/user/UserRepository.h \
    ../../model/repository/BaseRepository.h \
    ../../model/repository/IRepository.h \
    ../../model/repository/IRepositoryImpl.h \
    ../../model/factory/user/UserFactory.h \
    ../../model/traits/user/UserTraits.h \
    ../../model/traits/IEntityTraits.h \
    ../../model/entity/IEntity.h \
    ../../model/traits/category/CategoryTraits.h \
    ../../model/traits/commentary/CommentaryTraits.h \
    ../../model/traits/task/TaskTraits.h \
    ../../model/factory/category/CategoryFactory.h \
    ../../model/factory/commentary/CommentaryFactory.h \
    ../../model/factory/task/TaskFactory.h \
    ../../model/repository/task/TaskFilterSettings.h \
    ../../utility/StringConversions.h


QT -= gui

TARGET = CuteLogger

TEMPLATE = lib

CONFIG += staticlib

Release:DESTDIR = $$_PRO_FILE_PWD_/../release

Debug:DESTDIR = $$_PRO_FILE_PWD_/../debug

SOURCES += AbstractAppender.cpp        \
           AbstractStringAppender.cpp  \
           ConsoleAppender.cpp         \
           FileAppender.cpp            \
           Logger.cpp

HEADERS += AbstractAppender.h        \
           AbstractStringAppender.h  \
           ConsoleAppender.h         \
           FileAppender.h            \
           Logger.h

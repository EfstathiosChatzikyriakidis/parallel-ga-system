QT += network

TARGET = PGAClient

TEMPLATE = app

VERSION = 0.0.2

Release:DESTDIR = $$_PRO_FILE_PWD_/../release

Debug:DESTDIR = $$_PRO_FILE_PWD_/../debug

SOURCES += main.cpp MainWindow.cpp

HEADERS += MainWindow.h

FORMS += MainWindow.ui

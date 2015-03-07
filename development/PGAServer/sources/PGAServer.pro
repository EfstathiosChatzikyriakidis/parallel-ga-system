QT += network

TARGET = PGAServer

VERSION = 0.0.2

TEMPLATE = app

Release:DESTDIR = $$_PRO_FILE_PWD_/../release

Debug:DESTDIR = $$_PRO_FILE_PWD_/../debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../SharedSources/CuteLogger/release/ -lCuteLogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../SharedSources/CuteLogger/debug/ -lCuteLogger
else:unix:!symbian: LIBS += -L$$PWD/../../SharedSources/CuteLogger/release/ -lCuteLogger

INCLUDEPATH += $$PWD/../../SharedSources/CuteLogger/sources
DEPENDPATH += $$PWD/../../SharedSources/CuteLogger/sources

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../SharedSources/CuteLogger/release/CuteLogger.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../SharedSources/CuteLogger/debug/CuteLogger.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/../../SharedSources/CuteLogger/release/libCuteLogger.a

SOURCES += main.cpp                  \
           MainWindow.cpp            \
           ServerManager.cpp         \
           Server.cpp                \
           IServerRequest.cpp        \
           IServerAction.cpp         \
           ServerBestRequest.cpp     \
           ServerBestAction.cpp      \
           ServerRequestFactory.cpp  \
           ServerActionFactory.cpp   \
           IServerState.cpp          \
           ServerStartState.cpp      \
           ServerStopState.cpp       \
           Configuration.cpp         \
           ServerLogger.cpp

HEADERS += MainWindow.h            \
           ServerManager.h         \
           Server.h                \
           IServerRequest.h        \
           IServerAction.h         \
           ServerBestRequest.h     \
           ServerBestAction.h      \
           ServerRequestFactory.h  \
           ServerActionFactory.h   \
           IServerState.h          \
           ServerStartState.h      \
           ServerStopState.h       \
           Configuration.h         \
           ServerLogger.h

FORMS += MainWindow.ui

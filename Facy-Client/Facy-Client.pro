QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    frmcontrol.cpp \
    frmgame.cpp \
    frmlogin.cpp \
    frmmain.cpp \
    frmscoreboard.cpp \
    main.cpp

HEADERS += \
    frmcontrol.h \
    frmgame.h \
    frmlogin.h \
    frmmain.h \
    frmscoreboard.h

FORMS += \
    frmcontrol.ui \
    frmgame.ui \
    frmlogin.ui \
    frmmain.ui \
    frmscoreboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
    images/

DISTFILES += \
    images/phAvatar.png \
    images/phLogo.png

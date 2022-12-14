QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fileexplorer.cpp \
    frmaccount.cpp \
    frmhelp.cpp \
    frmmain.cpp \
    frmoptions.cpp \
    logiccontroller.cpp \
    main.cpp

HEADERS += \
    fileexplorer.h \
    frmaccount.h \
    frmhelp.h \
    frmmain.h \
    frmoptions.h \
    logiccontroller.h

FORMS += \
    fileexplorer.ui \
    frmaccount.ui \
    frmhelp.ui \
    frmmain.ui \
    frmoptions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
    images/

DISTFILES += \
    images/phAvatar.png \
    images/phLogo.png \
    options.ini

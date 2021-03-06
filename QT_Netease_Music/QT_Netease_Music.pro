QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AnimationWidget.cpp \
    BottomWidget.cpp \
    ClickLabel.cpp \
    ListWidgetFindMusic.cpp \
    ListWidgetLocalMusic.cpp \
    MiddleWidgetLeftList.cpp \
    MiddleWidgetRightStack.cpp \
    PlaySongInfoWidget.cpp \
    SkinWidget.cpp \
    SongListFrame.cpp \
    TitleBar.cpp \
    TurntableWidget.cpp \
    gallery_item.cpp \
    main.cpp \
    mainwindow.cpp \
    widget_tab1.cpp \
    widget_tab2.cpp

HEADERS += \
    AnimationWidget.h \
    BottomWidget.h \
    ClickLabel.h \
    ListWidgetFindMusic.h \
    ListWidgetLocalMusic.h \
    MiddleWidgetLeftList.h \
    MiddleWidgetRightStack.h \
    PlaySongInfoWidget.h \
    SkinWidget.h \
    SongListFrame.h \
    TitleBar.h \
    TurntableWidget.h \
    gallery_item.h \
    mainwindow.h \
    widget_tab1.h \
    widget_tab2.h

FORMS += \
    gallery_item.ui \
    mainwindow.ui \
    widget_tab1.ui \
    widget_tab2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Resources/Logo.png

RESOURCES += \
    res.qrc \
    res.qrc

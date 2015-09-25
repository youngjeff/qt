TEMPLATE = subdirs

SUBDIRS += \
    UiPushButton

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/UiPushButton/release/ -lUiPushButton
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/UiPushButton/debug/ -lUiPushButton
else:unix: LIBS += -L$$OUT_PWD/UiPushButton/ -lUiPushButton

INCLUDEPATH += $$PWD/UiPushButton
DEPENDPATH += $$PWD/UiPushButton

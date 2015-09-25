TEMPLATE = subdirs

SUBDIRS += \
    Hellow

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/UIComponents/UiPushButton/release/ -lUiPushButton
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/UIComponents/UiPushButton/debug/ -lUiPushButton
else:unix: LIBS += -L$$OUT_PWD/../lib/UIComponents/UiPushButton/ -lUiPushButton

INCLUDEPATH += $$PWD/../lib/UIComponents/UiPushButton
DEPENDPATH += $$PWD/../lib/UIComponents/UiPushButton

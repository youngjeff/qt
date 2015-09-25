TEMPLATE = subdirs

SUBDIRS += \
    UITester

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/UIComponents/JeffPushButton/release/ -lJeffPushButton
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/UIComponents/JeffPushButton/debug/ -lJeffPushButton
else:unix: LIBS += -L$$OUT_PWD/../lib/UIComponents/JeffPushButton/ -lJeffPushButton

INCLUDEPATH += $$PWD/../lib/UIComponents/JeffPushButton
DEPENDPATH += $$PWD/../lib/UIComponents/JeffPushButton

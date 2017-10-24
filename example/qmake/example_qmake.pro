TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

target = example_qmake

SOURCES += \
    unittest.cpp


LIBS += \
    -lcontest_main \
    -lgmock \
    -lpthread

#mytarget.target = .buildfile
mytarget.commands = $$OUT_PWD/$$target

QMAKE_EXTRA_TARGETS += mytarget


POST_TARGETDEPS += mytarget
#QMAKE_POST_LINK

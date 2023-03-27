QT          += widgets

HEADERS     = \
              history.h \
              interval.h \
              load.h \
              mylabel.h \
              save.h \
              saver.h \
              widget.h \
              window.h
SOURCES     = \
              history.cpp \
              interval.cpp \
              load.cpp \
              main.cpp \
              mylabel.cpp \
              save.cpp \
              saver.cpp \
              widget.cpp \
              window.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
INSTALLS += target

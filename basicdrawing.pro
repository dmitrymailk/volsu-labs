QT += widgets
requires(qtConfig(combobox))

HEADERS       = renderarea.h \
                colorlisteditor.h \
                window.h
SOURCES       = main.cpp \
                colorlisteditor.cpp \
                renderarea.cpp \
                window.cpp
RESOURCES     = basicdrawing.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
INSTALLS += target

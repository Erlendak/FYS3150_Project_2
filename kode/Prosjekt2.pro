TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += C:\armadillo\include
DEPENDPATH += C:\armadillo\include


LIBS += \
    -LC:\armadillo\examples\lib_win64 \
    -llapack_win64_MT \
    -lblas_win64_MT

HEADERS += \
    jacobi_rotation.h \
    test_jacobi_rotation.h\
    quantum_dots.h

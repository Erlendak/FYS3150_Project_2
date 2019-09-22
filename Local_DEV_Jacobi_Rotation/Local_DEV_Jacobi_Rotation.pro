TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += A:\Skole\Programmer\C++\armadillo-9.700.2\include
DEPENDPATH += A:\Skole\Programmer\C++\armadillo-9.700.2\include

LIBS += \
    -LA:\Skole\Programmer\C++\armadillo-9.700.2\examples\lib_win64 \
    -llapack_win64_MT \
    -lblas_win64_MT

HEADERS += \
    jacobi_rotation.h \
    test_jacobi_rotation.h

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += A:\Skole\Programmer\C++\armadillo\include
DEPENDPATH += A:\Skole\Programmer\C++\armadillo\include

LIBS += \
    -LA:\Skole\Programmer\C++\armadillo\examples\lib_win64\
    -llapack_win64_MT \
    -lblas_win64_MT

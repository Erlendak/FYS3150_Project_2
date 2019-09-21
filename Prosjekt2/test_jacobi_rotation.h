#ifndef TEST_JACOBI_ROTATION_H
#define TEST_JACOBI_ROTATION_H

#endif // TEST_JACOBI_ROTATION_H

#include "jacobi_rotation.h"

void test_solution(){
    mat A(3,3);
    A(0,0) = 1;
    A(0,1) = 0;
    A(0,2) = -2;
    A(1,0) = 0;
    A(1,1) = 2;
    A(1,2) = 7;
    A(2,0) = -2;
    A(2,1) = 7;
    A(2,2) = 5;
    cout << A << endl;

};


void test_maxoffdiag(){
    mat A(5,5);
    for(int i = 0, i<5, i++){

    }
};

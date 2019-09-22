#ifndef TEST_JACOBI_ROTATION_H
#define TEST_JACOBI_ROTATION_H


#include "jacobi_rotation.h"

void test_solution(){
    int n = 3; //Dimensjon på matrisene
    mat A(n,n);

    //Lager en matrise
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
    A = rotate(A,n);
    int tol = 1E-4;
    cout << A << endl;
    int x = abs(abs(10.90582184)-abs(A(2,2))) + abs(abs(1.08097442) - abs(A(0,0))) + abs(abs(-3.98679626) - abs(A(1,1)));
    cout << x << endl;
    cout << eig_sym(A) << endl;

    /*Kjører funksjonene til vi enten har nådd maks antall iterasjoner eller til
        det største ikke diagonale elementet er mindre enn toleransen.*/
};


void test_maxoffdiag(){
    int n = 5;
    mat A(n,n);
    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
                A(i,j) = 1;
        };
    };
    A(0,2) = 3;
    A(2,0) = 3;
    int k, l;
    int max = maxoffdiag(A,&k,&l,n);
    cout << A << endl;
    cout << max << endl;
};


#endif // TEST_JACOBI_ROTATION_H

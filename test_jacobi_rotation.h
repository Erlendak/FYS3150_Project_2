#ifndef TEST_JACOBI_ROTATION_H
#define TEST_JACOBI_ROTATION_H

#include "jacobi_rotation.h"

void test_solution(){
    int n = 3; //Dimensjon på matrisene
    mat A(n,n);
    A(0,0) = 1;
    A(0,1) = 0;
    A(0,2) = -2;
    A(1,0) = 0;
    A(1,1) = 2;
    A(1,2) = 7;
    A(2,0) = -2;
    A(2,1) = 7;
    A(2,2) = 5;

    A = rotate(A,n);
    double tol = 1E-4;
    double x = abs(abs(10.90582184)-abs(A(2,2))) + abs(abs(1.08097442) - abs(A(0,0))) + abs(abs(-3.98679626) - abs(A(1,1)));
    try{
        if (x > tol){
        throw "Warning the rotation mehtod is not as accurat as expected, there may be a serius error.";
    }
    }
        catch (const char* msg){
            cerr << msg <<endl;
        }
};


void test_maxoffdiag(){
    int n = 5;
    mat A(n,n);
    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
                A(i,j) = 1;
        };
    };
    A(1,3) = 3;
    A(3,1) = 3;
    int k, l;
    int max = maxoffdiag(A,&k,&l,n);
    try{
        if (max != 3){
        throw "Warning critical error, the maxoffdiag() function does not work properly"
            "\nIt did not find the largest number.";
    }
    }
        catch (const char* msg){
            cerr << msg <<endl;
        }
    //cout << A << endl;
    //cout << max << endl;
}
void test_syntac(){
//teste forskjellige n i forhold til matrise A's n. For eksempel negativ n.
//usymetrisk matrise.
//teste matriser under 3.

}
void tests(){
    test_solution();
    test_maxoffdiag();
};
#endif // TEST_JACOBI_ROTATION_H


#ifndef TEST_JACOBI_ROTATION_H
#define TEST_JACOBI_ROTATION_H

#include "jacobi_rotation.h"

void test_solution(){
    /*test_solution:
    *Function to test that we get the right diagonal elements
     out of a symmetric matrix after we have rotated it. We have
     found the eigenvalues analytically and compare them to the numerical ones*/

    int n = 3;
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

    rotate(A,n);
    double tol = 1E-4;
    double x = abs(abs(10.90582184)-abs(A(2,2))) + abs(abs(1.08097442) - abs(A(0,0))) + abs(abs(-3.98679626) - abs(A(1,1)));
    try{
        if (x > tol){
        throw "Warning: The Jacobi rotation method is not accurate and is not giving excpected values, there may be a serious problem";
    }
    }
        catch (const char* msg){
            cerr << msg <<endl;
        }
};

void test_rotate(){
    /*test_solution:
    *Function to test that the Jacobi rotation
     preserves the eigenvalues. The eigenvalues before
     and after the transform should be the same.*/

    int n = 3;
    mat A(n,n);
    A(0,0) = 3;
    A(0,1) = 0;
    A(0,2) = -7;
    A(1,0) = 0;
    A(1,1) = 2;
    A(1,2) = 5;
    A(2,0) = -7;
    A(2,1) = 5;
    A(2,2) = 5;

    rotate(A,n);
    double tol = 1E-4;
    double x = abs(abs(eig_sym(A)[0])-abs(A(0,0))) + abs(abs(eig_sym(A)[1]) - abs(A(1,1))) + abs(abs(eig_sym(A)[2]) - abs(A(2,2)));
    try{
        if (x > tol){
        throw "Warning: The Jacobi rotation method does not preserve the eigenvalues. Eigenvalues before and after rotate are not the same, something is wrong.";
    }
    }
        catch (const char* msg){
            cerr << msg <<endl;
        }
};


void test_maxoffdiag(){
    /*test_maxoffdiag:
    Function to test if the max_offdiag function actually
    gives the maximum non-diagonal element.*/
    int n = 5;
    mat A(n,n);
    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
                A(i,j) = 1;
        }
    }

    A(1,3) = 3;
    A(4,4) = 5;
    A(3,1) = 3;

    int k, l;
    int max = maxoffdiag(A,&k,&l,n);
    try{
        if (max != 3){
        throw "Warning, critical error: The maxoffdiag() function does not work properly"
            "\nIt did not find the max non-diagonal number.";
    }
    }
        catch (const char* msg){
            cerr << msg <<endl;
        }
}

void test_syntac(){
//teste forskjellige n i forhold til matrise A's n. For eksempel negativ n.
//usymetrisk matrise.
//teste matriser under 3.

}

void tests(){
    /*A function where we have all
    of the tests. Instead of running each
    individual test we can just run this and everything
    will be tested.*/
    test_solution();
    test_maxoffdiag();
    test_rotate();
};
#endif // TEST_JACOBI_ROTATION_H


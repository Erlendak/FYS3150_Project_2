#ifndef JACOBI_ROTATION_H
#define JACOBI_ROTATION_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "armadillo"

using namespace arma;
using namespace std;

double maxoffdiag(mat A,int *k,int *l,int n){
    /*maxoffdiag:
     * Function to find the absolute max non-diagonal element
        of the matrix.*/

       double max;
       for(int i = 0; i<n; i++){
           for(int j= i+1; j<n; j++){
               double a = fabs(A(i,j));
               if(a>max){
                   max = a; *l=i; *k = j;
               }
               double b = fabs(A(j,i));
               if(b>max){
                   max = b; *l=j; *k = i;
               }
           }
       }
       return max;
};


void rotate(mat & A , int n){
    /*rotate:
     * Rotates the matrix so that the non-diagonal elements are forced to become zero.
     * After enough iterations vi should be left with a diagonal matrix with the
     * eigenvalues on the diagonal.
     * */

    int k, l;
    mat R(n,n);
    double epsilon = 1E-8; //Tolerance
    int iteration = 0;
    int max_iter = n*n*n; //Max number of iteration.
    double max_offdiag = maxoffdiag(A,&k,&l,n);

    //We keep iterating until all non-diag elements are either
    // zero or until we hit the max number of iterations we have set.
    while(fabs(max_offdiag) > epsilon && iteration <= max_iter){
        //double progress = double(iteration)/double(max_iter);
        //cout.flush();
        //cout << progress*100 << " %\r";
         max_offdiag = maxoffdiag(A,&k,&l,n);

    double s,c;
    /*If our non-diagonal element is already zero we don't want to waste
     * memory rotating our matrix. Therefor we make an if statement to check if
       the non-diag element is zero.*/
    if(A(k,l) != 0.0){
        double t,tau;
        tau = (A(l,l) - A(k,k))/(2*A(k,l));

        if(tau >= 0){
            t = 1.0/(tau + sqrt(1.0+tau*tau));
        }else{
            t= -1.0/(-tau + sqrt(1.0+tau*tau));
        }

        c = 1/sqrt(1+t*t);
        s = c*t;
    }else{
        c = 1.0;
        s = 0.0;
    }


    //This is where the diagonalization happens
    double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
    a_kk = A(k,k);
    a_ll = A(l,l);
    A(k,k) = c*c*a_kk - 2*c*s*A(k,l) + s*s*a_ll;
    A(l,l) = s*s*a_kk + 2.0*c*s*A(k,l) + c*c*a_ll;
    A(k,l) = 0.0;
    A(l,k) = 0.0;

    for(int i = 0; i<n; i++){
        if(i != k && i != l){
            a_ik = A(i,k);
            a_il = A(i,l);
            A(i,k) = c*a_ik - s*a_il;
            A(k,i) = A(i,k);
            A(i,l) = c*a_il + s*a_ik;
            A(l,i) = A(i,l);


        }

        r_ik = R(i,k);
        r_il = R(i,l);
        R(i,k) = c*r_ik - s*r_il;
        R(i,l) = c*r_il + s*r_ik;
    }

             iteration++;
      }
cout<<iteration<<endl;

}


vec diagelement(mat A, int n){
    /*diagelement:
     * Takes the diagonal elements of the rotated matrix and prints them out.
     * This is so we can just look at the important elements instead of
     * having a matrix full of zeroes and only diagonal elements.*/

    vec eigen(n);
    for(int i=0; i<n; i++){
          eigen(i) = A(i,i);
        }
    double tmp;
    for(int j =0; j<n; j++){
        double min = eigen(j);
        int k = j ;
        for(int i=j+1; i<n; i++){

            if(abs(eigen(i)) < min){
                min = eigen(i);
                k = i;
            }
        }
        tmp = eigen(j);

        eigen(j) = min;
        eigen(k) = tmp;
}

    return eigen;
};


/*
vec diagelement(mat A, int n, int k){
    vec eigen(n);
    for(int i=0; i<n; i++){
          eigen(i) = A(i,i);
        }
    double tmp;
    for(int j =0; j<n; j++){
        double min = eigen(j);
        int k = j ;
        for(int i=j+1; i<n; i++){

            if(abs(eigen(i)) < min){
                min = eigen(i);
                k = i;
            }
        }
        tmp = eigen(j);

        eigen(j) = min;
        eigen(k) = tmp;
}

    return eigen;
};*/


#endif // JACOBI_ROTATION_H

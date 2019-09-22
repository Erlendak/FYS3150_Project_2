#ifndef JACOBI_ROTATION_H
#define JACOBI_ROTATION_H

#endif // JACOBI_ROTATION_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "armadillo"

using namespace arma;
using namespace std;

/*maxoffdiag:
 * Funksjon for å finne det største
 * ikke diagonale matriseelementet.*/
double maxoffdiag(mat A,int *k,int *l,int n){
       double max;
       for(int i = 0; i<n; i++){
           for(int j= i+1; j<n; j++){
               double a = fabs(A(i,j));
               if(a>max){
                   max = a; *l=i; *k = j;
               }
           }
       }
       return max;
}

/*rotate:
 * Roterer matrisen slik at ikke diagonale elementer tvinges til å bli null
 * */
mat rotate(mat A, int n){
    int k, l;
    mat R(n,n);
    double epsilon = 1E-8; //Toleranse
    int iteration = 0;
    int max_iter = n*n*n; //Max antall iterasjoner
    double max_offdiag = maxoffdiag(A,&k,&l,n);
    while(fabs(max_offdiag) > epsilon && iteration <= max_iter){
         max_offdiag = maxoffdiag(A,&k,&l,n);

    double s,c;
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

    return A;
}


/*eigen:
 * Lager en matrise som inneholder egenverdiene
 */
void eigen(mat A, mat R, int n){
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==j){
                R(i,j) = 1;
            }else{
                R(i,j) = 0;
            }
        }
    }
}

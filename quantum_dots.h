#ifndef QUANTUM_DOTS_H
#define QUANTUM_DOTS_H
#include "jacobi_rotation.h"


void task_2b(){
    /*Code to solve task 2b.
    We define a tridiagonal matrix and let our rotate
    function solve it.*/

    double n = 100;
    double rho_0 = 0;
    double rho_n = 1;
    double h  = (rho_n - rho_0)/(n);
    double analytisk;

    //This gives us the analytical eigenvalues in 2b.
    for(int j = 1; j<n+1;j++){
              analytisk = (2/(h*h))+ 2*(-1/(h*h))*(cos((j*M_PI)/(n+1)));
              cout << analytisk << endl;
             };

    vec rho(n);
    for (int i = 0; i < n; ++i) {
        rho[i] = rho_0 + (i+1)*h;
    }

    mat B(n,n);

    //Define every element other than the non-tridiagonal elements to be zero
    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
                B(i,j) = 0;
        }
    }

    //This is our diagonal elements
    for(int i = 0; i<n;i++){
               B(i,i) = (2/(h*h));
       };

    //This is the elements next to the diagonal
    for(int j = 1; j<n;j++){
               B(j-1,j) = -1/ (h*h);
               B(j,j-1) = -1/(h*h);

       };

    rotate(B,n);
   cout << B << endl;
}

void task_2d(){
    /*Code to solve task 2d.
    We do almost the same as in 2d, the point is to try to approximate rho_n = infinity.
    We also add rho^2 to our diagonal elements.
    */

    double n = 200;
    double rho_0 = 0;
    double rho_n = 10;
    double h  = (rho_n - rho_0)/(n);
    double analytisk;

    vec rho(n);
        for (int i = 0; i < n; ++i) {
            rho[i] = rho_0 + (i+1)*h;
        }

    mat B(n,n);

    //Analytical eigenvalues for task 2d.
    // We know the eigenvalues are 3,7,11,15,...
    for(int i = 0; i<n; i++){
        analytisk = 3 + i*4;
        cout << analytisk << endl;
    }

    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
            B(i,j) = 0;
        }
    }

    for(int i = 0; i<n;i++){
           B(i,i) = (2/(h*h))+(rho[i]*rho[i]);
        }

    for(int j = 1; j<n;j++){
           B(j-1,j) = -1/ (h*h);
           B(j,j-1) = -1/(h*h);
   }

    rotate(B,n);
    //cout << diagelement(B, n) << endl;
}


void task_2e(double omega){
   /*Code to solve task 2e.
    We do almost the same as in 2d and 2b
    but we add omega^2*rho^2+(1/rho) to the diagonal elements.*/

    double n = 100;
    double rho_0 = 0;
    double rho_n = 10;
    double h  = (rho_n - rho_0)/(n);

    vec rho(n);
    for (int i = 0; i < n; ++i) {
        rho[i] = rho_0 + (i+1)*h;
    }

    mat B(n,n);

    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
                B(i,j) = 0;
        }
    }

    for(int i = 0; i<n;i++){
               B(i,i) = (2/(h*h))+( (omega*omega)*(rho[i]*rho[i]))+(1/rho[i]);
       };

    for(int j = 1; j<n;j++){
               B(j-1,j) = -1/ (h*h);
               B(j,j-1) = -1/(h*h);

       };

    rotate(B,n);
    cout << diagelement(B, n) << endl;
}

#endif // QUANTUM_DOTS_H

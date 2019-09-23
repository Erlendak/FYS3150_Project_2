#ifndef QUANTUM_DOTS_H
#define QUANTUM_DOTS_H
#include "jacobi_rotation.h"

//Kode for å løse oppgave 2b.
void task_2b(){
    double n = 15;
    double rho_0 = 0;
    double rho_n = 1;
    double h  = (rho_n - rho_0)/(n);
    double analytisk;
    for(int j = 1; j<n+1;j++){
              analytisk = (2/(h*h))+ 2*(-1/(h*h))*(cos((j*M_PI)/(n+1)));
              cout << analytisk << endl;
             };

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
               B(i,i) = (2/(h*h));// + (rho[i]*rho[i])
       };

    for(int j = 1; j<n;j++){
               B(j-1,j) = -1/ (h*h);
               B(j,j-1) = -1/(h*h);

       };

    rotate(B,n);
    cout << diagelement(B, n) << endl; //Printer ut alle diagonalelementene
}

//Kode for å løse oppgave 2d.
void task_2d(){
double n = 5;
double rho_0 = 0;
double rho_n = 1000;
double h  = (rho_n - rho_0)/(n);
double analytisk;

vec rho(n);
for (int i = 0; i < n; ++i) {
    rho[i] = rho_0 + (i+1)*h;
}

for(int j = 1; j<n+1;j++){
          analytisk = ((2/(h*h))+(rho[j]+rho[j]))+ 2*(-1/(h*h))*(cos((j*M_PI)/(n+1)));
          cout << analytisk << endl;
         };

mat B(n,n);
for(int i= 0; i<n; i++){
    for(int j=0; j<n; j++){
            B(i,j) = 0;
    }
}

for(int i = 0; i<n;i++){
           B(i,i) = (2/(h*h))+(rho[i]*rho[i]);
   };

for(int j = 1; j<n;j++){
           B(j-1,j) = -1/ (h*h);
           B(j,j-1) = -1/(h*h);
   };

rotate(B,n);
cout << diagelement(B, n) << endl; //Printer ut alle diagonalelementene
}
#endif // QUANTUM_DOTS_H

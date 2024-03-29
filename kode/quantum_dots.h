#ifndef QUANTUM_DOTS_H
#define QUANTUM_DOTS_H
#include "jacobi_rotation.h"
#include <iomanip>



void task_2b(int n){
    /*Code to solve task 2b.
    We define a tridiagonal matrix and let our rotate
    function solve it.*/


    double rho_0 = 0;
    double rho_n = 1;
    double h  = (rho_n - rho_0)/(n);
    vec analytisk(n);

    vec rho(n);
    for (int i = 1; i < n-1; ++i) {
        rho[i] = rho_0 + (i+1)*h;
    }

    mat B(n,n);

    //Define every element other than the non-tridiagonal elements to be zero
    for(int i= 1; i<n-1; i++){
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
       }
    clock_t start1, finish1;
    start1 = clock();
    mat armadillos_eig = eig_sym(B);
    finish1 = clock();
    cout << "Armadillos time:" <<((((double)finish1 - (double)start1)/CLOCKS_PER_SEC)) << endl;
    //cout <<armadillos_eig <<endl;

    mat x = rotate(B,n);
    sort_eigenvec(B,x,n);

    clock_t start, finish;
    start = clock();
    //This gives us the analytical eigenvalues in 2b.
    for(int j = 1; j<n+1;j++){
              analytisk = (2/(h*h))+ 2*(-1/(h*h))*(cos((j*M_PI)/(n+1)));
    }
    finish = clock();
    cout << "Analytical time:" <<((((double)finish - (double)start)/CLOCKS_PER_SEC)) << endl;



    ofstream ofile;
    string filename = "2b.dat";
    string fileout = filename;
    ofile.open(fileout);
    ofile << setiosflags(ios::showpoint | ios::uppercase);

         ofile << setw(15) << setprecision(8) <<  analytisk;
         ofile << setw(15) << setprecision(8) <<  sort_diag(B,n);

      ofile.close();
}

void task_2d(int n){
    /*Code to solve task 2d.
    We do almost the same as in 2d, the point is to try to approximate rho_n = infinity.
    We also add rho^2 to our diagonal elements.
    */

    ofstream ofile;
    double rho_0 = 0;
    double rho_n = 10;
    double h  = (rho_n - rho_0)/(n);
    double analytisk;

    vec rho(n);
        for (int i = 1; i < n-1; ++i) {
            rho[i] = rho_0 + (i+1)*h;
        }

    mat B(n,n);

    //Analytical eigenvalues for task 2d.
    // We know the eigenvalues are 3,7,11,15,...
    clock_t start, finish;
    start = clock();
    for(int i = 0; i<n; i++){
        analytisk = 3 + i*4;
        //cout << analytisk << endl;
    }
    finish = clock();
    cout << "Analytical time:" <<((((double)finish - (double)start)/CLOCKS_PER_SEC)) << endl;


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

    mat x = rotate(B,n);
    sort_eigenvec(B,x,n);

    string filename = "2d.dat";
    string fileout = filename;
    ofile.open(fileout);
    ofile << setiosflags(ios::showpoint | ios::uppercase);
      //      ofile << "       x:             approx:          exact:       relative error" << endl;
         ofile << setw(15) << setprecision(8) << x;
      ofile.close();
}


void task_2e(double omega, int n){
   /*Code to solve task 2e.
    We do almost the same as in 2d and 2b
    but we add omega^2*rho^2+(1/rho) to the diagonal elements.
    We make it a function of omega so we can test for different omega values.*/

    ofstream ofile;
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
       }

    for(int j = 1; j<n;j++){
               B(j-1,j) = -1/ (h*h);
               B(j,j-1) = -1/(h*h);

       }

    mat x = rotate(B,n);
    cout << sort_eigenvec(B,x,n)<<endl;
    string omega_string = to_string(omega);
    string filename = "Result_omega"+omega_string+".dat";
    string fileout = filename;
    ofile.open(fileout);
    ofile << setiosflags(ios::showpoint | ios::uppercase);
      //      ofile << "       x:             approx:          exact:       relative error" << endl;
         ofile << setw(15) << setprecision(8) << x;

      ofile.close();
}

#endif // QUANTUM_DOTS_H

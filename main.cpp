#include "test_jacobi_rotation.h"
#include "jacobi_rotation.h"
#include "quantum_dots.h"

int main(){
tests();
<<<<<<< HEAD
double N = 200;
double rho_0 = 0;
double rho_n = 1;
double h  =  (rho_n - rho_0)/(N);
int analytisk1;

int analytisk2;
for(int j = 0; j<N;j++){
          analytisk2 = (2/(h*h))+ 2*(-1/ (h*h))*cos((j*M_PI)/(N+1))*j;
          cout << analytisk2 << endl;
         };

vec rho(N);
for (int i = 0; i < N; ++i) {
    rho[i] = rho_0 + (i+1)*h;
}


mat B(N,N);
for(int i= 0; i<N; i++){
    for(int j=0; j<N; j++){
            B(i,j) = 0;
    }
}
//cout << B << endl;
for(int i = 0; i<N;i++){
           B(i,i) = (2/(h*h));// + (rho[i]*rho[i])
   };
//cout << B << endl;
for(int j = 1; j<N;j++){
           B(j-1,j) = -1/ (h*h);
           B(j,j-1) = -1/(h*h);

   };


for(int j = 1; j<N;j++){
    analytisk1 = B(j,j) + 2*B(j,j-1)*cos((j*M_PI)/(N+1))*j;
    cout << analytisk1 << endl;
}


cout << B << endl;
rotate(B,N);
cout << B << endl;
//cout << rho << endl;
=======
task_2d();
>>>>>>> 2cbc6673a60dfaea4e363fb1c032634b2a815338



return 0;
}

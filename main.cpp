#include "test_jacobi_rotation.h"
#include "jacobi_rotation.h"

int main(){
tests();
double N = 200;
double rho_0 = 0;
double rho_n = 10;
double h  =  (rho_n - rho_0)/(N+1);
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
           B(i,i) = (2/(h*h)) + (rho[i]*rho[i]);
   };
//cout << B << endl;
for(int j = 1; j<N;j++){
           B(j-1,j) = -1/ (h*h);
           B(j,j-1) = -1/(h*h);
   };
//cout << B << endl;
rotate(B,N);
cout << B(199,199) << endl;
//cout << rho << endl;

return 0;
}

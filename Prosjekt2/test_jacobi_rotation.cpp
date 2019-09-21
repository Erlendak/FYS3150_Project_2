#include "jacobi_rotation.h"

int main(){
    double epsilon = 1E-8; //Toleranse
    int n = 3; //Dimensjon på matrisene
    int k, l;
    int iteration = 0;
    int max_iter = n*n*n; //Max antall iterasjoner
    mat A(n,n);
    mat R(n,n);


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


    double max_offdiag = maxoffdiag(A,&k,&l,n);

    cout << eig_sym(A) << endl;

    /*Kjører funksjonene til vi enten har nådd maks antall iterasjoner eller til
        det største ikke diagonale elementet er mindre enn toleransen.*/
    while(fabs(max_offdiag) > epsilon && iteration <= max_iter){
           max_offdiag = maxoffdiag(A,&k,&l,n);
           A = rotate(A,R,k,l,n);


           iteration++;
    }
     cout << A << endl;
     cout << iteration << endl;

    return 0;
    }

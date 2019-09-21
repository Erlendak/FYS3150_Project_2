#include "jacobi_rotation.h"

int main(){
    int n = 3; //Dimensjon på matrisene
    mat A(n,n);
    mat A(n,n);

    int k, l;
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

    A = rotate(A,R,k,l,n);
    cout << A << endl;




    cout << eig_sym(A) << endl;

    /*Kjører funksjonene til vi enten har nådd maks antall iterasjoner eller til
        det største ikke diagonale elementet er mindre enn toleransen.*/

     cout << A << endl;
     cout << iteration << endl;

    return 0;
    }

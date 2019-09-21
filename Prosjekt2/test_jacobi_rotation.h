#ifndef TEST_JACOBI_ROTATION_H
#define TEST_JACOBI_ROTATION_H

#endif // TEST_JACOBI_ROTATION_H

void test_solution(){
    int n = 3; //Dimensjon på matrisene
    mat A(n,n);


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
    A = rotate(A,n);
    int tol = 1E-4
    cout << A << endl;


    abs(10.90582184-A(0,0))
    abs(1.08097442-A(1,1))

    cout << eig_sym(A) << endl;

    /*Kjører funksjonene til vi enten har nådd maks antall iterasjoner eller til
        det største ikke diagonale elementet er mindre enn toleransen.*/
};


void test_maxoffdiag(){
    mat A(5,5);

};

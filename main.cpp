#include "test_jacobi_rotation.h"
#include "jacobi_rotation.h"
#include "quantum_dots.h"


int main(){
    int n =200;
    int w = 0.01;

    tests();

    task_2e(w,n);

    task_2e(w,n);

    task_2e(w,n);
    //task_2d(n);

    //task_2e(0.5);
    //task_2e(5);
    return 0;
}

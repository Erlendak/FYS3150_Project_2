#include "test_jacobi_rotation.h"
#include "jacobi_rotation.h"
#include "quantum_dots.h"
#include <iomanip>

ofstream ofile;
int n = 200;
int main(int argc, char *argv[]){
    string filename;

        if( argc <= 1 ){
         cout << "Bad Usage: " << argv[0] <<
            " read also file name on same line" << endl;
             exit(1);
        }
            else{
            filename = argv[1]; // first command line argument after name of program
        }

        // Declare new file name
        string fileout = filename;

        ofile.open(fileout);
        ofile << setiosflags(ios::showpoint | ios::uppercase);
          //      ofile << "       x:             approx:          exact:       relative error" << endl;

             ofile << setw(15) << setprecision(8) << task_2d(n);

          ofile.close();


//tests();

//task_2b();
//task_2e(0.01);
//task_2e(0.5);
//task_2e(5);
return 0;
}

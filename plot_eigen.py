import matplotlib.pyplot as plt
import numpy as np 

eigen_val = []


import sys

with open(sys.argv[1], 'r') as infile:
    print("Reading from "+sys.argv[1])
    for i in infile:
        data = i.split()
        e_val= data[0].split("[]")[0]
        eigen_val.append(float(e_val))
        #num_val.append(float(n_val))
        #x_val.append(float(x_v))
        



plt.title("Eigenvalues vs N, N=200")
plt.stem(eigen_val,label="Sorted eigen values")
#plt.plot(x_val,num_val, label="Numerical value")
plt.xlabel("N value")
plt.ylabel("Eigen value")
plt.legend()
plt.show()


import matplotlib.pyplot as plt
import numpy as np 

eigen_val = []


import sys


with open("2b.dat", 'r') as infile:
    print("Reading from "+"2b.dat")
    for i in infile:
        data = i.split()
        e_val= data[0].split("[]")[0]
        print(e_val)
        eigen_val.append(float(e_val))
        #num_val.append(float(n_val))
        #x_val.append(float(x_v))

"""   
with open("2d.dat", 'r') as infile:
    print("Reading from "+"2d.dat")
    for i in infile:
        data = i.split()
        e_val= data[2].split("[]")[0]
        eigen_val.append(float(e_val))
        #num_val.append(float(n_val))
        #x_val.append(float(x_v))
       
with open("2e.dat", 'r') as infile:
    print("Reading from "+"2e.dat")
    for i in infile:
        data = i.split()
        e_val= data[0].split("[]")[0]
        eigen_val.append(float(e_val))
        #num_val.append(float(n_val))
        #x_val.append(float(x_v))
"""

x = np.linspace(0,1,len(eigen_val))

plt.plot(x,eigen_val,label="Sorted eigen values")
#plt.plot(x_val,num_val, label="Numerical value")
plt.title("Potensialet til elektronet")
plt.ylabel("Utslag ; ")
plt.xlabel("Posisjon ; ")
plt.grid()
plt.show()


import matplotlib.pyplot as plt
import numpy as np 

eigen_val1 = []
eigen_val2 = []
eigen_val3 = []
eigen_val4 = []


import sys


with open("2e.dat", 'r') as infile:
    print("Reading from "+"2e.dat")
    for i in infile:
        data = i.split()
        e_val1= data[0].split("[]")[0]
        e_val2= data[1].split("[]")[0]
        e_val3= data[2].split("[]")[0]
        e_val4= data[3].split("[]")[0]
        eigen_val1.append(float(e_val1))
        eigen_val2.append(float(e_val2))
        eigen_val3.append(float(e_val3))
        eigen_val4.append(float(e_val4))
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

x = np.linspace(0,1,len(eigen_val1))

plt.plot(x,eigen_val1,label="Sorted eigen values")
plt.plot(x,eigen_val2,label="Sorted eigen values")
plt.plot(x,eigen_val3,label="Sorted eigen values")
plt.plot(x,eigen_val4,label="Sorted eigen values")
#plt.plot(x_val,num_val, label="Numerical value")
plt.title("Potensialet til elektronet")
plt.ylabel("Utslag ; ")
plt.xlabel("Posisjon ; ")
plt.grid()
plt.show()


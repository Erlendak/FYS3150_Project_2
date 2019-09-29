import matplotlib.pyplot as plt
import numpy as np 

eigen_val1 = []
eigen_val2 = []
eigen_val3 = []
eigen_val4 = []


import sys

"""
with open("2b.dat", 'r') as infile:
    print("Reading from "+"2b.dat")
    for i in infile:
        data = i.split()
        e_val1= data[0].split()[0]
        e_val2= data[1].split("[]")[0]
        e_val3= data[2].split("[]")[0]
        e_val4= data[3].split("[]")[0]
        eigen_val1.append(float(e_val1))
        eigen_val2.append(float(e_val2))
        eigen_val3.append(float(e_val3))
        eigen_val4.append(float(e_val4))
        eigen_val1.append(float(e_val1))
        #num_val.append(float(n_val))
        #x_val.append(float(x_v))
"""


with open("2d.dat", 'r') as infile:
    print("Reading from "+"2d.dat")
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


"""      
with open("2e.dat", 'r') as infile:
    print("Reading from "+"2e.dat")
    for i in infile:
        data = i.split()
        e_val= data[0].split("[]")[0]
        eigen_val.append(float(e_val))
        #num_val.append(float(n_val))
        #x_val.append(float(x_v))
"""

x = np.linspace(0,10,len(eigen_val1))

plt.plot(x,eigen_val1,label="Egenvektor 1")
plt.plot(x,eigen_val2,label="Egenvektor 2")
plt.plot(x,eigen_val3,label="Egenvektor 3")
plt.plot(x,eigen_val4,label="Egenvektor 4")
plt.title("",size=17)
plt.ylabel("Utslag ; ",size=17)
plt.xlabel("Posisjon ; ",size=17)
plt.grid()
plt.legend()
plt.show()


import matplotlib.pyplot as plt
import numpy as np
import sys
eigen_vec_omega1 = []
eigen_vec_omega5 = []
eigen_vec_omega001 = []
eigen_vec_omega05 = []


with open("Result_omega0.010000.dat", 'r') as infile:
    print("Reading from "+"Result_omega0.010000.dat")
    for i in infile:
        data = i.split()
        tmp = data[0].split("[]")[0]
        eigen_vec_omega001.append(float(tmp))

with open("Result_omega0.500000.dat", 'r') as infile:
    print("Reading from "+"Result_omega0.500000.dat")
    for i in infile:
        data = i.split()
        tmp = data[0].split("[]")[0]
        eigen_vec_omega05.append(float(tmp))

with open("Result_omega1.000000.dat", 'r') as infile:
    print("Reading from "+"Result_omega1.000000.dat")
    for i in infile:
        data = i.split()
        tmp = data[0].split("[]")[0]
        eigen_vec_omega1.append(float(tmp))

with open("Result_omega5.000000.dat", 'r') as infile:
    print("Reading from "+"Result_omega5.000000.dat")
    for i in infile:
        data = i.split()
        tmp = data[0].split("[]")[0]
        eigen_vec_omega5.append(float(tmp))
"""


tmp = []
with open("Result_omega5.000000.dat", 'r') as infile:
    print("Reading from "+".dat")
    for i in infile:
        data = i.split()
        tmp.append(float(data[0]))

omega_5 = np.array(tmp)
tmp = []

with open("Result_omega1.000000.dat", 'r') as infile:
    print("Reading from "+".dat")
    for i in infile:
        data = i.split()
         = data[0].split("[]")[0]
        tmp.append(float(tnp[0]))

omega_1 = np.array(tmp)
tmp = []

with open("Result_omega0.500000.dat", 'r') as infile:
    print("Reading from "+".dat")
    for i in infile:
        data = i.split()
        tmp.append(float(data[0]))

omega_05 = np.array(tmp)
tmp = []

with open("Result_omega0.010000.dat", 'r') as infile:
    print("Reading from "+".dat")
    for i in infile:
        data = i.split()
        tmp.append(float(data[0]))

omega_001 = np.array(tmp)
tmp = []

print(omega_1)
"""
x= np.linspace(0,10,200)
plt.plot(x,eigen_vec_omega001,label=r'$\omega = 0,01 $')
plt.plot(x,eigen_vec_omega05,label=r'$\omega = 0,5 $')
plt.plot(x,eigen_vec_omega1,label=r'$\omega = 1 $')
plt.plot(x,eigen_vec_omega5,label=r'$\omega = 5 $')
plt.title("",size=17)
plt.ylabel("Utslag ; ",size=17)
plt.xlabel("Posisjon ; ",size=17)
plt.grid()
plt.legend()
plt.show()

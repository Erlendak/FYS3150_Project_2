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



n = len(eigen_vec_omega1)
x= np.linspace(0,10,n)
eigen_vec_omega001 = np.array(eigen_vec_omega001)
eigen_vec_omega05 = np.array(eigen_vec_omega05)
eigen_vec_omega1 = np.array(eigen_vec_omega1)
eigen_vec_omega5 = np.array(eigen_vec_omega5)
plt.plot(x,eigen_vec_omega001**2,label=r'$\omega = 0,01 $')
plt.plot(x,eigen_vec_omega05**2,label=r'$\omega = 0,5 $')
plt.plot(x,eigen_vec_omega1**2,label=r'$\omega = 1 $')
plt.plot(x,eigen_vec_omega5**2,label=r'$\omega = 5 $')
plt.title("Estimasjon av elektronenes posisjon\nVed forskjellige oscillator frekvenser",size=17)
plt.ylabel("Sansynlighet ; ",size=15)
plt.xlabel("Posisjon ; ",size=15)
plt.grid()
plt.legend()
plt.show()

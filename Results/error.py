import matplotlib.pyplot as plt
import numpy as np

tmp = []



import sys


with open("2b.dat", 'r') as infile:
    print("Reading from "+"2b.dat")
    for i in infile:
        data = i.split()
        tmp.append(float(data[0]))


analytisk = []
numerisk = []

N = int( len(tmp)/2 )
for i in range(  N  ):
    analytisk.append(tmp[i])
    numerisk.append(tmp[N+i])

ana_ary = np.array(analytisk)
num_ary= np.array(numerisk)
print(abs((ana_ary-num_ary)/ana_ary))

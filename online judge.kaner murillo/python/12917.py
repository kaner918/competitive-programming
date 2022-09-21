#https://onlinejudge.org/external/129/12917.pdf
#12917

from sys import stdin

cadena = [int(x) for x in stdin.readline().split()]

while cadena!=[]:

    calculo  = cadena[0]-(cadena[2] - cadena[1])

    if calculo>0:
        print("Hunters win!")
    
    else:
        print("Props win!")

    cadena = [int(x) for x in stdin.readline().split()]

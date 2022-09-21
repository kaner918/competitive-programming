#https://onlinejudge.org/external/126/12646.pdf
#12646

from sys import stdin 

cadena = stdin.readline().split()

while cadena != []:

    if cadena[0] != cadena[1] and cadena[0] != cadena[2]:

        print("A")
    
    elif cadena[1] != cadena[0] and cadena[1] != cadena[2]:
        print("B")

    elif cadena[2] != cadena[0] and cadena[2] != cadena[1]:
        print("C")
    
    else:
        print("*")

    cadena = stdin.readline().split()

#https://onlinejudge.org/external/4/414.pdf
#414

from sys import stdin

cantidad = int(stdin.readline())

while cantidad != 0:

    cadenas = []
    menor = 25

    for i in range(cantidad):

        cadena = stdin.readline().rstrip('\n')

        if cadena.count(" ") < menor:
            menor  = cadena.count(" ")
        
        cadenas.append(cadena.count(" "))

    suma = 0

    for i in range(cantidad):

        suma+= cadenas[i] - menor
    
    print(suma)

    cantidad = int(stdin.readline())
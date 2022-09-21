#https://onlinejudge.org/external/111/11192.pdf
#11192

from sys import stdin 
from collections import deque

secuencia = stdin.readline().split()

while secuencia != ['0']:

    cad = []
    pila = deque()  
    contador = 0

    for i in range(len(secuencia[1])+1):

        if contador == len(secuencia[1])//int(secuencia[0]):

            while len(pila) != 0:

                cad.append(pila[-1])
                pila.pop()
            contador = 0

        if i<len(secuencia[1]):

            pila.append(secuencia[1][i])
            contador+=1

    print("".join(cad))

    secuencia = stdin.readline().split()
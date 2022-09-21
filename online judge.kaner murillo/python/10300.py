#https://onlinejudge.org/external/103/10300.pdf
#https://www.udebug.com/UVa/10300
#10300

from sys import stdin
import math

casos = int(stdin.readline().strip())

for i in range(casos):

    agricultores = int(stdin.readline().strip())

    suma = 0

    for n in range(agricultores):

        granja = [int(x) for x in stdin.readline().split()]

        suma+= ((granja[0]/granja[1])*granja[2])*granja[1]

    print(math.ceil(suma))


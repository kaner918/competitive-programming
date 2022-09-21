#https://onlinejudge.org/external/126/12658.pdf
#12658

from sys import stdin 

cantidad = int(stdin.readline().strip())

matriz  = []

for i in range(6):

    matriz.append([stdin.readline().rstrip('\n')])

i = 0 
cadena = []

while i < len(matriz[0]):

    if matriz[0][i] == "*"
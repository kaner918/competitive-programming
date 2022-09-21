#https://onlinejudge.org/external/127/12709.pdf
#12709

from sys import stdin

cantidad = int(stdin.readline().strip())

while cantidad != 0:

    lista = []

    for i in range(cantidad):
        
        lista.append([int(x) for x in stdin.readline().split()])

    lista.sort(key= lambda x: (-x[2], -(x[0] * x[1] * x[2])))

    print(lista[0][0] * lista[0][1] * lista[0][2])
    
    cantidad = int(stdin.readline().strip())

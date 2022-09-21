#https://onlinejudge.org/external/113/11364.pdf
#https://www.udebug.com/UVa/11364
#11364

from sys import stdin

casos = int(stdin.readline().strip())

for i in range(casos):

    tiendas = stdin.readline().strip()

    parqueadero = [int(x) for x in stdin.readline().split()]

    menor = parqueadero[0]
    mayor = parqueadero[-1]

    for n in range(len(parqueadero)):

        if parqueadero[n] < menor:
            menor = parqueadero[n]
        
        if parqueadero[n]>mayor:
            mayor = parqueadero[n]

    print((mayor-menor)*2)
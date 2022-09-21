#https://onlinejudge.org/external/113/11364.pdf
#https://www.udebug.com/UVa/11364
#11364

from sys import stdin

casos = int(stdin.readline().strip())

for i in range(casos):

    tiendas = stdin.readline().strip()

    parqueadero = [int(x) for x in stdin.readline().split()]

    parqueadero.sort()

    print((parqueadero[-1]-parqueadero[0])*2)
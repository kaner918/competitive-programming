#https://onlinejudge.org/external/108/10812.pdf
#10812

from sys import stdin

cases = int(stdin.readline().strip())

for i in range(cases):

    suma, diferencia = [int(x) for x in stdin.readline().split()]

    if suma < diferencia or (suma - diferencia) % 2 != 0:
        
        print("impossible")
    
    else:

        menor = (suma - diferencia) // 2

        print(suma-menor, menor)
        
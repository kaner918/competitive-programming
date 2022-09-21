#https://onlinejudge.org/external/118/11875.pdf
#11875

from sys import stdin

casos = int(stdin.readline())

for i in range(1, casos+1):

    numeros = [int(x) for x in stdin.readline().split()]
    numeros.pop(0)
    numeros.sort()

    print(f"Case {i}: {numeros[len(numeros)//2]}")
    
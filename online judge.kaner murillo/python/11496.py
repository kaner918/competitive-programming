#https://onlinejudge.org/external/114/11496.pdf
#11496

from sys import stdin

cantidad = int(stdin.readline())

while cantidad != 0:

    sonidos = [int(x) for x in stdin.readline().split()]
    contador = 0

    for i in range(1,cantidad-1):

        if (sonidos[i] > sonidos[i-1] and sonidos[i] > sonidos[i+1]) or (sonidos[i] < sonidos[i-1] and sonidos[i]<sonidos[i+1]):

            contador+=1
    
    if (sonidos[-1] > sonidos[-2] and sonidos[-1] > sonidos[0]) or (sonidos[-1] < sonidos[-2] and sonidos[-1]<sonidos[0]):

        contador+=1
    
    if (sonidos[0] > sonidos[-1] and sonidos[0] > sonidos[1]) or (sonidos[0] < sonidos[-1] and sonidos[0]<sonidos[1]):

        contador+=1

    print(contador)

    cantidad = int(stdin.readline())
#https://onlinejudge.org/external/126/12696.pdf
#12696

from sys import stdin

casos = int(stdin.readline().strip())

contador = 0

for i in range(casos):

    dimensiones = [float(x) for x in stdin.readline().split()]

    ans = True

    if dimensiones[0] > 56 or dimensiones[1] > 45 or dimensiones[2] > 25:
        ans = False
    
    if ans == False and dimensiones[0] + dimensiones[1] + dimensiones[2]<=125:

        ans = True

    if dimensiones[3] > 7:
        ans = False
    
    if ans == True:
        print(1)
        contador+=1
    
    else:
        print(0)

print(contador)
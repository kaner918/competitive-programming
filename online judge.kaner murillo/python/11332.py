#https://onlinejudge.org/external/113/11332.pdf
#https://www.udebug.com/UVa/11332
#11332

from sys import stdin

numero = int(stdin.readline().strip())

while numero != 0:

    ans = True
    suma = 0
    while suma>9 or ans == True:
        
        suma = 0
        while numero >0:

            suma+=numero%10
            numero//=10
        numero = suma
        ans = False
    print(suma)
    numero = int(stdin.readline().strip())
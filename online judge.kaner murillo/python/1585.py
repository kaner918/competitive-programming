#https://onlinejudge.org/external/15/1585.pdf
#https://www.udebug.com/UVa/1585
#1585

from sys import stdin

cases = int(stdin.readline().strip())

for i in range(cases):

    contadorGlobal = 0
    contadorLocal = 0

    cadena = stdin.readline().rstrip('\n')

    for i in cadena:

        if i == 'O':
            contadorGlobal+=contadorLocal+1
            contadorLocal+=1
        
        else:
            contadorLocal = 0
    print(contadorGlobal)
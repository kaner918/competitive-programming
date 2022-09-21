#https://onlinejudge.org/external/1/100.pdf
#100

from sys import stdin

linea = stdin.readline().strip()

while linea != "":
    
    mayor = 0

    n,j = [int(x) for x in linea.split()]

    for i in range(n, j+1):

        contador = 0
        numero = i

        while numero != 1:

            if numero % 2 == 0:

                numero = numero/2

            else:
                
                numero = numero*3 +1

            contador+=1

        if contador > mayor:

            mayor = contador
        
    print(n, j, mayor+1)

    linea = stdin.readline().strip()
                 


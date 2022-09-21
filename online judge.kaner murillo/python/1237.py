#https://onlinejudge.org/external/12/1237.pdf
#1237

from sys import stdin

casos = int(stdin.readline().strip())

for i in range(casos):

    fabricantes = int(stdin.readline().strip())
    lista = []

    for n in range(fabricantes):

        lista.append(stdin.readline().split())

    precios = int(stdin.readline().strip())

    for n in range(precios):

        precio = int(stdin.readline().strip())

        ans = False
        x = 0 
        contador = 0
        posicion = 0

        while x < len(lista):

            if(precio>=int(lista[x][1]) and precio <= int(lista[x][2])):

                posicion = x
                ans = True
                contador+=1
            
            if contador == 2:
                x = len(lista)

            x+=1

        if ans == True and contador<2:
            print(lista[posicion][0])

        else:
            
            print("UNDETERMINED")
    
    if i < casos-1:
        print()
#https://onlinejudge.org/external/121/12150.pdf
#12150

from sys import stdin 

cantidadCarros = int(stdin.readline())

while cantidadCarros != 0:

    carros = []
    carros2 = []
    ans = True

    for i in range(cantidadCarros):

        carros.append([int(x) for x in stdin.readline().split()])
        carros2.append(0)

    i = 0
    
    while i<cantidadCarros and ans == True:

        nuevaPosicion = i+carros[i][1]

        if nuevaPosicion < 0 or nuevaPosicion > cantidadCarros-1 or carros2[nuevaPosicion] != 0:

            ans = False

        if ans == True:

            carros2[nuevaPosicion] = carros[i][0]

        i+=1

    if ans == True:

        cad = []

        for i in range(cantidadCarros-1):

            cad.append(str(carros2[i]))
            cad.append(" ")

        cad.append(str(carros2[-1]))

        print("".join(cad))

    else:

        print("-1") 
        
    cantidadCarros = int(stdin.readline())
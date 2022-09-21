#https://onlinejudge.org/external/113/11360.pdf
#11360

from sys import stdin 

casos = int(stdin.readline().rstrip('\n'))

for i in range(1,casos+1):
    
    tamano = int(stdin.readline().rstrip('\n'))
    matriz = []

    for n in range(tamano):

        matriz.append(list(stdin.readline().rstrip('\n')))
    
    operaciones  = int(stdin.readline().rstrip('\n'))

    for n in range(operaciones):

        operacion = stdin.readline().rstrip()

        #intercambiar filas, lo hago a traves de un auxiliar, interando directamente con cada lista dentro de la matriz
        if operacion[0] == 'r':

            a = int(operacion[4])-1
            b = int(operacion[6])-1

            matriz[a], matriz[b] = matriz[b], matriz[a]
        
        #intercambiando columnas, lo hago a atraves de un auxiliar, con la diferencia, de que no lo realizo directamente con las listas de la matriz, sino con cada valor de la posicion indicada, de que cada lista de la matriz
        elif operacion[0] == 'c':
            
            a = int(operacion[4])-1
            b = int(operacion[6])-1

            for m in range(len(matriz)):

                matriz[m][a], matriz[m][b] = matriz[m][b], matriz[m][a]


        #interamos sobre cada valor del arreglo, sumandole 1 y de ese resultado, obtener el residuo que queda al dividirlo entre 10
        elif operacion[0] == 'i':

            for m in range(len(matriz)):

                for x in range(len(matriz)):

                    matriz[m][x] =  str((int(matriz[m][x]) + 1)%10)
        
        #interamos sobre cada valor del arreglo, restandole 1 y de ese resultado, obtener el residuo que queda al dividirlo entre 10
        elif operacion[0] == 'd':

            for m in range(len(matriz)):

                for x in range(len(matriz)):

                    matriz[m][x] =  str((int(matriz[m][x]) - 1)%10)

        #creo una matriz identica a la original, donde voy a interar sobre sus posiciones, intercambiando la posicion del valor, cambiando su indice en las filas, por su indice en la columna
        else:

            matrizAux = []

            for m in range(len(matriz)):
                matrizAux.append(list(matriz[m]))

            for m in range(len(matriz)):

                for x in range(len(matriz)):
    
                    matriz [m][x] = matrizAux[x][m]
    
    print(f"Case #{i}")
    for n in matriz:

        print("".join(n))

    print("")

            
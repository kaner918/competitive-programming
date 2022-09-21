#https://onlinejudge.org/external/6/612.pdf
#612


from sys import stdin 

cases = int(stdin.readline().strip())

for i in range(cases):

    stdin.readline()

    columna, fila = [int(x) for x in stdin.readline().split()]
    entrada = []

    for n in range(fila):

        entrada.append([0, n, stdin.readline().rstrip('\n')])

    for cadena in entrada:
        
        inversiones = 0

        n = 0

        while n < columna-1:

            inversiones2 = 0

            for x in range(n+1,columna):

                if ord(cadena[2][n]) > ord(cadena[2][x]):
                    inversiones2+=1
                    
            inversiones+=inversiones2
            while cadena[2][n] == cadena[2][n+1] and n < columna-2:

                inversiones+=inversiones2
                n+=1
            n+=1

        cadena[0] = inversiones

    entrada.sort(key= lambda x: (x[0], x[1]))

    for cadena in entrada:

        print(cadena[2])

    if i < cases-1:

        print()






#https://onlinejudge.org/external/108/10855.pdf
#10855

from sys import stdin

def rotar(figura):

    figuraRotada = []

    for i in range(len(figura)):

        fila = []

        for n in range(len(figura)-1,-1,-1):

            fila.append(figura[n][i])

        figuraRotada.append("".join(fila))        
    
    return figuraRotada 

cube, miniCube = [int(x) for x in stdin.readline().split()]

while cube != 0 or miniCube !=0:

    matriz = []
    miniMatriz = []

    results = [0,0,0,0]

    for i in range(cube):

        matriz.append(stdin.readline().rstrip('\n'))

    for i in range(miniCube):

        miniMatriz.append(stdin.readline().rstrip('\n'))

    for i in range(4):

        ans = False
        n = 0

        while n < len(matriz):

            if miniMatriz[0][0] in matriz[n]:

                m = 0

                while m < len(matriz[n]):

                    if matriz[n][m] == miniMatriz[0][0]:
                        
                        x = 0
                        y = n
                        p = 0

                        aux  = []

                        while x < len(miniMatriz) and y < len(matriz ) and p < len(miniMatriz):

                            aux.append(matriz[y][m:m+len(miniMatriz[p])])

                            x+=1
                            y+=1
                            p+=1

                        if aux == miniMatriz:
                            results[i] += 1

                    m+=1
            n+=1

        miniMatriz = rotar(miniMatriz)
    
    print(results[0], results[1], results[2], results[3])
    
    cube, miniCube = [int(x) for x in stdin.readline().split()]
    
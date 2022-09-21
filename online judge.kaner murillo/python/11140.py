#https://onlinejudge.org/external/111/11140.pdf
#11140

from sys import stdin

def identificarFigura(figura):

    indiceMenor = len(figura[0])-1
    indiceMayor = 0

    lista = []
    acomulado = []
    flag = False

    for i in range(len(figura)):

        if "*" in figura[i]:

            for x in range(len(figura[i])):

                if figura[i][x] == "*" :

                    if x < indiceMenor:
                        indiceMenor = x

                    if x > indiceMayor:
                        indiceMayor = x

            if len(acomulado) > 0:

                lista.extend(acomulado)
                lista.append(figura[i])
                acomulado = []
            
            else:
                flag = True
                lista.append(figura[i])

        elif "*" not in figura[i] and flag == True:
            acomulado.append(figura[i])

    for i in range(len(lista)):

        aux = []
        
        for x in range(indiceMenor, indiceMayor+1):

            aux.append(lista[i][x])
        
        lista[i] = "".join(aux)

    return lista

def evaluarFigura(tablero, figura):

    ans = False
    flag = True 
    i = 0

    while len(figura) <= len(tablero)-i and ans == False:

        n = 0

        while len(figura[0]) <= len(tablero[i])-n and ans == False:
            
            if((figura[0][0] == "*" and tablero[i][n] == "*") or (figura[0][0] == ".")):

                recorrerFigura = 0
                recorrerTablero = i
                flag = True

                while recorrerFigura<len(figura) and recorrerTablero < len(tablero):
                    y = 0
                    posicionActual = n

                    while posicionActual<len(tablero[recorrerTablero]) and y<len(figura[recorrerFigura]) and flag == True:
                        
                        if(figura[recorrerFigura][y] == "*" and tablero[recorrerTablero][posicionActual] != "*"):
                            flag = False

                        y+=1
                        posicionActual+=1

                    if(y!=len(figura[recorrerFigura])):
                        flag = False

                    recorrerFigura+=1
                    recorrerTablero+=1

                if(recorrerFigura == len(figura) and flag == True):
                    ans = True

            n+=1        
        i+=1

    return ans

def main():

    casos = int(stdin.readline().strip())

    for i in range(casos):

        tamano = [int(x) for x in stdin.readline().split()]

        tablero = []

        for x in range(tamano[0]):

            tablero.append(stdin.readline().rstrip('\n'))

        for x in range(tamano[2]):

            figura = []
            tamanoFigura = [int(x) for x in stdin.readline().split()]

            for y in range(tamanoFigura[0]):

                figura.append(stdin.readline().rstrip('\n'))

            figura = identificarFigura(figura)
            
            if(len(figura)>0):

                if evaluarFigura(tablero, figura) == True:
                    print("Yes")
                
                else:
                    print("No")
            
            else:
                print("Yes")

        input()
        print()

main()


#https://onlinejudge.org/external/4/466.pdf
#466

from sys import stdin 

def rotar(figura):

    figuraRotada = []

    for i in range(len(figura)):

        fila = []

        for n in range(len(figura)-1,-1,-1):

            fila.append(figura[n][i])

        figuraRotada.append(fila)        
    
    return figuraRotada 

#investigando me di cuenta que las listas si son mutables cuando las tenemos en los parametros de una funcion, entonces no tengo necesidad de retornar una nueva lista, ya que solo estoy intercambiando sus filas
def espejo(figura):

    for i in range(len(figura)//2):

        figura[i], figura[len(figura)-i-1] = figura[len(figura)-i-1],figura[i]


def main():

    dimensiones = stdin.readline().strip()
    contador = 1

    while dimensiones != "":

        figura = []
        cambio = []
        ans = False 

        for i in range(int(dimensiones)):

            fila,filaCambio = stdin.readline().split()
            figura.append(list(fila)),cambio.append(list(filaCambio))

        if figura == cambio:
            print(f"Pattern {contador} was preserved.")

        else:
            
            movimientos = 0
            movimientos2 = 0

            while movimientos < 5 and ans == False:
                
                matrizAux = list(figura)

                while movimientos2 < 3 and ans ==False:

                    matrizAux = rotar(matrizAux)

                    if matrizAux == cambio:

                        ans = True

                    movimientos2+=1

                if movimientos == 1 and ans == False:

                    espejo(matrizAux)

                    if matrizAux == cambio:

                        ans = True 

                elif movimientos == 2 and ans == False:

                    movimientos2 = 0

                    espejo(matrizAux)

                    while movimientos2 < 3 and ans ==False:

                        matrizAux = rotar(matrizAux)

                        if matrizAux == cambio:

                            ans = True

                        movimientos2+=1

                movimientos+=1

            if movimientos == 1 and movimientos2 == 1 and ans == True:

                print(f"Pattern {contador} was rotated 90 degrees.")
            
            elif movimientos == 1 and movimientos2 ==2 and ans == True:

                print(f"Pattern {contador} was rotated 180 degrees.")

            elif movimientos == 1 and movimientos2 == 3 and ans == True:

                print(f"Pattern {contador} was rotated 270 degrees.")

            elif movimientos == 2 and ans == True:
                
                print(f"Pattern {contador} was reflected vertically.")
            
            elif movimientos == 3 and movimientos2 == 1 and ans == True:

                print(f"Pattern {contador} was reflected vertically and rotated 90 degrees.")

            elif movimientos == 3 and movimientos2 == 2 and ans == True:

                print(f"Pattern {contador} was reflected vertically and rotated 180 degrees.")

            elif movimientos == 3 and movimientos2 == 3 and ans == True:

                print(f"Pattern {contador} was reflected vertically and rotated 270 degrees.")
                
            else:

                print(f"Pattern {contador} was improperly transformed.")

        dimensiones = stdin.readline().strip()
        contador+=1

main()
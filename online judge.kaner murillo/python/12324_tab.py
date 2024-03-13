from sys import stdin

def fri(i,materia, listaFinal):
    
    tab = [[0 for i in range(len(listaFinal))] for x in range(len(listaFinal))]
    
    for i in range(len(listaFinal)+1):
        tab[len(listaFinal)][i] = 0

    for i in range(len(listaFinal), -1, -1):
        for j in range(len(listaFinal)+1):

            materia = j+listaFinal[i][0]
            if materia > len(listaFinal):
                materia = len(listaFinal)
            
            tab[i][j] = tab[i+1][j] + listaFinal[i][1]
            if materia:
                tab[i][j] = min(tab[i][j], tab[i][j-1] + (listaFinal[i][1]//2))
    
    return tab[0][0]

def main():
    numberTrips = int(stdin.readline().strip())
    listaViajesYmateria = []
    listaFinal = []
    while numberTrips != 0:
        
        for i in range(numberTrips):
            tiAndBi = stdin.readline().split()
            listaViajesYmateria = (int(tiAndBi[0]), int(tiAndBi[1]))
            listaFinal.append(listaViajesYmateria)
        memoria = {}
        print(fri(0,0,listaFinal))
        
        numberTrips = int(stdin.readline().strip())
        listaViajesYmateria = []
        listaFinal = []
main()
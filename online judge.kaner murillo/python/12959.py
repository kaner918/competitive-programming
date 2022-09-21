#https://onlinejudge.org/external/129/12959.pdf
#12959

from sys import stdin

partidad = [int(x) for x in stdin.readline().split()]

while partidad != []:

    jugadores = [[x+1,0] for x in range(partidad[0])]
    puntos = [int(x) for x in stdin.readline().split()]
    contador = 0

    for i in range(len(puntos)):

        jugadores[contador][1]+= puntos[i]
        contador+=1

        if contador == partidad[0]:
            contador = 0

    jugadores.sort(key=lambda x: (-x[1], -x[0]))

    print(jugadores[0][0])

    partidad = [int(x) for x in stdin.readline().split()]
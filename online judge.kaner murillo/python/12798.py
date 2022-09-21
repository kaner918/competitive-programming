#https://onlinejudge.org/external/127/12798.pdf
#12798

from sys import stdin 

partido = stdin.readline().strip()

while partido != "":

    jugadores, partidos = partido.split()
    contador = 0

    for i in range(int(jugadores)):

        juego = stdin.readline().split()

        if '0' not in juego:

            contador+=1

    print(contador)

    partido = stdin.readline().strip()

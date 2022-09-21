#https://onlinejudge.org/external/118/11805.pdf
#11805

from sys import stdin 

casos = int(stdin.readline().rstrip('\n'))

for i in range(1,casos+1):

    practica = [int(x) for x in stdin.readline().rstrip('\n').split()]

    jugadorActual = practica[1]

    for n in range(practica[2]%practica[0]):

        jugadorActual+=1

        if jugadorActual>practica[0]:
            jugadorActual = 1
    
    print(f"Case {i}: {jugadorActual}")
#https://onlinejudge.org/external/130/13012.pdf
#https://www.udebug.com/UVa/13012
#13012

from sys import stdin

respuesta = stdin.readline().strip()

while respuesta!="":

    contador = 0 
    
    rParticipantes = stdin.readline().split()

    for i in range(len(rParticipantes)):

        if rParticipantes[i]== respuesta:
            contador+=1
    
    print(contador)
    
    respuesta = stdin.readline().strip()
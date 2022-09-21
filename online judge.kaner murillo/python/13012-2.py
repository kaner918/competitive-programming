#https://onlinejudge.org/external/130/13012.pdf
#https://www.udebug.com/UVa/13012
#13012

from sys import stdin

respuesta = stdin.readline().strip()

while respuesta!="":
    
    rParticipantes = stdin.readline().split()

    print(rParticipantes.count(respuesta))
    
    respuesta = stdin.readline().strip()
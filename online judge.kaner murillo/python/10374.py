#https://onlinejudge.org/external/103/10374.pdf
#10374

from sys import stdin 

casos = int(stdin.readline())

for i in range(casos):

    stdin.readline()

    candidatos = int(stdin.readline())
    listaCandidatos = {}

    mayor = 0
    contador = 0
    nombre = ""
    candidato = ""

    for n in range(candidatos):

        nombre = stdin.readline().rstrip('\n')
        partido = stdin.readline().rstrip('\n')
            
        listaCandidatos[nombre] = [partido,0]

    votos = int(stdin.readline())

    for n in range(votos):

        candidato = stdin.readline().rstrip('\n')

        if candidato in listaCandidatos:

            listaCandidatos[candidato][1]+=1

    for n in listaCandidatos:

        if listaCandidatos[n][1] == mayor:
            contador+=1

        elif listaCandidatos[n][1] > mayor:
            mayor = listaCandidatos[n][1]
            nombre = n
            contador = 0

    if contador<1:
        print(listaCandidatos[nombre][0])
    
    else:
        print("tie")
    
    if i<casos-1:
        print()


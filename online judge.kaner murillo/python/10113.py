#https://onlinejudge.org/external/101/10113.pdf
#10113

from sys import stdin
from collections import deque

def dfs(v, buscar):

    if v != buscar:

        for u in grafo[v]:

            if visits[u[0]] == False and u[0] not in pila:

                pila.append(u[0])

                dfs(u[0], buscar)

                if len(pila) > 0 and pila[-1] == buscar:

                    return 

        if len(pila) > 0:

            visits[pila.pop()] = True

line = stdin.readline().strip()
dicIndex = {}
dicName = {}
counter = 0
grafo = {}
visits = []

while line != ".":

    lineAux = line.split()
    pila = deque()

    if True in visits:

        for n in range(len(visits)):
            visits[n] = False

    if lineAux[0] == "!":
        
        if lineAux[2] not in dicIndex:

            dicIndex[lineAux[2]] = counter
            dicName[counter] = lineAux[5]
            visits.append(False)
            counter+=1
        
        if lineAux[5] not in dicIndex:

            dicIndex[lineAux[5]] = counter
            dicName[counter] = lineAux[5]
            visits.append(False)
            counter+=1

        if dicIndex[lineAux[2]] not in grafo:

            grafo[dicIndex[lineAux[2]]] = [[dicIndex[lineAux[5]], int(lineAux[1]), int(lineAux[4])]]

        else:

            grafo[dicIndex[lineAux[2]]].append([dicIndex[lineAux[5]], int(lineAux[1]), int(lineAux[4])])
        
        if dicIndex[lineAux[5]] not in grafo:

            grafo[dicIndex[lineAux[5]]] = [[dicIndex[lineAux[2]], int(lineAux[4]), int(lineAux[1])]]
        
        else:

            grafo[dicIndex[lineAux[5]]].append([dicIndex[lineAux[2]], int(lineAux[4]), int(lineAux[1])])

    else:

        dfs(dicIndex[lineAux[1]], dicIndex[lineAux[3]])

        if len(pila) == 0:

            print(line)
            
        elif len(pila) <= 2 and len(pila) > 0:

            num1 = grafo[dicIndex[lineAux[1]]][0][1]
            num2 = grafo[dicIndex[lineAux[3]]][0][1]
            
            print(num1, num2)

            divisor  = 2

            while divisor <= num1:

                while num1 % divisor == 0 and num2 % divisor == 0:

                    num1//= divisor
                    num2//= divisor

                divisor+=1

            print(num1, lineAux[1], "=", num2, lineAux[3])
            
        else:
            
            print(pila[n])

    line = stdin.readline().strip()

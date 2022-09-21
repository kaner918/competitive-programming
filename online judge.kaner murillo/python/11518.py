#https://onlinejudge.org/external/115/11518.pdf
#11518

from sys import stdin

def dfs(v):

    visits[v] = True

    for u in range(len(grafo[v])):

        if grafo[v][u] == 1 and visits[u] == False:

            dfs(u)

cases = int(stdin.readline())

for i in range(cases):

    dominos = [int(x) for x in stdin.readline().split()]

    grafo = []
    listG = [0 for x in range(dominos[0])]

    for n in range(dominos[0]):

        grafo.append(list(listG))

    for n in range(dominos[1]):

        conection = [int(x)-1 for x in stdin.readline().split()]

        grafo[conection[0]][conection[1]] = 1

    visits = [False for x in range(dominos[0])]

    for n in range(dominos[2]):

        domino = int(stdin.readline())

        dfs(domino-1)

    counter = 0

    for n in range(dominos[0]):

        if visits[n] == True:

            counter+=1
        
    print(counter)
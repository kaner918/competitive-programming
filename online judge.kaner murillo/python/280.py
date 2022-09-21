#https://onlinejudge.org/external/2/280.pdf
#280

from sys import stdin

def dfs(v):

    visits2[v] = True

    for u in grafo[v]:

        visits[u] = True

        if visits2[u] == False:
            dfs(u)

vertex = int(stdin.readline())

while vertex != 0:
    
    grafo = [[]for _ in range(vertex)]

    list = [int(x)-1 for x in stdin.readline().split()]

    while list != [-1]:

        list.pop()
        grafo[list[0]] = list
        grafo[list[0]].pop(0)
        

        list = [int(x)-1 for x in stdin.readline().split()]

    consults = [int(x)-1 for x in stdin.readline().split()] #lectura de datos ^|.
    
    for i in range(1, consults[0]+2):

        visits2 = [False for x in range(vertex)]
        visits = [False for x in range(vertex)]

        dfs(consults[i]) 

        cad = []
        counter = 0

        for n in range(vertex):

            if visits[n] == False:

                cad.append(" "+str(n+1))
                counter+=1

        print(str(counter)+"".join(cad))

    vertex = int(stdin.readline())
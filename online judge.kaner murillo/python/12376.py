#https://onlinejudge.org/external/123/12376.pdf
#12376

from sys import stdin
from collections import deque

def bfs(position):

    cola = deque()
    cola.append(position)
    visits[position] = True
    mayor = 0
    sum = 0

    while len(cola) > 0:

        position = cola.popleft()

        for u in grafo[position]:

            if peso[u] > peso[mayor] and visits[u] == False:

                mayor = u
                position = mayor

            elif peso[u] == peso[mayor] and visits[u] == False and u<mayor:

                mayor = u
                position = mayor

        if visits[position] == False:

            visits[position] = True
            sum+=peso[position]
            cola.append(position)

        mayor = 0

    return sum, position

cases = int(stdin.readline())

for i in range(1, cases+1):

    input()
    n, m = [int(x) for x in stdin.readline().split()]

    peso = [int(x) for x in stdin.readline().split()]

    grafo = []
    visits = []

    for n in range(n):

        visits.append(False)
        grafo.append([])
    
    for n in range(m):

        conection = [int(x) for x in stdin.readline().split()]

        grafo[conection[0]].append(conection[1])
        

    sum, position = bfs(0)

    print(f"Case {i}: {sum} {position}")
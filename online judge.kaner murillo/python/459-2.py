#https://onlinejudge.org/external/4/459.pdf
#459

from sys import stdin
from collections import deque

def bfs(v):

    visits[v] = True
    cola = deque()
    cola.append(v)

    while len(cola) > 0:

        v = cola.popleft()

        for u in grafo[v]:

            if visits[u] == False:

                visits[u] = True
                cola.append(u)
    
cases = int(stdin.readline())
input()

for i in range(cases):

    letter = stdin.readline().strip()
    size = (ord(letter) - ord('A')) + 1

    visits = []
    grafo = []

    for n in range(size):

        visits.append(False)
        grafo.append([])
    
    cad = stdin.readline().strip()

    while cad != "":
        
        grafo[ord(cad[0]) - ord('A')].append(ord(cad[1]) - ord('A'))
        grafo[ord(cad[1]) - ord('A')].append(ord(cad[0]) - ord('A'))

        cad = stdin.readline().strip()

    counter = 0

    for n in range(len(visits)):

        if visits[n] == False:

            bfs(n)
            counter+=1
    
    print(counter)

    if i < cases-1:
        print()
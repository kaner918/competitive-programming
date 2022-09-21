#https://onlinejudge.org/external/11/1148.pdf
#1148

from sys import stdin
from collections import deque

def bfs(origin, destiny):

    q = deque()
    q.append(origin)
    visits[origin] = 0

    while len(q) > 0:

        v = q.popleft()

        for u in grafo[v]:

            if visits[u] == None:

                visits[u] = visits[v] + 1
                q.append(u)

                if u == destiny:

                    print(origin, destiny, visits[v])
           
cases = int(stdin.readline())

for i in range(cases):

    stdin.readline()

    size = int(stdin.readline())

    grafo = []
    visits = []

    for n in range(size):
        
        visits.append(None)
        grafo.append(set())

    for n in range(size):

        lis = deque([int(x) for x in stdin.readline().split()])
        vertex = lis.popleft()

        grafo[vertex] = set(lis)
        
    consult = [int(x) for x in stdin.readline().split()]

    bfs(consult[0], consult[1])
    #print(visits)

    if i < cases-1:
        print()
        


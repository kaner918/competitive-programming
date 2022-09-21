#https://onlinejudge.org/external/109/10959.pdf
#10959

from sys import stdin
from collections import deque

cases = int(stdin.readline())

def bfs(visits, grafo):

    q = deque()
    q.append(0)
    visits[0] = 0

    while(len(q) > 0):

        v = q.popleft()

        for u in grafo[v]:

            if visits[u] == None:
                
                visits[u] = visits[v]+1
                q.append(u)

def main():

    for i in range(cases):

        input()

        persons, conections = [int(x) for x in stdin.readline().split()]

        grafo = [[] for _ in range(persons)]
        visits = [None for _ in range(persons)]

        for n in range(conections):

            duple = [int(x) for x in stdin.readline().split()]

            if duple[0] not in grafo[duple[1]]:

                grafo[duple[0]].append(duple[1])
                grafo[duple[1]].append(duple[0])
        
        bfs(visits, grafo)

        for n in range(1,len(visits)):

            print(visits[n])
        
        if i < cases-1:
            print()

main()
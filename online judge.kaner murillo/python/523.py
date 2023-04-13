#https://onlinejudge.org/external/5/523.pdf
#523

from sys import stdin
from heapq import heappop, heappush
from collections import deque

def dijkstra(matrix_ad, costes, pre, init, finish):

    dist = [float('inf') for x in range(len(costes))]

    q = [(0, init)]
    
    dist[init] = 0

    auxNode, node, coste, weight = 0, 0, 0, 0

    while(len(q)):

        node = q[0][1]
        coste = q[0][0]

        heappop(q)

        if(node != finish and dist[node] == coste):
            
            if(node != init):

                coste+=costes[node]

            for i in range(len(matrix_ad)):

                weight = matrix_ad[node][i]
                auxNode = i

                if(weight != -1 and weight + coste < dist[auxNode]):
                    
                    dist[auxNode] = weight + coste
                    heappush(q, (dist[auxNode], auxNode))
                    pre[auxNode] = node

    return dist[finish]

def main():

    cases = int(stdin.readline())

    for i in range(cases):

        stdin.readline().strip()

        matrix_ad = []

        line = [int(x) for x in stdin.readline().split()]
        matrix_ad.append(line)
        
        for n in range(len(line)-1):
            
            line = [int(x) for x in stdin.readline().split()]
            matrix_ad.append(line)
        
        costes = [int(x) for x in stdin.readline().split()]

        case = [int(x) for x in stdin.readline().split()]

        while case != []:

            pre = [-1 for x in range(len(costes))]
            coste = dijkstra(matrix_ad, costes, pre, case[0]-1, case[1]-1)

            pre_aux = deque()
            aux = case[1]-1

            while(pre[aux] != -1):

                pre_aux.append(aux+1)
                aux = pre[aux]

            print(f"From {case[0]} to {case[1]} :")
            print(f"Path: {case[0]}", end="")

            while(len(pre_aux) > 1):
                
                aux = pre_aux.pop()
                print(f"-->{aux}", end="")

            if(len(pre_aux)):

                aux = pre_aux.pop()
                print(f"-->{aux}", end="")
            
            print()
            print(f"Total cost : {coste}")
            
            case = [int(x) for x in stdin.readline().split()]

            if case != []:
                print()
                
        if(i<cases-1):  
            print()

main()
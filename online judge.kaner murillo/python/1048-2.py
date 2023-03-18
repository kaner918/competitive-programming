#https://onlinejudge.org/external/10/1048.pdf
#1048

from sys import stdin
from heapq import heappop, heappush
graph = {}
visits = {}
travel = []
res = []

def dijkstra():

    global travel, graph, visits, res
    conj = set()
    if(travel[1] != travel[-1]):

        visits[travel[1]] = 0

    q = [(0, travel[1], 2, -1, [])]
    conj.add((travel[1], -1, 2))

    while len(q):

        coste = q[0][0]
        city = q[0][1]
        index = q[0][2]
        tique = q[0][3]
        lista = q[0][4]

        heappop(q)

        if index == len(travel) and city == travel[-1]:

            visits[city] = coste
            res = lista
            break
        
        elif city in graph:

            for i in graph[city]:
                
                if i[2] == tique or i[-1]:

                    aux_city = i[0]
                    aux_coste = coste
                    aux_index = index
                    aux_lista = list(lista)

                    if tique != i[2]:
                        aux_coste+=i[1] 
                        aux_lista.append(i[2]+1) 

                    if travel[index] == aux_city:   
                        aux_index+=1

                    aux_tuple = (aux_city, i[2], aux_index)

                    if aux_tuple not in conj:

                        conj.add(aux_tuple)
                        heappush(q, (aux_coste, aux_city, aux_index, i[2], aux_lista))       

def main():

    global travel, graph, visits, res

    travels = int(stdin.readline())
    counter1 = 1
    
    while travels:

        graph = {}
        visits = {}
        counter2 = 1

        for i in range(travels):

            tique = [int(x) for x in stdin.readline().split()]
            flag = True
            for n in range(2, len(tique)-1):

                if tique[n] in graph:

                    graph[tique[n]].append((tique[n+1], tique[0], i, flag))

                
                else:

                    graph[tique[n]] = [(tique[n+1], tique[0], i, flag)]

                visits[tique[n]] = float('inf')
                visits[tique[n+1]] = float('inf')
                flag = False
        
        cases = int(stdin.readline())

        for i in range(cases):

            res = []
            travel = [int(x) for x in stdin.readline().split()]
            dijkstra()
            print(f"Case {counter1}, Trip {counter2}: Cost = {visits[travel[-1]]}")
            print("  Tickets used:", end="")

            for n in res:

                print(f' {n}', end = "")
        
            print()
            counter2+=1
            visits[travel[-1]] = float('inf')
            visits[travel[1]] = float('inf')

        travels = int(stdin.readline())
        counter1+=1

main()
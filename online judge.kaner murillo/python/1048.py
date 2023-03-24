#1048
#https://onlinejudge.org/external/10/1048.pdf

from sys import stdin
from heapq import heappop, heappush

class State:

    def __init__(self, coste = 0, city = 0, index = 0, idTique = 0, indexTique = 0, res = []):

        self.coste = coste
        self.city = city
        self.index = index
        self.idTique = idTique
        self.indexTique = indexTique
        self.res =  res
    
    def __lt__(self, other):

        if self.coste == other.coste:

            return self.index > other.index
        
        return self.coste < other.coste

    def __str__(self):
        return f"(coste: {self.coste}, city: {self.city}, position tique: {self.indexTique}, index: {self.index}, idTique: {self.idTique})"
    
def dijkstra(graph, travel):

    visits = set()
    q = []

    for i in range(len(graph)):

        if(graph[i][2] == travel[1]):

            heappush(q, State(graph[i][0], travel[1], 1, i, 1, [i+1]))
            visits.add((1, 1, i))
            
    ans = State()

    while len(q):

        state = heappop(q)
        #print(state)
        
        if(state.index == len(travel)):

            ans = state 
            break
        
        else:
                
            if(state.indexTique < len(graph[state.idTique])-1):

                state.indexTique+=1

                if(state.index < len(travel) and graph[state.idTique][state.indexTique] == travel[state.index]):
                    
                    state.index+=1

                if((state.indexTique, state.index, state.idTique) not in visits):
                    
                    state.city = graph[state.idTique][state.indexTique-1] 
                    heappush(q, state)
                    visits.add((state.indexTique, state.index, state.idTique))

                    city = graph[state.idTique][state.indexTique]

                    for i in range(len(graph)):

                        if graph[i][2] == city:

                            res = list(state.res)
                            res.append(i+1)
                            heappush(q, State(state.coste + graph[i][0], city, state.index, i, 1, res))

    return ans

def main():

    ite = int(stdin.readline())
    counter1 = 1
    
    while ite:

        graph = []
        travel = []
        counter2 = 1

        for i in range(ite):

            graph.append([int(x) for x in stdin.readline().split()])
        
        cases = int(stdin.readline())

        for i in range(cases):

            travel = [int(x) for x in stdin.readline().split()]
            
            ans = dijkstra(graph, travel)
        
            print(f"Case {counter1}, Trip {counter2}: Cost = {ans.coste}")
            print("  Tickets used:", end="")

            for n in ans.res:

                print(f' {n}', end = "")
        
            print()
            counter2+=1
        
        counter1+=1
        ite = int(stdin.readline())

main()
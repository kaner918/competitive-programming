#https://onlinejudge.org/external/116/11635.pdf
#11635

from sys import stdin
from heapq import heappush, heappop

graph = []
hotels = []

class State:

    def __init__(self, coste = 0, time = 0, city = 0):

        self.coste = coste
        self.time = time
        self.city = city
    
    def __lt__(self, other):

        if self.coste == other.coste:

            return self.city > other.city
        
        return self.coste < other.coste

def dijkstra():

    q = []
    visits = set()

    heappush(q, State(0, 0, 0))
    visits.add((0, 0, 0))
    finish = len(graph)-1

    state = State()

    while len(q):
        
        state = heappop(q)

        if state.city == finish:

            return state.coste

        for i in graph[state.city]:

            if state.city in hotels:

                if (state.coste + 1, i[1], i[0]) not in visits:

                    heappush(q, State(state.coste + 1, i[1], i[0]))
                    visits.add((state.coste + 1, i[1], i[0]) )

    
            if state.time + i[1] <= 600:

                if (state.coste, state.time + i[1], i[0]) not in visits:
                    
                    heappush(q, State(state.coste, state.time + i[1], i[0]))
                    visits.add((state.coste, state.time + i[1], i[0]))

    return -1

def main():

    nodes = int(stdin.readline())

    while nodes:
        
        global graph, hotels

        graph = [[] for _ in range(nodes)]
        hotels = [int(x) for x in stdin.readline().split()]
        hotels[0] = None

        edges = int(stdin.readline())

        for i in range(edges):

            conection = [int(x) for x in stdin.readline().split()]

            if(conection[2] <= 600):

                graph[conection[0]-1].append((conection[1]-1, conection[2]))

        print(dijkstra())

        nodes = int(stdin.readline())

main()
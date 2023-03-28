#https://onlinejudge.org/external/101/10187.pdf
#10187

from sys import stdin
from heapq import heappop, heappush

graph = {}

class State:

    def __init__(self, coste = 0, time = 0, city = ""):

        self.coste = coste
        self.time = time
        self.city = city
    
    def __lt__(self, other):

        """ if(self.coste == other.coste):
            return self.time < other.time """
        return self.coste < other.coste

def dijkstra(init, finish):

    global graph
    q = [State(0, 18, init)]
    conj = set((18, 18, init))
    state = State()
    ans = float('inf')

    while len(q):

        state = heappop(q)

        if(state.city == finish and state.coste < ans):

            return state.coste
        
        if (18, 18, state.city) not in conj:
            
            conj.add((18, 18, state.city))
            heappush(q, State(state.coste+1, 18, state.city))

        if state.city in graph:

            for i in graph[state.city]:

                flag = False

                if(i[1] == state.time):
                    flag = True
                
                elif (state.time > 17 and state.time < i[1]):
                    flag = True
                
                elif (state.time > 17 and i[1] < 7):
                    flag = True
                    
                elif (state.time < 7 and i[1] < 7 and  state.time < i[1]):
                    flag = True
                
                if (i[1], i[2], i[0]) not in conj and flag:

                    conj.add((i[1], i[2], i[0]))
                    heappush(q, State(state.coste, i[2], i[0]))

    return ans

def main():

    cases = int(stdin.readline())
    global graph

    for i in range(cases):

        graph = {}

        conections = int(stdin.readline())

        for n in range(conections):

            conection = stdin.readline().split()
            aux = int(conection[2]) + int(conection[3])

            if(aux > 24):
                aux -=24
            
            if((int(conection[2]) > 17 or int(conection[2]) < 6) and (aux >17 or aux < 7) and int(conection[3]) <= 12):

                if conection[0] not in graph:

                    graph[conection[0]] = [(conection[1], int(conection[2]), aux)]
                
                else:
                    
                    graph[conection[0]].append((conection[1], int(conection[2]), aux))

        init,finish = stdin.readline().split()

        print(f"Test Case {i+1}.")

        ans = dijkstra(init, finish)

        if ans == float('inf'):

            print("There is no route Vladimir can take.")
        
        else:

            print(f"Vladimir needs {ans} litre(s) of blood.")
        
main()
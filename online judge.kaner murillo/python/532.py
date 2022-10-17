#https://onlinejudge.org/external/5/532.pdf
#532

from sys import stdin
from collections import deque

arrRow = [-1, 1, 0, 0]
arrColum = [0 , 0, -1, 1]
arrDime = [1, -1]

class State:

    def __init__(self, row, colum, dime):
        
        self.row = row
        self.colum = colum
        self.dime = dime

def bfs(rowInit, columInit, dimeInit, rowFinish, columFinish, dimeFinish, graph, visits):

    queue = deque()
    queue.append(State(rowInit, columInit, dimeInit))

    visits[dimeInit][rowInit][columInit] = 0

    while len(queue) > 0:

        auxState = queue.popleft()
        
        if auxState.row == rowFinish and auxState.colum == columFinish and auxState.dime == dimeFinish:

            return visits[auxState.dime][auxState.row][auxState.colum]

        for n in range(4):

            auxRow = auxState.row + arrRow[n]  
            auxColum = auxState.colum + arrColum[n]  

            if ((auxState.dime > -1 and auxState.dime<len(graph)) and auxRow > -1 and auxColum >-1) and (auxRow<len(graph[-1]) and auxColum < len(graph[-1][-1])) and graph[auxState.dime][auxRow][auxColum] != "#" and visits[auxState.dime][auxRow][auxColum] == -1:

                queue.append(State(auxRow, auxColum, auxState.dime))
                visits[auxState.dime][auxRow][auxColum] = visits[auxState.dime][auxState.row][auxState.colum] + 1

        for i in range(2):

            auxDime = auxState.dime + arrDime[i]   

            if ((auxDime > -1 and auxDime<len(graph)) and visits[auxDime][auxState.row][auxState.colum] == -1 and graph[auxDime][auxState.row][auxState.colum] != "#"):

                queue.append(State(auxState.row, auxState.colum, auxDime))
                visits[auxDime][auxState.row][auxState.colum] = visits[auxState.dime][auxState.row][auxState.colum] + 1

    return -1

def main():

    dime = [int(x) for x in stdin.readline().split()]

    while dime != [0, 0, 0]:

        conjGraph = []
        conjVisits = []

        dimeInit = None
        dimeFinish = None 
        rowInit = None
        columInit = None
        rowFinish = None
        columFinish = None

        for i in range(dime[0]):

            graph = []
            visits = []

            for n in range(dime[1]):

                graph.append(stdin.readline().rstrip('\n'))
                visits.append([-1 for x in range(dime[2])])

                if "S" in graph[-1]:

                    for m in range(len(graph[-1])):

                        if graph[-1][m] == "S":
                            
                            rowInit = n
                            columInit = m
                            dimeInit = i
                
                if "E" in graph[-1]:

                    for m in range(len(graph[-1])):

                        if graph[-1][m] == "E":

                            rowFinish = n
                            columFinish = m
                            dimeFinish = i

            conjGraph.append(graph)
            conjVisits.append(visits)

            stdin.readline()

        ans = bfs(rowInit, columInit, dimeInit, rowFinish, columFinish, dimeFinish, conjGraph, conjVisits)

        if ans != -1:

            print(f"Escaped in {ans} minute(s).")
        
        else:

            print("Trapped!")

        dime = [int(x) for x in stdin.readline().split()]

main()
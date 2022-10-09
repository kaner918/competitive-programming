#https://onlinejudge.org/external/6/627.pdf
#627

from sys import stdin
from collections import deque

def bfs(routerInit, routeFinish, graph, visits):

    queue = deque()

    if routerInit > -1 and routerInit < len(graph):

        queue.append(routerInit)
        visits[routerInit].append(str(routerInit+1))
    
    while len(queue) > 0:

        auxRouter = queue.popleft()
        
        if auxRouter == routeFinish:

            print("".join(visits[auxRouter]))
            return 0

        for i in graph[auxRouter]:

            if visits[i] == []:

                visits[i] = list(visits[auxRouter])
                visits[i].extend(" ")
                visits[i].extend(str(i+1))

                queue.append(i)

    return -1




def main():
    
    routers = stdin.readline()
    print("-----")

    while routers != "":
        
        graph = []
        visits = []

        for i in range(int(routers)):

            line = stdin.readline().rstrip('\n').split(",")
            lis = []

            if line[0][-1] == "-":

                graph.append([])
            
            else:
                
                auxLine = line[0].split("-")

                lis.append(int(auxLine[-1])-1)

                for n in range(1, len(line)):

                    if(line[n] != ""):

                        lis.append(int(line[n])-1)

                graph.append(lis)

            visits.append([])

        consults = int(stdin.readline())

        for i in range(consults):

            consult = [int(x) for x in stdin.readline().split()]

            ans = bfs(consult[0]-1, consult[1]-1, graph, visits)

            if ans == -1:

                print("connection impossible")

            visits = [[] for x in range(int(routers))]

        routers = stdin.readline()

        if routers != "":

            print("-----")
main()
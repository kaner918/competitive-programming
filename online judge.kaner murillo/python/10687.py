#https://onlinejudge.org/external/106/10687.pdf
#10687

from sys import stdin
from math import sqrt

def dfs(visits, graph, node):

    ans = 1
    visits[node] = True

    for i in graph[node]:

        if i and not visits[i[0]]:
            ans+= dfs(visits, graph, i[0])
    
    return ans

def compare(dist, graph, i, j):

    if not len(graph[i]):

        graph[i].append((j, dist))
        graph[i].append(None)

    else:
        
        if dist < graph[i][0][1]:
            
            graph[i][0], graph[i][1] = (j, dist), graph[i][0]
            
        else:

            if graph[i][1] == None:

                graph[i][1] = (j, dist)

            else:

                if dist < graph[i][1][1]:
            
                    graph[i][1] = (j, dist)

def main():

    size = int(stdin.readline())
    visits = [False for _ in range(1001)]
    aux_points = []

    while size:

        while len(aux_points) < size*2:

            aux_points.extend([int(x) for x in stdin.readline().split()])

        init_x = aux_points[0]
        init_y = aux_points[1]
        init = None
        points = []
        graph = [[] for _ in range(1001)]

        for i in range(0, size*2, 2):
            points.append((aux_points[i], aux_points[i+1]))

        points.sort(key=lambda x:(x[0], x[1]))
        
        for i in range(size):
            
            visits[i] = False

            if points[i][0] == init_x and points[i][1] == init_y:
                init = i

            for j in range(i+1, size):
                
                dist = sqrt((points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1])**2)
               
                compare(dist, graph, i, j)
                compare(dist, graph, j, i)
          
        if dfs(visits, graph, init) == size:
            print("All stations are reachable.")
        
        else:
            print("There are stations that are unreachable.")

        size = int(stdin.readline())
        aux_points = []

main()

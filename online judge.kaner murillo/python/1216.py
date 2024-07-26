#https://onlinejudge.org/external/12/1216.pdf
#1216

from sys import stdin
from heapq import heappop, heappush
from math import ceil, sqrt

def prim(graph):

    dist = [float('inf') for i in range(len(graph))]
    visits = [0 for i in range(len(graph))]
    q = [(0, 0)]
    dist[0] = 0

    while len(q):

        point = heappop(q) 
        visits[point[1]] = 1

        if dist[point[1]] == point[0]:
            for i in range(len(graph)):
                if i != point[1]:
                    weight = ceil(sqrt(pow(graph[point[1]][0]-graph[i][0], 2) + pow(graph[point[1]][1]-graph[i][1], 2)))
                    if not visits[i] and weight < dist[i]:
                        dist[i] = weight
                        heappush(q, (weight, i))

    return dist
                  
def main():

    cases = int(stdin.readline())

    for i in range(cases):

        receiver = int(stdin.readline())
        receiver-=1
        points = []
        point = [int(x) for x in stdin.readline().split()]

        while point[0] != -1:
            points.append(point)
            point = [int(x) for x in stdin.readline().split()]
        
        dist = prim(points)
        dist.sort(key=lambda x: -x)
        print(dist[receiver])
        
main()
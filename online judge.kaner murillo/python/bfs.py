from sys import stdin
from collections import deque

def bfs(graph, visits, node):



def main():

    vertex = int(stdin.readline())

    #vertex = 4
    #[[],[],[],[]]
    graph = [[] for i in range(vertex)] 
    visits = [-1 for i in range(vertex)]

    aristas = int(stdin.readline())

    for i in range(aristas):

        node1, node2 = [int(x) for x in stdin.readline().split()]

        if node2-1 not in graph[node1-1]:

            graph[node1-1].append(node2-1)
            graph[node2-1].append(node1-1)
#https://onlinejudge.org/external/107/10765.pdf
#10756

from sys import stdin, setrecursionlimit

setrecursionlimit(1000000)
visits = [-1 for _ in range(10002)]
fathers = [-1 for _ in range(10002)]
low = [-1 for _ in range(10002)]
childrens = [0 for _ in range(10002)]
index = 0

def tarjan(graph, dic, node):
    global index, visits, fathers, childrens, low

    visits[node] = index
    low[node] = index
    index+=1

    for i in graph[node]:

        if visits[i] == -1:
            
            fathers[i] = node
            childrens[node]+=1
            tarjan(graph, dic, i)
            low[node] = min(low[node], low[i])

            if fathers[node] != -1 and low[i] >= visits[node]:
                dic[node]+=1

        elif fathers[node] != i:
            low[node] = min(low[node], visits[i])
    
    if fathers[node] == -1:
        dic[node] = childrens[node]

        if(not childrens[node]):
            dic[node] = 1

def main():

    global index, visits, fathers, childrens, low
    nodes, candidates = [int(x) for x in stdin.readline().split()]

    while nodes != 0 or candidates != 0:

        graph = [[] for _ in range(nodes)]
        dic = {}
        index = 1
        for i in range(nodes):
            visits[i] = -1
            fathers[i] = -1
            low[i] = -1
            childrens[i] = 0
            dic[i] = 1

        a, b = [int(x) for x in stdin.readline().split()]

        while a != -1 or  b != -1:

            graph[a].append(b)
            graph[b].append(a)

            a, b = [int(x) for x in stdin.readline().split()]

        for i in range(nodes):

            if visits[i] == -1:
                tarjan(graph, dic, i)

        aux = []

        for i in dic:
            aux.append([i, dic[i]])

        aux.sort(key=lambda x: (-x[1], x[0]))

        for i in range(candidates):
            print(f"{aux[i][0]} {aux[i][1]}")
        print()

        nodes, candidates = [int(x) for x in stdin.readline().split()]

main()
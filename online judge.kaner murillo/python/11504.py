#https://onlinejudge.org/external/115/11504.pdf
#11504

from sys import stdin, setrecursionlimit

setrecursionlimit(10000000)

visits = []
indexComponent = []
tps = []
graph = []
indexTps = 0
indexC = 0

def dfs(domino, dominos, visits):

    visits[domino] = True

    for i in range(len(dominos[domino])):

        if(visits[dominos[domino][i]]) == False:

            dfs(dominos[domino][i], dominos, visits)

def kosarajuAux(node):

    global visits, graph, tps, indexTps
    if(not visits[node]):
        visits[node] = 1
        for i in graph[node]:

            kosarajuAux(i)

        tps[indexTps] = node
        indexTps-=1

def asing(u, v):
    
    global graph, indexComponent

    indexComponent[u] = v

    for i in graph[u]:

        if indexComponent[i] == -1:
            asing(i, v)

def kosaraju(dominos):

    global visits, indexComponent, tps, indexTps, indexC

    for i in range(dominos):
        kosarajuAux(i)

    for i in range(dominos):

        if indexComponent[tps[i]] == -1:
            indexC+=1
            asing(tps[i], tps[i])

def main():

    cases = int(stdin.readline())
    global visits, indexComponent, tps, indexTps, indexC, graph

    for i in range(cases):

        dominos, conections = [int(x) for x in stdin.readline().split()]

        indexTps = dominos-1
        indexC = 0
        visits = [0 for x in range(dominos)]
        indexComponent = [-1 for x in range(dominos)]
        tps = [-1 for x in range(dominos)]
        graph = [[] for x in range(dominos)]

        for i in range(conections):

            a, b = [int(x)-1 for x in stdin.readline().split()]
            graph[a].append(b)
            graphT[b].append(a)

        kosaraju(dominos)

        print(indexC)

main()
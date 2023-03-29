#https://onlinejudge.org/external/128/12878.pdf
#12878

from sys import stdin
from heapq import heappop, heappush

graph = []
edge = {}
pre = []

def dijkstra():

    global graph, edge, pre

    res = []
    visits = [float('inf') for x in range(len(graph))]
    pre = [-1 for x in range(len(graph))]
    q = [(0, 0)]
    visits[0] = 0
    node = coste = weight = auxNode = 0 
    finish = len(graph) - 1

    while len(q):

        coste = q[0][0]
        node = q[0][1]

        heappop(q)

        if coste == visits[node]:

            for i in range(len(graph[node])):

                auxNode = graph[node][i]
                weight = edge[(node, auxNode)][0]

                if auxNode == finish:

                    if(coste + weight < visits[auxNode]):

                        res = [node]
                        visits[auxNode] = coste + weight

                    elif(coste + weight == visits[auxNode]):

                        res.append(node)

                else:          

                    if((coste + weight < visits[auxNode])):

                        visits[auxNode] = coste + weight
                        pre[auxNode] = node
                        heappush(q, (visits[auxNode], auxNode))

    return res

def main():

    case = [int(x) for x in stdin.readline().split()]

    global graph, edge, pre

    while case != []:

        graph = [[] for _ in range(case[0])]
        edge = {} #implementacion de una funcion de peso
        pre = []
        
        for i in range(case[1]):

            conection = [int(x) for x in stdin.readline().split()]
            aux = (conection[0], conection[1])
            aux2 = (conection[1], conection[0])

            if(aux not in edge):

                edge[aux] = [conection[2], 0]
                edge[aux2] = [conection[2], 0]
                graph[conection[0]].append(conection[1])
                graph[conection[1]].append(conection[0])

            else:

                if(edge[aux][0] > conection[2]):

                    edge[aux] = [conection[2], 0]
                    edge[aux2] = [conection[2], 0]
                
                elif (edge[aux][0] == conection[2]):
                    
                    edge[aux][1]+=conection[2]
                    edge[aux2][1]+=conection[2]
        
        sum_path = 0
        res = dijkstra()

        for i in range(len(res)):

            sum_path+= edge[(case[0]-1, res[i])][1] +edge[(case[0]-1, res[i])][0]
            aux = res[i]

            while pre[aux] != -1:

                sum_path+= edge[(aux, pre[aux])][1] + edge[(aux, pre[aux])][0]
                aux = pre[aux]

        print(sum_path * 2)
        
        case = [int(x) for x in stdin.readline().split()]

main()
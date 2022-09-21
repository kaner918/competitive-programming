
from collections import deque 
def dfs(v):

    visits[v] = True
    print(v)
    
    for u in grafo[v]:

        if visits[u] == False:

            dfs(u)

def bfs(vI):

    cola = deque()
    cola.append(vI)
    higer = 0
    visits[vI] = 0

    while len(cola) > 0:

        vI = cola.popleft()
        if visits[vI] > higer:

            higer = visits[vI]

        for u in grafo[vI]:

            if visits[u] == None:

                cola.append(u)
                visits[u] = visits[vI] + 1

    return higer

grafo = [[1], [2,4,0], [1,3], [2,4,8], [1,3,5,8], [4,6,7], [5], [5], [4,3,9], [8]]
matriz = []

mayor = 0

visits = [None for _ in range(len(grafo))]

print(bfs(0))
matriz.append(visits)

for n in visits:

    if n > mayor:

        mayor = n

radio = (mayor+1)//2





    

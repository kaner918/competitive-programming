#https://onlinejudge.org/external/101/10113.pdf
#10113

from sys import stdin
from collections import deque

coste_b, coste_b, coste_c = 0, 0, 0

def bfs(name_init, name_finish, graph, visits):

    q = deque()
    q.append((name_init, 1, 0))
    visits[name_init] = True
    global coste_a, coste_b, coste_c
    while(len(q)):

        aux_item = q.popleft()
        print(aux_item)

        for i in graph[aux_item[0]]:

            if i[0] == name_finish:

                coste_a = aux_item[1]
                coste_b = i[1]
                coste_c = i[2]

                return True

            elif not visits[i[0]]:
                
                visits[i[0]] = True

                if aux_item[2]:
                    q.append((i[0], (aux_item[1] * i[2])//i[1], 1))

                else:
                    q.append((i[0], (i[2]), 1))

    return False


def main():

    consult = stdin.readline().split()
    graph = {}
    visits = {}
    global coste_a, coste_b, coste_c

    while consult[0] != '.':

        if consult[0] == '!':

            if consult[2] not in graph: #first coste A and then coste B

                visits[consult[2]] = False
                graph[consult[2]] = [(consult[5], int(consult[1]), int(consult[4]))]
            
            else:
                
                graph[consult[2]].append((consult[5], int(consult[1]), int(consult[4])))

            if consult[5] not in graph: #first coste A and then coste B

                visits[consult[5]] = False
                graph[consult[5]] = [(consult[2], int(consult[4]), int(consult[1]))]
            
            else:
                
                graph[consult[5]].append((consult[2], int(consult[4]), int(consult[1])))

        else:

            print(graph)
            
            if bfs(consult[1], consult[3], graph, visits):
                

                print(f"{consult[1]} {coste_a} = {coste_b} {consult[3]}")
            else:

                print(f"? {consult[1]} = ? {consult[3]}")

        consult = stdin.readline().split()

main()
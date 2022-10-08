#https://onlinejudge.org/external/9/924.pdf
#924

from sys import stdin
from collections import deque

def bfs(employee, graph, visits):

    queue = deque()
    queue.append(employee)
    visits[employee] = 1
    higer = 0
    day = 0

    while len(queue) > 0:

        auxEmployee = queue.popleft()
        counter = 0
        
        if len(graph[auxEmployee]) > 1:

            for i in range(1, len(graph[auxEmployee])):

                if visits[graph[auxEmployee][i]] == -1:

                    visits[graph[auxEmployee][i]] = visits[auxEmployee] + 1 
                    counter+=1
                    queue.append(graph[auxEmployee][i])
        
        if counter > higer:

            higer = counter
            day = visits[auxEmployee]
    
    print(higer, day)

def main():

    employees = int(stdin.readline())
    visits = []
    graph = []

    for i in range(employees):
        
        graph.append([int(x) for x in stdin.readline().split()])
        visits.append(-1)
    
    cases = int(stdin.readline())

    for i in range(cases):

        employee = int(stdin.readline())

        if len(graph[employee]) > 1:

            bfs(employee, graph, visits)

        else:

            print(0)
        
        visits = [-1 for x in range(employees)]

main()
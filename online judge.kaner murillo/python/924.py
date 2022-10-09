#https://onlinejudge.org/external/9/924.pdf
#924

from sys import stdin
from collections import deque

def bfs(employee, graph, visits):

    queue = deque()
    queue.append(employee)
    queue.append(-1)
    auxEmployee2 = 0
    visits[employee] = 1
    higer = 0
    counter = 0
    negative = 0
    day = 0
    day2 = 1

    while len(queue) > 0:

        auxEmployee = queue.popleft()

        if auxEmployee < 0 and len(queue) > 0:
            
            if counter > higer:

                higer = counter
                day = day2

            counter = 0
            day2+=1
            queue.append(-1)
        
        elif auxEmployee >= 0:
            
            for i in graph[auxEmployee]:

                if visits[i] == -1:

                    visits[i] = visits[auxEmployee] + 1 
                    auxEmployee2 = visits[i]
                    counter+=1
                    negative = visits[auxEmployee]
                    queue.append(i)
    
    print(higer, day)

def main():

    employees = int(stdin.readline())
    visits = []
    graph = []

    for i in range(employees):
        
        graph.append([int(x) for x in stdin.readline().split()])
        graph[-1].pop(0)
        visits.append(-1)
    
    cases = int(stdin.readline())

    for i in range(cases):

        employee = int(stdin.readline())

        if len(graph[employee]) > 0:

            bfs(employee, graph, visits)

        else:

            print(0)
        
        visits = [-1 for x in range(employees)]

main()
#821
#https://onlinejudge.org/external/8/821.pdf

from sys import stdin
from collections import deque

sums = 0
counter = 0 #global variable

def bfs(init, visits, graph):
    
    queue = deque()
    queue.append(init)
    visits[init] = 0
    global sums
    global counter

    while len(queue) > 0:

        aux = queue.popleft()

        for i in graph[aux]:

            if visits[i] == -1:

                queue.append(i)
                visits[i] = visits[aux] + 1
                sums+=visits[i]
                counter+=1

def main():

    line_input = [int(x)-1 for x in stdin.readline().split()]

    global sums
    global counter

    counter2 = 1 #cases

    while line_input != [-1, -1]:

        graph = {}
        visits = {}
        sums = 0
        counter = 0

        for i in range(0, len(line_input)-2, 2):

            if line_input[i] not in graph:

                graph[line_input[i]] = [line_input[i+1]]
            
            else:

                graph[line_input[i]].append(line_input[i+1])

            if line_input[i] not in visits:

                visits[line_input[i]] = -1
            
            if line_input[i+1] not in visits:

                visits[line_input[i+1]] = -1

        for i in graph:
            
            bfs(i, visits, graph)

            for n in visits:

                visits[n] = -1

        print(f"Case %d: average length between pages = %.3f clicks" % (counter2, sums/counter))

        line_input = [int(x)-1 for x in stdin.readline().split()]
        counter2+=1

main()
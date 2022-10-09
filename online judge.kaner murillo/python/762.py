#https://onlinejudge.org/external/7/762.pdf
#762

from sys import stdin
from collections import deque

def bfs(cityInit, cityFinish, graph, name, visits):

    queue = deque()

    if cityInit in name:

        queue.append(cityInit)
        visits[name[cityInit]].append(cityInit)

    while len(queue) > 0:

        auxCity = queue.popleft()

        if auxCity == cityFinish:

            for n in range(len(visits[name[auxCity]])-1):

                print(visits[name[auxCity]][n], visits[name[auxCity]][n+1])

            return 0 

        for i in graph[name[auxCity]]:

            if visits[name[i]] == []:

                visits[name[i]].extend(visits[name[auxCity]])
                visits[name[i]].append(i)

                queue.append(i)

    return -1 


def main():

    cities = stdin.readline()

    while len(cities) > 0:

        graph = {}
        name = {}
        counter = 0
        
        for i in range(int(cities)):

            pair = stdin.readline().split()

            if pair[0] not in name:

                name[pair[0]] = counter
                graph[counter] = [pair[1]]
                counter+=1
            
            elif pair[1] not in graph[name[pair[0]]]:

                graph[name[pair[0]]].append(pair[1])

            if pair[1] not in name:

                name[pair[1]] = counter
                graph[counter] = [pair[0]]
                counter+=1
            
            elif pair[0] not in graph[name[pair[1]]]:

                graph[name[pair[1]]].append(pair[0])
        
        pair = stdin.readline().split()
        visits = [[] for x in range(counter)]

        #print(visits)
        ans = bfs(pair[0], pair[1], graph, name, visits)

        if ans == -1:

            print("No route")

        cities = stdin.readline()
        
        if len(cities) > 0:

            cities = stdin.readline()
            print()

main()
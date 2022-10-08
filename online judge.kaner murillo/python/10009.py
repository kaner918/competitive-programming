#https://onlinejudge.org/external/100/10009.pdf
#10009

from re import A
from sys import stdin
from collections import deque


def bfs(cityInit, cityFinish, iGraph, iNames, visits):

    queue = deque()
    queue.append(cityInit)
    flag = False

    visits[iNames[cityInit]] = cityInit[0]

    while len(queue) > 0 and flag == False:

        auxCity = queue.popleft()

        if auxCity == cityFinish:

            print(visits[iNames[auxCity]])
            flag = True 
        
        for i in iGraph[iNames[auxCity]]:

            if visits[iNames[i]] == "":

                visits[iNames[i]] = visits[iNames[auxCity]] + i[0]
                queue.append(i)

def main():

    cases = int(stdin.readline())

    for i in range(cases):

        stdin.readline().strip()

        counter = 0
        iGraph = {}
        iNames = {}
        visits = []

        roads, consults = [int(x) for x in stdin.readline().split()]

        for n in range(roads):

            auxRoad = stdin.readline().split()

            if auxRoad[0] not in iNames:

                iNames[auxRoad[0]] = counter
                iGraph[counter] = [auxRoad[1]]
                visits.append("")
                counter+=1
            
            else:

                iGraph[iNames[auxRoad[0]]].append(auxRoad[1])

            if auxRoad[1] not in iNames:

                iNames[auxRoad[1]] = counter
                iGraph[counter] = [auxRoad[0]]
                visits.append("")
                counter+=1
            
            else:

                iGraph[iNames[auxRoad[1]]].append(auxRoad[0])
        
        for n in range(consults):

            cityInit, cityFinish = stdin.readline().split()

            bfs(cityInit, cityFinish, iGraph, iNames, visits)

            visits = ["" for x in range(counter)]

        if i<cases-1:

            print()

main()
#https://onlinejudge.org/external/5/540.pdf
#540

from sys import stdin
from collections import deque

cTeams = int(stdin.readline())
counter = 1

while cTeams != 0:

    print(f"Scenario #{counter}")

    cola = deque()
    dic = {}
    dic2 = {}

    for i in range(cTeams):

        teams = stdin.readline().split()
        dic[i] = deque()

        for n in range(1, int(teams[0])+1):

            dic2[int(teams[n])] = i

    cad = stdin.readline().split()

    while cad[0] != "STOP":

        if cad[0] == "ENQUEUE":

            team  = dic2[int(cad[1])]

            if team not in cola:

                cola.append(team)
                dic[team].append(int(cad[1]))
                
            else:

                dic[team].append(int(cad[1]))
            
            #print(cola)

        else:

            print(dic[cola[0]][0])
            dic[cola[0]].popleft()

            if len(dic[cola[0]]) == 0:

                cola.popleft()            

        cad = stdin.readline().split()

    print()
    counter+=1
    
    cTeams = int(stdin.readline())



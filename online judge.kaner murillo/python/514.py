#https://onlinejudge.org/external/5/514.pdf
#514

from sys import stdin
from collections import deque

cantidad = int(stdin.readline().strip())

while cantidad!= 0:

    vagones = [int(x) for x in stdin.readline().split()]

    while vagones != [0]:

        i = 0
        n = 1
        estacion = deque()
        ans = True

        while(n<len(vagones)+1):

            estacion.append(n)

            if(estacion[-1] == vagones[i]):

                while len(estacion) != 0 and estacion[-1] == vagones[i]:

                    estacion.pop()
                    i+=1
            
            n+=1


        while len(estacion)!= 0 and ans == True:

            if(estacion[-1] == vagones[i]):

                estacion.pop()
                i+=1

            else:
                ans = False

        
        if ans == True:

            print("Yes")
        
        else:
            print("No")

        vagones = [int(x) for x in stdin.readline().split()]

    print()

    cantidad = int(stdin.readline().strip())


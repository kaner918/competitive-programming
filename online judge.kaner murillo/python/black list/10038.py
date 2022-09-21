#https://onlinejudge.org/external/100/10038.pdf
#10038

from sys import stdin 

jumpers = [int(x) for x in stdin.readline().split()]

while jumpers != []:

    ans = True 
    n = 1

    distancias = []

    while n < jumpers[0]:
        
        distancias.append(abs(jumpers[n] - jumpers[n+1])) 
            
        n+=1
    
    n = 0

    while n < jumpers[0]-1 and ans == True:

        if distancias[n] != n+1:

            ans = False

        n+=1

    if ans == True:
        print("Jolly")
    
    else:
        print("Not jolly")

    jumpers = [int(x) for x in stdin.readline().split()]
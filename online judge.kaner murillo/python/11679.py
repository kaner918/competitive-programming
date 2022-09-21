#https://onlinejudge.org/external/116/11679.pdf
#https://www.udebug.com/UVa/11679
#11679

from sys import stdin

bancos,operaciones = [int(x) for x in stdin.readline().split()]

while bancos!= 0 and operaciones != 0:

    reservas = [int(x) for x in stdin.readline().split()]
    i = 0
    ans = True

    while i<operaciones:

        operacion = [int(x) for x in stdin.readline().split()]
        
        reservas[operacion[1]-1]+=operacion[2]
        reservas[operacion[0]-1]-=operacion[2]

        i+=1

    i = 0
    
    while i<bancos and ans ==True:

        if reservas[i]<0:
            ans = False

        i+=1

    if ans == True:
        print("S")

    else:
        print("N")


    bancos,operaciones = [int(x) for x in stdin.readline().split()]
#https://onlinejudge.org/external/115/11559.pdf
#11559

from sys import stdin

planeacion = [int(x) for x in stdin.readline().split()]

while planeacion != []:

    ans = False
    menor = planeacion[1]

    for n in range(planeacion[2]):
        
        costo = int(stdin.readline().strip())

        hotel = [int(x) for x in stdin.readline().split()]

        for i in range(planeacion[3]):

            if hotel[i] >= planeacion[0] and planeacion[0]*costo < menor:

                menor =  planeacion[0]*costo
                ans = True

    if ans == True:

        print(menor)

    else:
        
        print("stay home")
            

    planeacion = [int(x) for x in stdin.readline().split()]
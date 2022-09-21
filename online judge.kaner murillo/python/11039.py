#https://onlinejudge.org/external/110/11039.pdf
#11039

from sys import stdin 

cases = int(stdin.readline().strip())

for i in range(cases):

    building = []
    flats = int(stdin.readline().strip())

    for n in range(flats):
        
        building.append(int(stdin.readline().strip()))

    if flats == 0:
        print(0)

    else:
        
        contador = 1
        building.sort(key= lambda x: -abs(x))

        for n in range(flats-1):

            if (building[n] < 0 and building[n+1] >0 or building[n] > 0 and building[n+1]<0) and abs(building[n]) > abs(building[n+1]):
                contador+=1
        
        print(contador)


#https://onlinejudge.org/external/101/10189.pdf
#10189

from sys import stdin

row, colum = [int(x) for x in stdin.readline().split()]
arrRow = [1, 1, 0, -1, -1, -1, 0, 1]
arrColum = [0, -1, -1, -1, 0, 1, 1, 1]
counter = 1

while row != 0 or colum != 0:

    map1 = []
    mapAux = []

    for i in range(row):

        map1.append(stdin.readline().rstrip('\n'))
        mapAux.append([0 for x in range(colum)])

    for i in range(row):

        for n in range(colum):

            if map1[i][n] == "*":

                for m in range(8):

                    auxRow = i + arrRow[m]
                    auxColum = n + arrColum[m]

                    if (auxRow > -1 and auxColum > -1) and (auxRow < row and auxColum < colum) and map1[auxRow][auxColum] != "*":

                        mapAux[auxRow][auxColum]+=1

    print(f"Field #{counter}:")
    
    for i in range(row):

        for n in range(colum):

            if map1[i][n] != "*":

                print(mapAux[i][n], end="")
            
            else:
                print("*", end="")
            
        print()

    row, colum = [int(x) for x in stdin.readline().split()]
    counter+=1
    if row != 0 or colum != 0:
        print()
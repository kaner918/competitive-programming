#https://onlinejudge.org/external/102/10279.pdf
#10279

from sys import stdin

arrRow = [1, 1, 0, -1, -1, -1, 0, 1]
arrColum = [0, -1, -1, -1, 0, 1, 1, 1]

def main():

    cases = int(stdin.readline())

    for j in range(cases):

        input()

        map1 = []
        map2 = []
        mapAux = []

        size = int(stdin.readline())

        for i in range(size):

            map1.append(stdin.readline().rstrip('\n'))
            mapAux.append([0 for x in range(size)])
        
        for i in range(size):

            map2.append(stdin.readline().rstrip('\n'))

        ans = True
        
        for i in range(size):

            for n in range(size):

                if map2[i][n] == "x" and map1[i][n] == "*": 

                    ans = False

                elif map2[i][n] == "x" and map1[i][n] == ".":

                    for m in range(8):

                        auxRow = i + arrRow[m]
                        auxColum = n + arrColum[m]

                        if (auxRow > -1 and auxColum > -1) and (auxRow<size and auxColum < size) and map1[auxRow][auxColum] == "*":

                            mapAux[i][n]+=1
        
        for i in range(size):

            for n in range(size):

                if ans == True:

                    if map2[i][n] == "x":

                        print(mapAux[i][n], end="")
                    
                    else:
                        print(".", end="")

                else:

                    if map2[i][n] == "x" and map1[i][n] == ".":

                        print(mapAux[i][n], end="") 
                    
                    elif map1[i][n] == "*":

                        print("*",end="")
                    
                    else:
                        print(".",end="")
                
            print()

        if j < cases-1:

            print()


main()
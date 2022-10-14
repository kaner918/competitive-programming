#https://onlinejudge.org/external/4/439.pdf
#439

dic = {"a": 0, "b":1, "c":2, "d":3, "e":4, "f":5, "g":6, "h":7}

from sys import stdin
from collections import deque

arrRow = [2, 2, -2, -2, 1, -1, 1, -1]
arrColum = [-1, 1, -1, 1, 2, 2, -2, -2]

class Pos:

    def __init__(self, row, colum):

        self.row = row
        self.colum = colum

def bfs(positionInit, positionFinish, visits):
      
    queue = deque()
    queue.append(positionInit)

    visits[positionInit.row][positionInit.colum] = 0
    
    while len(queue) > 0:

        auxPosition = queue.popleft()

        if auxPosition.row == positionFinish.row and auxPosition.colum == positionFinish.colum:

            return visits[auxPosition.row][auxPosition.colum]
        
        for i in range(8):

            auxRow = auxPosition.row + arrRow[i]
            auxColum = auxPosition.colum + arrColum[i]

            if (auxRow > -1 and auxColum >-1 ) and (auxRow < 8 and auxColum < 8) and visits[auxRow][auxColum] == None:

                queue.append(Pos(auxRow, auxColum))
                visits[auxRow][auxColum] = visits[auxPosition.row][auxPosition.colum] + 1


def main():

    line = stdin.readline().split()

    while line != []:
    
        visits = []
   
        for i in range(8):
    
            visits.append([None for x in range(8)])


        positionInit = Pos(dic[line[0][0]], int(line[0][1])-1)
        positionFinish = Pos(dic[line[1][0]], int(line[1][1])-1)

        print(f"To get from {line[0]} to {line[1]} takes {bfs(positionInit, positionFinish, visits)} knight moves.")
       
        line = stdin.readline().split()

main()
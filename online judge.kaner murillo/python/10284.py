#10284
#https://onlinejudge.org/external/102/10284.pdf

from sys import stdin

arrRow = [1, 1, 1, 0, -1, -1, -1, 0]
arrColum = [1, 0, -1, -1, -1, 0, 1, 1]
arrRowC = [2, 2, 1, -1, -2, -2, -1, 1]
arrColumC = [1, -1, -2, -2, -1, 1, 2, 2]

def dfs(row, colum, movement, board):

    if board[row][colum] == 'O':

        board[row][colum] = 'X'

    auxRow = row + arrRow[movement]
    auxColum = colum + arrColum[movement]

    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == 'X' or board[auxRow][auxColum] == 'O'):

        dfs(auxRow, auxColum, movement, board)
        
def main():

    board = stdin.readline().strip('\n').split('/')

    while board != ['']:

        board2 = []

        for i in board:
            
            position = 0
            line = []

            for n in range(len(i)):
                
                if ord(i[n]) >= ord('0') and ord(i[n]) <= ord('9'):
                    
                    for m in range(int(i[n])):

                        line.append('O')
                    
                    position+=int(i[n])

                else:

                    line.append(i[n])
                    position+=1
            
            board2.append(line)
        
        for i in range(len(board2)):

            for n in range(len(board2[i])):

                if  board2[i][n] == 'Q' or board2[i][n] == 'q':
                    
                    for x in range(8):

                        dfs(i, n, x, board2)
                
                elif board2[i][n] == 'B' or board2[i][n] == 'b':
                    
                    dfs(i, n, 0, board2)
                    dfs(i, n, 2, board2)
                    dfs(i, n, 4, board2)
                    dfs(i, n, 6, board2)

                elif board2[i][n] == 'R' or board2[i][n] == 'r':
                    
                    dfs(i, n, 1, board2)
                    dfs(i, n, 3, board2)
                    dfs(i, n, 5, board2)
                    dfs(i, n, 7, board2)

                elif board2[i][n] == 'K' or board2[i][n] == 'k':
                    
                    for x in range(8):
                        
                        auxRow = i + arrRow[x]
                        auxColum = n + arrColum[x]

                        if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board2[auxRow][auxColum] == 'X' or board2[auxRow][auxColum] == 'O'):

                            board2[auxRow][auxColum] = 'X'
                
                elif board2[i][n] == 'p':

                    auxRow = i + arrRow[2]
                    auxColum = n + arrColum[2]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board2[auxRow][auxColum] == 'X' or board2[auxRow][auxColum] == 'O'):

                            board2[auxRow][auxColum] = 'X'
                    
                    auxRow = i + arrRow[0]
                    auxColum = n + arrColum[0]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board2[auxRow][auxColum] == 'X' or board2[auxRow][auxColum] == 'O'):

                            board2[auxRow][auxColum] = 'X'

                elif board2[i][n] == 'P':

                    auxRow = i + arrRow[4]
                    auxColum = n + arrColum[4]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board2[auxRow][auxColum] == 'X' or board2[auxRow][auxColum] == 'O'):

                            board2[auxRow][auxColum] = 'X'
                    
                    auxRow = i + arrRow[6]
                    auxColum = n + arrColum[6]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board2[auxRow][auxColum] == 'X' or board2[auxRow][auxColum] == 'O'):

                            board2[auxRow][auxColum] = 'X'
                
                elif board2[i][n] == 'N' or board2[i][n] == 'n':

                    for x in range(8):
                        
                        auxRow = i + arrRowC[x]
                        auxColum = n + arrColumC[x]

                        if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board2[auxRow][auxColum] == 'X' or board2[auxRow][auxColum] == 'O'):

                            board2[auxRow][auxColum] = 'X'

        counter = 0
        
        for i in board2:
            
            for n in i:
                
                if n == 'O':

                    counter+=1
        
        print(counter)

        board = stdin.readline().strip('\n').split('/')

main()


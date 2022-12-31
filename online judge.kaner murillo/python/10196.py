#10196
#https://onlinejudge.org/external/101/10196.pdf

from sys import stdin

arrRow = [1, 1, 1, 0, -1, -1, -1, 0]
arrColum = [1, 0, -1, -1, -1, 0, 1, 1]
arrRowC = [2, 2, 1, -1, -2, -2, -1, 1]
arrColumC = [1, -1, -2, -2, -1, 1, 2, 2]
flag = None


def dfs(row, colum, movement, board, file):

    global flag

    if file == file.upper() and board[row][colum] == 'k':

        flag = False

    elif file == file.lower() and board[row][colum] == 'K':

        flag = True

    if flag == None and board[row][colum] != 'k' and board[row][colum] != 'K':

        auxRow = row + arrRow[movement]
        auxColum = colum + arrColum[movement]

        if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == '.' or board[auxRow][auxColum] == 'k' or board[auxRow][auxColum] == 'K'):

            dfs(auxRow, auxColum, movement, board, file)

def main():

    board = []
    counter = 1
    global flag

    for i in range(8):

        board.append(stdin.readline().rstrip('\n'))

    while board != ["........", "........", "........", "........", "........", "........", "........", "........"]:

        flag = None

        for i in range(len(board)):

            for n in range(len(board[i])):

                if  board[i][n] == 'Q' or board[i][n] == 'q':
                    
                    for x in range(8):

                        dfs(i, n, x, board, board[i][n])
                
                elif board[i][n] == 'B' or board[i][n] == 'b':
                    
                    dfs(i, n, 0, board, board[i][n])
                    dfs(i, n, 2, board, board[i][n])
                    dfs(i, n, 4, board, board[i][n])
                    dfs(i, n, 6, board, board[i][n])

                elif board[i][n] == 'R' or board[i][n] == 'r':
                    
                    dfs(i, n, 1, board, board[i][n])
                    dfs(i, n, 3, board, board[i][n])
                    dfs(i, n, 5, board, board[i][n])
                    dfs(i, n, 7, board, board[i][n])
                
                elif board[i][n] == 'p':

                    auxRow = i + arrRow[2]
                    auxColum = n + arrColum[2]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == 'K'):

                            flag = True
                    
                    auxRow = i + arrRow[0]
                    auxColum = n + arrColum[0]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == 'K'):

                            flag = True

                elif board[i][n] == 'P':

                    auxRow = i + arrRow[4]
                    auxColum = n + arrColum[4]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == 'k'):

                            flag = False
                    
                    auxRow = i + arrRow[6]
                    auxColum = n + arrColum[6]

                    if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == 'k'):

                            flag = False
                
                elif board[i][n] == 'N':

                    for x in range(8):
                        
                        auxRow = i + arrRowC[x]
                        auxColum = n + arrColumC[x]

                        if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == 'X' or board[auxRow][auxColum] == 'k'):

                            flag = False

                elif board[i][n] == 'n':

                    for x in range(8):
                        
                        auxRow = i + arrRowC[x]
                        auxColum = n + arrColumC[x]

                        if (auxRow > -1 and auxColum > -1 ) and (auxRow < 8 and auxColum < 8) and (board[auxRow][auxColum] == 'X' or board[auxRow][auxColum] == 'K'):

                            flag = True
        
        if flag == True:

            print(f"Game #{counter}: white king is in check.")

        elif flag == False:

            print(f"Game #{counter}: black king is in check.")

        else:

            print(f"Game #{counter}: no king is in check.")

        board = []
        stdin.readline()

        for i in range(8):

            board.append(stdin.readline().rstrip('\n'))
        
        counter+=1
main()
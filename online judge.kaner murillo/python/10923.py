#https://onlinejudge.org/external/109/10923.pdf
#10923

from sys import stdin
from heapq import heappop, heappush

graph = []
my_ship_row = None
my_ship_colum = None 
enemy_ships_row = []
enemy_ships_colum = []
lives = []
arrRow = [1, 1, 0, -1, -1, -1, 0, 1]
arrColum = [0, -1, -1, -1, 0, 1, 1, 1]

class State:

    def __init__(self, graph = [], row = 0, colum = 0, lives = [], enemy_rows = [], enemy_colums = [], moves = 0, size_lives = 0):

        self.graph = graph
        self.row = row
        self.colum = colum
        self.lives = lives
        self.enemy_rows = enemy_rows
        self.enemy_colums = enemy_colums
        self.moves = moves
        self.size_lives = size_lives
    
    def __lt__(self, other):

        if self.size_lives == other.size_lives:

            return self.moves < other.moves

        return self.size_lives < other.size_lives

def dijkstra():

    q = []
    visits = set()

    heappush(q, State(graph, my_ship_row, my_ship_colum, lives, enemy_ships_row, enemy_ships_colum, 10, len(lives)))
    visits.add((my_ship_row, my_ship_colum, 10, len(lives)))

    state = State()

    while len(q):

        state = heappop(q)

        if(state.size_lives<=0):

            return True

        elif state.moves > 0:

            for i in range(8):

                auxRow = state.row +  arrRow[i]
                auxColum = state.colum + arrColum[i]
                board = []

                for x in state.graph:

                    board.append(list(x))

                liv = list(state.lives)
                enemy_rows = list(state.enemy_rows)
                enemy_colums = list(state.enemy_colums)
                size_lives = state.size_lives
                flag = True
                pres = set()

                if(auxRow > -1 and auxColum > -1 and auxRow < 9 and auxColum < 8 and board[auxRow][auxColum] == '.'):

                    board[auxRow][auxColum] = 'S'
                    board[state.row][state.colum] = '.'

                    for n in range(len(liv)):

                        if(liv[n]):
                            
                            initRow = enemy_rows[n]
                            initColum = enemy_colums[n]

                            if(enemy_rows[n] == auxRow):
                                
                                if(enemy_colums[n] > auxColum):

                                    enemy_colums[n]-=1
                                
                                else:

                                    enemy_colums[n]+=1

                            elif(enemy_colums[n] == auxColum):

                                if(enemy_rows[n] > auxRow):

                                    enemy_rows[n]-=1
                                
                                else:

                                    enemy_rows[n]+=1

                            elif(enemy_rows[n] > auxRow):

                                if(enemy_colums[n] > auxColum):
                                
                                    enemy_colums[n]-=1
                                    enemy_rows[n]-=1
                                
                                else:
                                    enemy_colums[n]+=1
                                    enemy_rows[n]-=1

                            elif(enemy_rows[n] < auxRow):

                                if(enemy_colums[n] > auxColum):

                                    enemy_colums[n]-=1
                                    enemy_rows[n]+=1
                                
                                else:
                                    
                                    enemy_colums[n]+=1
                                    enemy_rows[n]+=1
                
                            if board[enemy_rows[n]][enemy_colums[n]] == 'S':
                                    
                                flag = False
                            
                            elif board[enemy_rows[n]][enemy_colums[n]] == '#':

                                size_lives-=1
                                liv[n] = False
                            
                            if board[enemy_rows[n]][enemy_colums[n]] == '.':

                                board[enemy_rows[n]][enemy_colums[n]] = board[initRow][initColum]

                            if (initRow, initColum) not in pres:

                                board[initRow][initColum] = '.'
                                pres.add((enemy_rows[n], enemy_colums[n]))

                    for n in range(len(liv)):
                        
                        pre = liv[n]

                        if(liv[n]):

                            for m in range(n+1, len(liv)):

                                if enemy_rows[m] == enemy_rows[n] and enemy_colums[n] == enemy_colums[m]:
                                    
                                    liv[n] = False
                                    liv[m] = False
                                    size_lives -=1
                                    board[enemy_rows[n]][enemy_colums[n]] = '#'

                        if(pre and not liv[n]):

                            size_lives-=1                      
                    
                    if flag and (auxRow, auxColum, state.moves - 1, size_lives) not in visits:

                        visits.add((auxRow, auxColum, state.moves - 1, size_lives))
                        heappush(q, State(board, auxRow, auxColum, liv, enemy_rows, enemy_colums, state.moves - 1, size_lives))

    return False

def main():

    cases = int(stdin.readline())
    
    for i in range(cases):

        global graph, my_ship_row, my_ship_colum, enemy_ships_row, enemy_ships_colum, lives

        graph = []
        my_ship_row = None
        my_ship_colum = None 
        enemy_ships_row = []
        enemy_ships_colum = []
        lives = []
        counter = 0

        for n in range(9):

            aux = list(stdin.readline().rstrip('\n'))
   
            for m in range(8):

                if aux[m] == 'E':
                    
                    enemy_ships_row.append(n)
                    enemy_ships_colum.append(m)
                    counter+=1
                    lives.append(True)
                
                elif aux[m] == 'S':

                    my_ship_row = n
                    my_ship_colum = m

            graph.append(aux)

        ans = dijkstra()          

        if i < cases-1:
            stdin.readline()

        
        if ans:

            print("I'm the king of the Seven Seas!")

        else:

            print("Oh no! I'm a dead man!")

main()
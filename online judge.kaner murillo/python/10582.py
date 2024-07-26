#https://onlinejudge.org/external/105/10582.pdf
#10582

from sys import stdin

def backtracking(r, c, pre, pre2, grid, moves, conection, arrRow, arrColum, diretion, visits):
    
    ans = 0
    #print(r, c, pre, pre2)
    if r == len(grid)-1 and c == len(grid[0])-1:
        for j in (moves[grid[r][c]]):
            if ((pre2, pre, j) in conection):
                for i in (diretion[j]):
                    auxRow = r + arrRow[i]
                    auxColum = c + arrColum[i]
                    if auxRow < len(grid) and auxColum < len(grid[0]) and auxRow > -1 and auxColum >-1:
                        ans = 1

    else:
        if(not r and not c):
                for j in (moves[grid[r][c]]):
                    for i in (diretion[j]):
                        auxRow = r + arrRow[i]
                        auxColum = c + arrColum[i]
                        if auxRow < len(grid) and auxColum < len(grid[0]) and auxRow > -1 and auxColum >-1 and not visits[auxRow][auxColum]:
                            visits[auxRow][auxColum] = 1
                            ans+=backtracking(auxRow, auxColum, j, i, grid, moves, conection, arrRow, arrColum, diretion, visits)
                            visits[auxRow][auxColum] = 0

        else:
            if(grid[r][c] != 2):
                for j in (moves[grid[r][c]]):
                    if ((pre2, pre, j) in conection):
                        for i in (diretion[j]):
                            auxRow = r + arrRow[i]
                            auxColum = c + arrColum[i]
                            if auxRow < len(grid) and auxColum < len(grid[0]) and auxRow > -1 and auxColum >-1 and not visits[auxRow][auxColum]:
                                visits[auxRow][auxColum] = 1
                                ans+=backtracking(auxRow, auxColum, j, i, grid, moves, conection, arrRow, arrColum, diretion, visits)
                                visits[auxRow][auxColum] = 0
    #print("back")
    return ans

def main():

    cases = int(stdin.readline())
    compares  = [["   ", "***", "   "],
                 ["   ", "** ", " * "],
                 ["   ", "   ", "   "]]

    moves = [[0, 3], [1, 4, 5, 6], [], [0, 3], [1, 4, 5, 6], [1, 4, 5, 6], [1, 4, 5, 6]]
    # conection = [((1, 0), (1, 6), (1, 5), (3,4), (3,1), (3, 0)), ((1, 5), (1, 0), (1, 6), (2, 4), (2, 5), (2, 3)), (), 
    #              ((0, 1), (0, 6), (0, 3), (2, 3), (2,5), (2,4)), ((1,0), (1,5), (1,6), (0, 6), (0,1), (0,3)),
    #              ((0,3), (0,6), (0, 1), (3, 4), (3,0), (3,1)), ((3, 4), (3,0), (3,1), (2, 4), (2,5), (2,3))]
    
    conection = set([(3,0,1),(3,0,4),(3,0,0),(1,0,6),(1,0,5),(1,0,0),
                    (1,1,0),(1,1,6), (1,1,5), (0,1,4),(0,1,3),(0,1,5),
                    (2,3,1),(2,3,6),(2,3,3),(0,3,5),(0,3,4), (0,3,3),
                    (1,4,0),(1,4,6),(1,4,5),(2,4,6), (2,4,3), (2,4,1),
                    (3,5,1),(3,5,4),(3,5,0),(2,5,1),(2,5,3),(2,5,6),
                    (3,6,4),(3,6,1),(3,6,0),(0,6,3),(0,6,5),(0,6,4)])
    
    diretion = [(1,3),(1,0), (), (0, 2), (1,2), (2,3), (0,3)]

    arrRow = [1, 0, -1, 0]
    arrColum = [0, -1, 0, 1]

    for i in range(cases):

        lines = []

        n, m = [int(x) for x in stdin.readline().split()]
        
        rows = n*3+n+1
        colums = m*3+m+1

        for j in range(rows):
            lines.append(stdin.readline().strip())

        #print(lines)
        grid = [[0 for _ in range(m)] for j in range(n)]
        visits = [[0 for _ in range(m)] for j in range(n)]
        visits[0][0] = 1
        j, k, l, p, u, w = 1, 1, 0, 0, 0, 0

        while j < rows:
            k = 1
            p = 0
            while k <  colums:
                #print(j, k)
                aux = []
                for u in range(3):
                    cad = ""
                    for w in range(3):
                        cad+=lines[j+u][k+w]
                    aux.append(cad)
                u = 0
                #print(aux)
                while compares[u] != aux: 
                    u+=1
                
                grid[l][p] = u 
                k+=4
                p+=1
            j+=4 
            l+=1
        #print(grid)

        if n == 1 and m == 1:
            print(f"Number of solutions: 2")
        else:
            print(f"Number of solutions: {backtracking(0, 0, -1, -1, grid, moves, conection, arrRow, arrColum, diretion, visits)}")

main()

'''
1
4 6
+---+---+---+---+---+---+
|   |   |   |   |   |   |
|***|***|** |** |** |***|
|   |   | * | * | * |   |
+---+---+---+---+---+---+
|   |   |   |   |   |   |
|   |** |** |***|** |** |
|   | * | * |   | * | * |
+---+---+---+---+---+---+
|   |   |   |   |   |   |
|***|** |***|***|***|** |
|   | * |   |   |   | * |
+---+---+---+---+---+---+
|   |   |   |   |   |   |
|** |   |***|   |** |** |
| * |   |   |   | * | * |
+---+---+---+---+---+---+
'''
#https://onlinejudge.org/external/119/11906.pdf
#11906

import sys
sys.setrecursionlimit(1000000)
from sys import stdin
move_row = [-1, -1, 1, 1]
move_colum = [-1, 1, -1, 1]

def dfs(r, c, m, n, graph, visits):
    
    global move_row, move_colum
    visits[r][c] = 1
    even = 0
    odd = 0
    count = 0
    limit = 4

    if n != m:
        limit = 8

    for i in range(limit):
        
        new_r = r + m * move_row[(i%4)]
        new_c = c + n * move_colum[(i%4)]

        if i >= 4:
            new_r = r + n * move_row[(i%4)]
            new_c = c + m * move_colum[(i%4)]

        if new_r < len(graph) and new_r > -1 and new_c < len(graph[0]) and new_c > -1 and not graph[new_r][new_c]:
            count+=1
            if not visits[new_r][new_c]:
                result = dfs(new_r, new_c, m, n, graph, visits)
                even+=result[0]
                odd+=result[1]

    if n == 0 or m == 0:
        count//=2
        
    if count % 2 == 0:
        even+=1
    else:
        odd+=1

    return (even, odd)


    


def main():

    cases = int(stdin.readline())

    for i in range(1, cases+1):

        rows, colums, m, n = [int(x) for x in stdin.readline().split()]
        graph = [[0 for x in range(colums)] for z in range(rows)]
        visits = [[0 for x in range(colums)] for z in range(rows)]
        water_cells = int(stdin.readline())

        for j in range(water_cells):
            r, c = [int(x) for x in stdin.readline().split()]
            graph[r][c] = 1
        
        ans = dfs(0, 0, m, n, graph, visits)
        print(f'Case {i}: {ans[0]} {ans[1]}')

if __name__ == "__main__":
    main()

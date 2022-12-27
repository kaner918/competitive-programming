#https://onlinejudge.org/external/7/785.pdf
#785

from sys import stdin

arrRow = [1, 0, -1, 0]
arrColum = [0, -1, 0, 1]

def dfs(graph, row, colum, figure):

    graph[row][colum] = figure

    for i in range(4):

        auxRow = row + arrRow[i]
        auxColum = colum + arrColum[i]

        if((auxRow>-1 and auxColum>-1) and (auxRow<len(graph) and auxColum<len(graph[auxRow])) and graph[auxRow][auxColum] == " "):

            dfs(graph, auxRow, auxColum, figure)

def main():

    line = stdin.readline()

    while len(line) > 0:

        aux_line = stdin.readline().rstrip('\n')

        graph = [list(line)]
        graph[-1].pop()

        dic = {}

        for i in line:

            if i not in dic and i != " " and i != "_":

                dic[i] = 1

            elif i in dic and i != " " and i != "_":
                dic[i]+=1

        while "_" not in aux_line:

            graph.append(list(aux_line))

            for i in aux_line:

                if i not in dic and i != " " and i != "_":

                    dic[i] = 1

                elif i in dic and i != " " and i != "_":
                    dic[i]+=1

            aux_line = stdin.readline().rstrip('\n')
        
        possibles = sorted(dic.items(), key=lambda x: -x[1])

        for i in range(len(graph)):

            for n in range(len(graph[i])):

                if(graph[i][n] != " " and graph[i][n] != possibles[0][0]):

                    dfs(graph, i, n, graph[i][n])

        for i in graph:

            print("".join(i))
        
        print(aux_line)

        line = stdin.readline()

main()
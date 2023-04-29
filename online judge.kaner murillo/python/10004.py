#https://onlinejudge.org/external/100/10004.pdf
#10004

from sys import stdin

def dfs(graph, visits, node, color):

    visits[node] = color
    ans = True

    for i in graph[node]:

        if visits[i] == -1:

            ans = dfs(graph, visits, i, not color)
    
        elif visits[i] != -1 and visits[i] == color:

            return False
        
    return ans

def main():

    n = int(stdin.readline())

    while n:

        graph = [[] for x in range(n)]
        visits = [-1 for x in range(n)]

        size = int(stdin.readline())

        for i in range(size):

            node1, node2 = [int(x) for x in stdin.readline().split()]
            graph[node1].append(node2)
            graph[node2].append(node1)

        ans = dfs(graph, visits, 0, 0)

        if ans:

            print("BICOLORABLE.")
        
        else:
            print("NOT BICOLORABLE.")
            
        n = int(stdin.readline())

main()
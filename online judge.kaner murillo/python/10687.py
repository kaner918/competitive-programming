#https://onlinejudge.org/external/106/10687.pdf
#10687

from sys import stdin
from math import sqrt

def dfs(visits, points, node, size):

    ans = 1
    visits[node] = True
    ad = []

    for i in range(0, size*2, 2):

        if i!=node:

            dist = sqrt((points[i]- points[node])**2 + (points[i+1] - points[node+1])**2)
            compare(dist, ad, node, i)

    for i in ad:

        if i and not visits[i[0]]:
            ans+=dfs(visits, points, i[0], size)

    return ans

def compare(dist, ad, i, j):

    if not len(ad):

        ad.append((j, dist))
        ad.append(None)

    else:
        
        if dist < ad[0][1]:
            
            ad[0], ad[1] = (j, dist), ad[0]
            
        else:

            if ad[1] == None:

                ad[1] = (j, dist)

            else:

                if dist < ad[1][1]:
            
                    ad[1] = (j, dist)

def main():

    size = int(stdin.readline())
    points = []

    while size:

        while len(points) < size*2:

            points.extend([int(x) for x in stdin.readline().split()])

        visits = [False for _ in range(1001*2)]

        """ init_x = aux_points[0]
        init_y = aux_points[1]
        init = None
        points = []
        graph = [[] for _ in range(1001)]

        for i in range(0, size*2, 2):
            points.append((aux_points[i], aux_points[i+1]))

        points.sort(key=lambda x:(x[0], x[1]))
        
        for i in range(size):
            
            visits[i] = False

            if points[i][0] == init_x and points[i][1] == init_y:
                init = i

            for j in range(i+1, size):
                
                dist = sqrt((points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1])**2)
               
                compare(dist, graph, i, j)
                compare(dist, graph, j, i) """
          
        if dfs(visits, points, 0, size) == size:
            print("All stations are reachable.")
        
        else:
            print("There are stations that are unreachable.")

        size = int(stdin.readline())
        points = []

main()

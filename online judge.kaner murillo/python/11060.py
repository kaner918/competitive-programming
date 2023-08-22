#https://onlinejudge.org/external/110/11060.pdf
#11060

from sys import stdin
from heapq import heappop, heappush

def khans(res, q, father, beverages):

    while len(q):

        node = q[0]
        heappop(q)
        res.append(node[1])

        for i in beverages[node[1]][0]:

            father[i]-=1

            if not father[i]:
                heappush(q, (beverages[i][1], i))

def main():

    size = stdin.readline()
    counter = 1
    
    while size != "":

        size = int(size)
        beverages = {}
        father = {}

        for i in range(size):
            name = stdin.readline().rstrip('\n')

            beverages[name] = ([], i)
            father[name] = 0

        conections = int(stdin.readline())

        for i in range(conections):

            edge = stdin.readline().split()

            father[edge[1]]+=1
            beverages[edge[0]][0].append(edge[1])
        
        res = []
        q = []

        for i in father:

            if(not father[i]):
                heappush(q, (beverages[i][1], i))

        khans(res, q, father, beverages)

        print(f"Case #{counter}: Dilbert should drink beverages in this order:", end="")

        for i in range(len(res)):

            print("", res[i], end="")
        print(".\n")

        counter+=1
        _=stdin.readline()
        size = stdin.readline()
main()
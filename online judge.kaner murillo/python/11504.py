#https://onlinejudge.org/external/115/11504.pdf
#11504

from pydoc import visiblename
from sys import stdin

def dfs(domino, dominos, visits):

    visits[domino] = True

    for i in range(len(dominos[domino])):

        if(visits[dominos[domino][i]]) == False:

            dfs(dominos[domino][i], dominos, visits)

def main():

    cases = int(stdin.readline())

    for i in range(cases):

        dominos, conections = [int(x) for x in stdin.readline().split()]

        visits = [False for x in range(dominos)]
        dominos = [[] for x in range(dominos)]
        
        for n in range(conections):

            domino1, domino2 = [int(x) for x in stdin.readline().split()]

            dominos[domino1-1].append(domino2-1)
        
        counter = 0

        for n in range(len(visits)):

            if visits[n] == False:

                counter+=1
                dfs(n, dominos, visits)

        print(counter)

main()
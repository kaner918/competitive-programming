#10721
#https://onlinejudge.org/external/107/10721.pdf

from pprint import pprint
from sys import stdin

def solve(n, k, m):
    tab = [[0 for _ in range(k+1)] for _ in range(n+1)]

    tab[n][k] = 1

    for suma in range(n-1, -1, -1):
        for grupos in range(k-1, -1, -1):
            for contiguos in range(1, m+1):
                if suma+contiguos <= n:
                    tab[suma][grupos] += tab[suma+contiguos][grupos+1]

    pprint(tab)
    return tab[0][0]

def main():

    case = [int(x) for x in stdin.readline().split()]

    while case != []:

        print(solve(case[0], case[1], case[2]))

        case = [int(x) for x in stdin.readline().split()]

main()
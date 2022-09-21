#https://onlinejudge.org/external/126/12643.pdf
#12643

from sys import stdin

tournament = [int(x) for x in stdin.readline().split()]

while tournament != []:

    matchs = 2**(tournament[0]-1)
    
    if (tournament[1] <= matchs//2 and tournament[2]>matchs//2) or (tournament[1] > matchs//2 and tournament[2]<=matchs//2):

            print(tournament[0])

    tournament = [int(x) for x in stdin.readline().split()]
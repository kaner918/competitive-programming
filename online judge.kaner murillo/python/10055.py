#https://onlinejudge.org/external/100/10055.pdf
#10055

from sys import stdin

bandos = [int(x) for x in stdin.readline().strip().split()]

while bandos!=[]:
    
    print(abs(bandos[0]-bandos[1]))

    bandos = [int(x) for x in stdin.readline().strip().split()]


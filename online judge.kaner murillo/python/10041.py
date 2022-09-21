#https://onlinejudge.org/external/100/10041.pdf
#10041

from sys import stdin

cases = int(stdin.readline())

for i in range(cases):

    sum = 0

    relatives = [int(x) for x in stdin.readline().split()]
    relatives.pop(0)

    relatives.sort()

    medium = relatives[len(relatives)//2]

    for n in range(len(relatives)):

        sum+=abs(medium-relatives[n])
    
    print(sum)

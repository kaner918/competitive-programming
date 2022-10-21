#https://onlinejudge.org/external/100/10067.pdf
#10067

from hashlib import blake2b
from sys import stdin
from collections import deque

cases = int(stdin.readline())
arrMove = [0, 1, -1]

def bfs(comInit, comFinish, conj, block):

    queue = deque()
    queue.append([comInit, 0, 0])
    conj.add(tuple(comInit))

    while(len(queue) > 0):

        auxCob = queue.popleft()

        if auxCob[1] > 3:

            auxCob[1] = 0

        auxCob2 = list(auxCob[0])
        print(auxCob2)

        for i in range(3):

            auxNumber = auxCob[0][auxCob[1]] + arrMove[i] 

            if auxNumber > 9:

                auxNumber = 0

            elif auxNumber < 0:

                auxNumber = 9

            auxCob2[auxCob[1]] = auxNumber

            if auxCob2 not in block and tuple(auxCob2) not in conj:

                queue.append([auxCob2, auxCob[1]+1, auxCob[2]+1])
                conj.add(tuple(auxCob2))

for i in range(cases):

    comInit = [int(x) for x in stdin.readline().split()]
    comFinish = [int(x) for x in stdin.readline().split()]

    sizeBlock = int(stdin.readline())
    block = []

    for n in range(sizeBlock):

        block.append(stdin.readline().split())
    
    conj = set()

    bfs(comInit, comFinish, conj, block)

#https://onlinejudge.org/external/122/12207.pdf
#12207

from sys import stdin
from collections import deque

peoples, commands = [int(x) for x in stdin.readline().split()]
counter = 1

while peoples != 0 or commands != 0:

    queue = deque([int(x+1) for x in range(peoples)])
    prioQueue = deque()

    print(f"Case {counter}:")

    for i in range(commands):

        command = stdin.readline().split()

        if command[0] == 'N':
            
            queue.append(queue.popleft())
            print(queue[-1])
            
        else:
            
            while queue[0] != int(command[1]):

                prioQueue.append(queue.popleft())
            
            print(queue[0])
            queue.append(queue.popleft())
            
            while len(prioQueue) > 0:

                queue.append(prioQueue.popleft())

    counter+=1

    peoples, commands = [int(x) for x in stdin.readline().split()]
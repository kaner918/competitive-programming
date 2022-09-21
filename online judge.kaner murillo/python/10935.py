#https://onlinejudge.org/external/109/10935.pdf
#10935

from sys import stdin
from collections import deque 

size = int(stdin.readline())

while size != 0:

    queue = deque ([str(x) for x in range(1,size+1)])
    cDeque = deque()

    while len(queue) > 1:

        cDeque.append(queue.popleft())
        queue.append(queue.popleft())

    print("Discarded cards:", end="")
    [print(" "+cDeque[x]+",", end="") for x in range(size-2)]
    
    if len(cDeque) > 0:
        
        print(" "+cDeque[-1])
    
    else:
        print()
        
    print("Remaining card:", queue[0])
    
    size = int(stdin.readline())
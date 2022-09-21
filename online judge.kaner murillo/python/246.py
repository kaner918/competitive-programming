#https://onlinejudge.org/external/2/246.pdf
#246

from sys import stdin
from collections import deque

cSequence = deque([int(x) for x in stdin.readline().split()])

while cSequence[0] != 0:

    while len(cSequence) < 52:

        [cSequence.append(int(x)) for x in stdin.readline().split()]

    cardsSet = set()
    state = []
    queues = deque()
    counter = 0
    flag = True

    for i in range(7):

        queues.append(deque([cSequence.popleft()]))

    while len(cSequence) >0 and len(queues) > 0 and flag == True:

        queues[0].append(cSequence.popleft())
        counter+=1

        ans = True

        while ans == True and len(queues[0]) >= 3:

            sums = queues[0][0] + queues[0][1] + queues[0][-1]
            sums2 = queues[0][0] + queues[0][-1] + queues[0][-2]
            sums3 = queues[0][-3] + queues[0][-2] + queues[0][-1]

            if (sums == 10) or (sums == 20) or (sums == 30):
                
                cSequence.append(queues[0][0]) 
                cSequence.append(queues[0][1])
                cSequence.append(queues[0][-1])

                queues[0].popleft()
                queues[0].popleft()
                queues[0].pop()
            
            elif (sums2 == 10) or (sums2 == 20) or (sums2 == 30):
                
                cSequence.append(queues[0][0]) 
                cSequence.append(queues[0][-2])
                cSequence.append(queues[0][-1])

                queues[0].popleft()
                queues[0].pop()
                queues[0].pop()
            
            elif (sums3 == 10) or (sums3 == 20) or (sums3 == 30):
                
                cSequence.append(queues[0][-3]) 
                cSequence.append(queues[0][-2])
                cSequence.append(queues[0][-1])

                queues[0].pop()
                queues[0].pop()
                queues[0].pop()

            else:
                ans = False
        
        state = cSequence.copy()
    
        for i in queues:

            state.extend(i.copy())
        
        if tuple(state) in cardsSet:

            flag = False
        
        else:

            cardsSet.add(tuple(state))

        if len(queues[0]) == 0:
            queues.popleft()

        else:
            queues.append(queues.popleft())

    if flag == False:
        print(f"Draw: {counter+7}")
    
    elif len(queues) == 0:
        print(f"Win : {counter+7}")
    
    else:
        print(f"Loss: {counter+7}")

    cSequence = deque([int(x) for x in stdin.readline().split()])
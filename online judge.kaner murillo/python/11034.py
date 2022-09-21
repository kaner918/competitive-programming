#https://onlinejudge.org/external/110/11034.pdf
#11034

from sys import stdin
from collections import deque

cases = int(stdin.readline())

for i in range(cases):

    trip = [int(x) for x in stdin.readline().split()]
    trip[0] = trip[0] * 100

    left = deque()
    right = deque()

    for n in range(trip[1]):

        car = stdin.readline().split()

        if car[1] == "left":

            left.append(int(car[0]))
        
        else:

            right.append(int(car[0]))

    ans = False
    counter = 0

    while len(left) != 0 or len(right) != 0:

        if ans == False:

            counter2 = 0

            while len(left) != 0 and counter2 + left[0] <= trip[0]:

                counter2+= left[0]
                left.popleft() 
            
            ans = True
            counter+=1

        else:

            counter2 = 0

            while len(right) != 0 and counter2 + right[0] <= trip[0]:

                counter2+= right[0]
                right.popleft() 
            
            ans = False
            counter+=1

    print(counter)


            
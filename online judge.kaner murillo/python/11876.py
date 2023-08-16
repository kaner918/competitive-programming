#https://onlinejudge.org/external/118/11876.pdf
#11876

from math import sqrt, floor
from sys import stdin
from collections import deque

def main():

    cases = int(stdin.readline())
    numbers = deque([1])
    ans = 0

    for i in range(cases):

        a, b = [int(x) for x in stdin.readline().split()]
        ans = 0

        while numbers[-1] < b:

            counter = 0
            n = 1
            while n <= sqrt(numbers[-1]):
            
                counter+= (not (numbers[-1] % n))*2
                n+=1

            if int(sqrt(numbers[-1]))**2 == numbers[-1]:
                counter-=1

            numbers.append(numbers[-1] + counter)

        print(len(numbers))
        print(numbers)

        """ print(f"Case {i+1}: {ans}") """
        
main()
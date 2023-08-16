#https://onlinejudge.org/external/118/11876.pdf
#11876

from math import sqrt
from sys import stdin

def main():

    cases = int(stdin.readline())
    ans = 0

    for i in range(cases):

        a, b = [int(x) for x in stdin.readline().split()]
        ans = 0

        while a <= b:

            print("numero:", a)
            counter = 0
            for n in range(1, a+1):
            
                counter+= not (a % n)

            a+=counter
            ans+=1
        print(f"Case {i+1}: {ans}")
        
main()
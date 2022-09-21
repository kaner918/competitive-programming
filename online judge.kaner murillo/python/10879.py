#https://onlinejudge.org/external/108/10879.pdf
#10879

from sys import stdin

cases = int(stdin.readline())

for i in range(1, cases+1):

    number = int(stdin.readline())

    list = []
    n = 2

    while len(list) < 2:

        if number % n == 0:
            list.append(n)
        
        n+=1
    
    print(f"Case #{i}: {number} = {list[0]} * {number//list[0]} = {list[1]} * {number//list[1]}")

        





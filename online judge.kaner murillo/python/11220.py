#https://onlinejudge.org/external/112/11220.pdf
#11220

from sys import stdin 

cases = int(stdin.readline())
input()

for i in range(1, cases+1):

    line = stdin.readline().split()

    print(f"Case #{i}:")

    while line != []:

        index  = 0
        word = []

        for n in line:

            if len(n) >= index+1:

                word.append(n[index])
                index+=1
        
        print("".join(word))

        line = stdin.readline().split()

    if i < cases:

        print()
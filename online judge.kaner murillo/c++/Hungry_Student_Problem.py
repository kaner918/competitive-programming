from sys import stdin 

cases = int(stdin.readline())

for i in range(cases):

    size = int(stdin.readline())

    if size%3 == 0 or size%7 == 0:

        print("YES")

    elif (size-((size//7)*7)) % 3 == 0 or (size-((size//3)*3)) % 7 == 0:

       print("YES")     

    else:

        print("NO")
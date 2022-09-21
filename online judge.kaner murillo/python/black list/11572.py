#https://onlinejudge.org/external/115/11572.pdf
#11572

from sys import stdin

cases = int(stdin.readline())

for i in range(cases):

    dic = {}

    size = int(stdin.readline())
    index = 0
    higer = 0
    dic[index] = []

    for n in range(size):

        number = int(stdin.readline())

        if number not in dic[index]:
            dic[index].append(number)
        
        else:
            index+=1
            dic[index] = [number]

        if len(dic[index]) > higer:
            higer = len(dic[index])
        
    print(higer)

        

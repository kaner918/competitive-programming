#https://onlinejudge.org/external/104/10420.pdf
#10420

from sys import stdin

size = int(stdin.readline())
dic = {}

for i in range(size):

    loved = stdin.readline().split()

    if len(loved) > 1:

        if loved[0] in dic:
            dic[loved[0]]+=1
        
        else:
            dic[loved[0]] = 1
    
sort = sorted(dic.items(), key=lambda x: x[0])

for i in sort:

    print(i[0], i[1])
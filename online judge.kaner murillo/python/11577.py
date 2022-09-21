#https://onlinejudge.org/external/115/11577.pdf
#11577

from sys import stdin

cases = int(stdin.readline())

for i in range(cases):

    line = stdin.readline().rstrip('\n').lower()
    dic = {}
    mayor = 0

    for n in line:

        if ord(n) >= ord('a') and ord(n) <= ord('z'):

            if n in dic:

                dic[n]+=1
            
            else:

                dic[n] = 1
            
            if dic[n] > mayor:
                mayor = dic[n]
    
    cad = []

    for n in dic:

        if dic[n] == mayor:
            cad.append(n)

    cad.sort()

    print("".join(cad))

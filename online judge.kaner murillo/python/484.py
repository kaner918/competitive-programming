#https://onlinejudge.org/external/4/484.pdf
#484

from sys import stdin

secuencia  = [int(x) for x in stdin.readline().split()]
dic  = {}

while secuencia != []:

    for i in range(len(secuencia)):

        if secuencia[i] in dic:
            dic[secuencia[i]]+=1
        
        else:
            dic[secuencia[i]] = 1

    secuencia = [int(x) for x in stdin.readline().split()]

for i in dic:
    print(i, dic[i])
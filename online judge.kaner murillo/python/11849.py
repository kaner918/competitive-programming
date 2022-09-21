#https://onlinejudge.org/external/118/11849.pdf
#11849

from sys import stdin

discosTotales = [int(x) for x in stdin.readline().split()]

while discosTotales != [0,0]:

    conjunto1 = set()
    conjunto2 = set()

    for i in range(discosTotales[0]):
        
        conjunto1.add(int(stdin.readline().strip()))

    for i in range(discosTotales[1]):

        conjunto2.add(int(stdin.readline().strip()))
    
    lista = conjunto1 & conjunto2

    print(len(lista))

    discosTotales = [int(x) for x in stdin.readline().split()]

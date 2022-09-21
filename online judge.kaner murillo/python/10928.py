#https://onlinejudge.org/external/109/10928.pdf
#10928

from sys import stdin, stdout

casos = int(input())

for i in range(casos):
    
    lPosibles = int(input())
    cad = []
    menor = lPosibles

    for i in range(lPosibles):

        vecinos = stdin.readline().rstrip('\n').split()

        if(len(vecinos)<menor):
            cad = [i+1]
            menor = len(vecinos)

        elif len(vecinos) == menor:
            cad.append(i+1)
    
    stdin.readline()
    
    print(*cad)
        

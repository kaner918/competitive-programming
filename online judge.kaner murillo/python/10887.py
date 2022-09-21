#https://onlinejudge.org/external/108/10887.pdf
#10887

from sys import stdin

casos = int(stdin.readline().strip())

for i in range(1,casos+1):

    primerGrupo,segundoGrupo = [int(x) for x in stdin.readline().split()]

    conjunto1 = []
    conjunto2 = []
    concatenacion = set()

    for n in range(primerGrupo):

        conjunto1.append(stdin.readline().rstrip('\n'))
    
    for n in range(segundoGrupo):

        conjunto2.append(stdin.readline().rstrip('\n'))


    for n in conjunto1:

        for m in conjunto2:
            
            concatenacion.add(n+m)

    print("Case %d: %d"% (i, len(concatenacion)))
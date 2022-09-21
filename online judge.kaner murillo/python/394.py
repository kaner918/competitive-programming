#https://onlinejudge.org/external/3/394.pdf
#394

from sys import stdin 

casos = [int(x) for x in stdin.readline().rstrip('\n').split()]

biblio = []

for i in range(casos[0]):

    biblio.append(stdin.readline().rstrip('\n').split())

base = []

for i in range(casos[0]):

    posicion = len(biblio[i])-1
    ans = [int(biblio[i][2])]

    for n in range(int(biblio[i][3])-1):

        ans.insert(0,(int(biblio[i][posicion])-int(biblio[i][posicion-1])+1)*ans[0])

        posicion-=2
    
    base.append(ans)

for i in range(casos[1]):
    
    newDireccion = stdin.readline().rstrip('\n').split()
    posicion = 0
    posicionResta = 4
    cadena = []

    for n in range(len(biblio)):
        if biblio[n][0] == newDireccion[0]:
            posicion = n
    
    basico = int(biblio[posicion][1])

    for n in range(1,len(newDireccion)):

        if n<len(newDireccion)-1:

            cadena.append(newDireccion[n]+", ")

        else:
            cadena.append(newDireccion[n])

        basico+=(int(newDireccion[n])-int(biblio[posicion][posicionResta]))*base[posicion][n-1]
        posicionResta+=2

    cadena = "".join(cadena)

    print(f"{newDireccion[0]}[{cadena}] = {basico}")

#formula:
'''e.g.
TWO 2000 4 3 1 4 0 5 5 10
TWO base = 2000 size = 4 D = 3
D0=(1, 4), D1=(0, 5), D2=(5, 10)
Di = (Di_L, Di_U)
    
C[2] = size = 4
C[1] = C[2] * (10-5+1) = 24
C[0] = C[1] * (5-0+1) = 144

TWO[3, 3, 9] = base + (3-D0_L)*C[0] + (3-D1_L)*C[1] + (9-D2_L)*C[2]
= 2000 + (3-1)*144 + (3-0)*24 + (9-5)*4 = 2376'''
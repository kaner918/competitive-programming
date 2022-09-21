#https://onlinejudge.org/external/4/483.pdf
#483

from sys import stdin

cadena = stdin.readline().strip()

while cadena != "":

    cadena2 = []
    linea = cadena.split()

    for i in range(len(linea)):

        for n in range(len(linea[i])-1,-1,-1):

            cadena2.append(linea[i][n])

        if i < len(linea)-1:

            cadena2.append(" ")
    
    print("".join(cadena2))
    
    cadena = stdin.readline().strip()
    
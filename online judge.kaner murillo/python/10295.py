#https://onlinejudge.org/external/102/10295.pdf
#10295

from sys import stdin

palabras, textos = [int(x) for x in stdin.readline().split()]
nombres = []
puntos = []

for i in range(palabras):

    entrada = stdin.readline().split()

    nombres.append(entrada[0])
    puntos.append(int(entrada[1]))

dic = dict(zip(nombres, puntos))

for i in range(textos):

    cadenas = []

    cad = stdin.readline().strip()

    while cad != ".":

        cadenas.extend(cad.split())

        cad = stdin.readline().strip()

    total  = 0

    for i in cadenas:

        if i in dic:
            total+=dic[i]

    print(total)
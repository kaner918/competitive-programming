#https://onlinejudge.org/external/102/10282.pdf
#10282

from sys import stdin

dic = {}

cadena = stdin.readline().split()

while cadena != []:

    dic[cadena[1]] = cadena[0]

    cadena = stdin.readline().split()

cadena = stdin.readline().strip()

while cadena != "":

    if cadena in dic:
        print(dic[cadena])
    
    else:
        print("eh")

    cadena = stdin.readline().strip()
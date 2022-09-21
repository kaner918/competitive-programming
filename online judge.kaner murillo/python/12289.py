#https://onlinejudge.org/external/122/12289.pdf
#12289

from sys import stdin

casos = int(stdin.readline().strip())

for i in range(casos):

    cadena = stdin.readline().rstrip('\n')

    if len(cadena) == 3:

        if (cadena[0] == "t" and cadena[1]=="w") or (cadena[1]=="w" and cadena[2]=="o") or (cadena[0] == "t" and cadena[2]=="o"):

            print(2)

        else:
            print(1)

    else:

        print(3)
#https://onlinejudge.org/external/8/895.pdf
#895

from sys import stdin 

dic = []
cadena = stdin.readline().strip()
letras = []

while cadena != "#":

    dic.append(cadena)

    cadena = stdin.readline().strip()

cadena = stdin.readline().split()

while cadena != ["#"]:

    contador = 0

    for m in dic:

        posiciones = []

        for i in range(len(m)):

            n = 0
            ans = False

            while n < len(cadena) and ans == False:

                if m[i] == cadena[n] and n not in posiciones:
                    posiciones.append(n)
                    ans = True
                n+=1

        if len(posiciones) == len(m):
            contador+=1

    print(contador)

    cadena = stdin.readline().split()

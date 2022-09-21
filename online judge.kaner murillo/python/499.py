#https://onlinejudge.org/external/4/499.pdf
#499

from sys import stdin

cadena = stdin.readline().strip()

while cadena != "":

    dic = {}
    mayor = 0
    letras = []
    letra = ""

    for i in range(len(cadena)):

        if (ord(cadena[i]) >= ord('a') and ord(cadena[i]) <= ord('z')) or ord(cadena[i]) >= ord('A') and ord(cadena[i]) <= ord('Z'):

            if cadena[i] not in dic:

                dic[cadena[i]] = 1

            else:

                dic[cadena[i]]+=1

    for i in dic:

        if dic[i] == mayor:

            letras.extend(i)
        
        elif dic[i] > mayor:

            mayor = dic[i]  
            letras = [i]
            letra = i
    
    letras.sort()
    print("".join(letras), dic[letra])

    cadena = stdin.readline().strip()
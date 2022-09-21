#https://onlinejudge.org/external/4/444.pdf
#444

from sys import stdin

cadena = stdin.readline().strip()

while cadena != "":

    cadena2 = []

    if ord('0')<=ord(cadena[0])<=ord('9'):
        
        numero = ""
        i = len(cadena)-1
        
        while i>-1:

            numero+=cadena[i]

            if len(numero) == 2:
                
                
                if cadena[i-1] != '1':

                    cadena2.append(chr(int(numero)))
                    numero = ""

                else:

                    i-=1
                    numero+=cadena[i]
                    cadena2.append(chr(int(numero)))
                    numero = ""

            i-=1 

    elif (ord('a') <= ord(cadena[0])<=ord('z')) or (ord('A') <= ord(cadena[0])<=ord('Z')):
        
        for i in range(len(cadena)-1,-1,-1):

            numero = ord(cadena[i])

            while numero > 0:

                cadena2.append(str(numero%10))
                numero//=10

    print("".join(cadena2))
    
    cadena = stdin.readline().strip()
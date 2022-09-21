#https://onlinejudge.org/external/4/458.pdf
#458

from sys import stdin 

cadena = stdin.readline().strip()

while cadena != "":
    
    cadena2 = []

    for i in cadena:

        cadena2.append(chr(ord(i)-7))
    
    print("".join(cadena2))
    
    cadena = stdin.readline().strip()

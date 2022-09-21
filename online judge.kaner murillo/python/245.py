#https://onlinejudge.org/external/2/245.pdf
#245

from sys import stdin

cadena = stdin.readline().rstrip('\n')
palabras = []

while cadena!='0':

    cad = ""
    palabra = ""
    numero = "" 
    i = 0

    while i<len(cadena):

        if ord("a")<= ord(cadena[i]) <=ord("z") or ord("A")<= ord(cadena[i]) <=ord("Z"):
            if numero!="":
                cad+=palabras[int(numero)-1]
                palabra2 = palabras[int(numero)-1]
                palabras.pop(int(numero)-1)
                palabras.insert(0,palabra2)
            numero = ""
            palabra+=cadena[i]

        elif ord("0")<= ord(cadena[i])<= ord("9"):
            cad+=palabra
            if palabra!="":
                palabras.insert(0,palabra)
            palabra = ""
            numero+=cadena[i]
            

        else:
            if palabra!="":
                palabras.insert(0,palabra)
            
            elif numero!="":
                cad+=palabras[int(numero)-1]
                palabra2 = palabras[int(numero)-1]
                palabras.pop(int(numero)-1)
                palabras.insert(0,palabra2)

            cad+=palabra
            numero = ""
            cad+=cadena[i]
            palabra = ""

        i+=1
    
    cad+=palabra
    if numero!="":
                cad+=palabras[int(numero)-1]
                palabra2 = palabras[int(numero)-1]
                palabras.pop(int(numero)-1)
                palabras.insert(0,palabra2)

    elif palabra!="":
                palabras.insert(0,palabra)
    print(cad)
    cadena = stdin.readline().rstrip('\n')
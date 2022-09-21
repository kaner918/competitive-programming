#https://onlinejudge.org/external/2/272.pdf
#https://www.udebug.com/UVa/272
#272

from sys import stdin 

cadena = stdin.readline().strip()
ans = True 

while cadena!="":

    i = 0
    cad = []

    while i<len(cadena):
        
        if ord(cadena[i])== 34 and ans==True:
            cad.append("``")
            ans = False

        elif ord(cadena[i])== 34 and ans==False:
            cad.append("''")
            ans = True

        else:
            cad.append(cadena[i])

        i+=1

    print("".join(cad))
    cadena = stdin.readline().strip()

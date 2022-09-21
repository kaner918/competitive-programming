#https://onlinejudge.org/external/4/494.pdf
#494

from sys import stdin

cadena = stdin.readline().rstrip('\n')

while cadena != "":

    ans = False
    contador = 0

    for i in range(len(cadena)):

        if ord(cadena[i]) >= ord('a') and ord(cadena[i])<= ord('z') or ord(cadena[i]) >= ord('A') and ord(cadena[i])<= ord('Z'):
            
            ans = True
        
        else:

            if ans == True:
                contador+=1
                ans = False

    if ans == True:
        contador+=1
        
    print(contador)

    cadena = stdin.readline().rstrip()

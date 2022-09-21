#https://onlinejudge.org/external/4/492.pdf
#492

from sys import stdin

cadena = stdin.readline().rstrip('\n')

while cadena != "":

    nuevaCadena = []
    letra = ""
    ans = False
    flag = False
    posicion = 0

    for i in range(len(cadena)): 

        if (cadena[i].lower() == "a" or cadena[i].lower() == "e" or cadena[i].lower() == "i" or cadena[i].lower() == "o" or cadena[i].lower() == "u") and ans == False:

            ans = True
            flag = True
            nuevaCadena.append(cadena[i])

        elif (cadena[i].lower() != "a" or cadena[i].lower() != "e" or cadena[i].lower() != "i" or cadena[i].lower() != "o" or cadena[i].lower() != "u") and (ord(cadena[i].lower()) >= ord("a") and ord(cadena[i].lower()) <= ord("z")):
            
            if ans == False:

                ans = True
                flag = False
                letra = cadena[i]
            
            else:
                nuevaCadena.append(cadena[i])
            
        elif((ord(cadena[i].lower()) < ord("a") or ord(cadena[i].lower()) > ord("z"))):

            if ans == True and flag == True:

                nuevaCadena.append("ay")
                nuevaCadena.append(cadena[i])
                ans = False 

            elif ans == True and flag == False:

                nuevaCadena.append(letra)
                nuevaCadena.append("ay")
                nuevaCadena.append(cadena[i])
                ans = False

            else:
                nuevaCadena.append(cadena[i])
                
    if ans == True and flag == True:

        nuevaCadena.append("ay")

    elif ans == True and flag == False:

        nuevaCadena.append(letra)
        nuevaCadena.append("ay")
        ans = False

    print("".join(nuevaCadena))

    cadena = stdin.readline().rstrip('\n')
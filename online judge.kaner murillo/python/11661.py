#11661
#https://onlinejudge.org/external/116/11661.pdf

n = int(input())

while n!=0:


    posicion = None
    cadena = input() 
    menor = len(cadena)

    if "Z" in cadena:
        print(0)

    else:
        
        for i in range(len(cadena)):

            if (cadena[i] == "D" or cadena[i]=="R") and posicion == None:
                posicion = i

            elif (cadena[i] =="R" or cadena[i] =="D") and posicion!=None:
                
                if cadena[i] == cadena[posicion]:
                    posicion=i

                else:
                    if i-posicion < menor:
                        menor = i-posicion
                    posicion=i

        print(menor)




    n = int(input())    
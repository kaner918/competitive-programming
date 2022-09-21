from sys import stdin

cadena  = stdin.readline().strip()
contador = 1

while cadena!="":

    n = int(input())
    print(f"Case {contador}:")
    for i in range(n):

        rango = [int(x) for x in input().split()]
        ans = "Yes"
        unos = "1"
        ceros = "0"

        if cadena[rango[0]] != cadena[rango[1]]:
            print("No")
        
        else:
             
            if rango[0] < rango[1]:

                numero = rango[1]-rango[0]+1
                if cadena[rango[0]:rango[1]+1]!=unos*numero and cadena[rango[0]:rango[1]+1]!=ceros*numero:
                    ans = "No"
                
            else:

                numero = rango[0]-rango[1]

                if cadena[rango[1]:rango[0]]!=unos*numero and cadena[rango[1]:rango[0]]!=ceros*numero:
                    ans = "No"

            print(ans)
    cadena  = stdin.readline().strip()
    contador+=1
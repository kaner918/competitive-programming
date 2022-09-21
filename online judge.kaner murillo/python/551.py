#
#551

from sys import stdin 
from collections import deque

cadena = stdin.readline().rstrip('\n')

while cadena != "":

    flag = True
    ans = True
    i = 0
    contador = 0
    corchete = ""
    pila = deque()

    while ans == True and i<len(cadena):

        flag = True

        if i < len(cadena)-1:

            if cadena[i] == "(" and cadena[i+1] == "*":
                pila.append("(*")
                flag = False
                i+=1

            elif(cadena[i] == "*" and cadena[i+1] == ")"):

                if len(pila) != 0 and pila[-1] == "(*":

                    pila.pop()
                    flag = False
                    i+=1
                
                else:
                    ans = False
                    i+=1

        if flag == True:

            if cadena[i] == "(" or cadena[i] == "[" or cadena[i] == "{" or cadena[i] == "<":

                pila.append(cadena[i])

            elif cadena[i] == ")" or cadena[i] == "]" or cadena[i] == "}" or cadena[i] == ">":
                
                if len(pila)!=0 and cadena[i] == ")" and pila[-1] == "(":

                    pila.pop()
                
                elif len(pila)!=0 and cadena[i] == "]" and pila[-1] == "[":
                    
                    pila.pop()
                
                elif len(pila)!=0 and cadena[i] == "}" and pila[-1] == "{":
                    
                    pila.pop()

                elif len(pila)!=0 and cadena[i] == ">" and pila[-1] == ">":
                    
                    pila.pop()

                else:
                    ans = False 

        i+=1
        contador+=1

    if len(pila)!= 0 and ans == True:
        ans = False
        contador+=1
    
    if ans == True:
        print("YES")
    
    else:
        print("NO",contador)

    cadena = stdin.readline().rstrip('\n')
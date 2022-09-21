#https://onlinejudge.org/external/6/673.pdf
#673

from sys import stdin 
from collections import deque

casos = int(stdin.readline().strip())

for i in range(casos):

    cadena = stdin.readline().rstrip('\n')
    pila = deque()

    n = 0
    ans = True

    while n<len(cadena) and ans == True:

        if(cadena[n] == "[" or cadena[n] == "("):
            pila.append(cadena[n])
        
        elif (len(pila)!=0 and pila[-1] == "[" and cadena[n] == "]"):
            pila.pop()
        
        elif (len(pila)!=0 and pila[-1] == "(" and cadena[n] == ")"):
            pila.pop()

        else:
            ans = False

        n+=1
    
    if(len(pila)!=0):
        ans = False
    
    if ans == True:
        print("Yes")
    
    else:
        print("No")
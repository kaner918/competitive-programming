#https://www.udebug.com/UVa/10038
#10038

from sys import stdin
import math

cadena = [int(x) for x in stdin.readline().split()]

while cadena != []:

    if cadena[0] == 1:
        print("Jolly")
    
    else:

        ans = True
        n = 1
        conjunto = set()

        while n < cadena[0]:

            conjunto.add(abs(cadena[n] - cadena[n+1]))
            
            n+=1
        
        n = 1

        while n < cadena[0] and ans == True:

            if n not in conjunto:
                ans = False

            n+=1

        if ans == True:
            print("Jolly")
        
        else:
            print("Not jolly")

    cadena = [int(x) for x in stdin.readline().split()]
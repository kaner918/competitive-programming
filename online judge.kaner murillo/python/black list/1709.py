#https://onlinejudge.org/external/17/1709.pdf
#1709

from sys import stdin 
import math

entrada  = stdin.readline().strip()

while entrada!="":
    
    entrada = [int(x)for x in entrada.split()]
    
    mayorD = 0
    mayor = float(entrada[0]*(math.sin(entrada[1]+entrada[2])+math.cos(entrada[3]+entrada[4]))+2)


    for k in range(2,entrada[-1]):
        
        
        prueba = float(entrada[0]*(math.sin((entrada[1]*k)+entrada[2])+math.cos((entrada[3]*k)+entrada[4]))+2)

        if mayor > prueba:
            
            if float(mayorD)<mayor-prueba:
                mayorD = mayor-prueba
        
        else:
            mayor = prueba
    
    print("{:.6f}".format(mayorD))

    entrada = stdin.readline().strip()
        

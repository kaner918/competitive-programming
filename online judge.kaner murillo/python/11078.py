#https://onlinejudge.org/external/110/11078.pdf
#11078 

from sys import stdin 

cases  = int(stdin.readline().strip())

for i in range(cases):

    amount = int(stdin.readline().strip())

    estudiantes = []

    for n in range(amount):

        estudiantes.append(int(stdin.readline().strip()))
    
    mayor = estudiantes[0]
    max = -200000

    for n in range(amount-1):

        if estudiantes[n]>mayor:
            mayor = estudiantes[n]
        
        if mayor-estudiantes[n+1]>max:
            max = mayor-estudiantes[n+1]
    
    print(max)

            
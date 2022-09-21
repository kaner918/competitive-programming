#https://onlinejudge.org/external/103/10370.pdf
#10370

from sys import stdin

casos = int(stdin.readline().strip())

for i in range(casos):

    estudiantes = [int(x) for x in stdin.readline().split()]

    promedio = 0
    contador = 0

    for x in range(1,estudiantes[0]+1):

        promedio+=estudiantes[x]

    promedio = promedio / estudiantes[0]

    for x in range(1,estudiantes[0]+1):
        
        if estudiantes[x] > promedio:
            contador+=1
    
    print("%.3f%c" %((contador / estudiantes[0] * 100), '%'))
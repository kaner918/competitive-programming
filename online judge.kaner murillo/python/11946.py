#https://onlinejudge.org/external/119/11946.pdf
#11946

from sys import stdin

lista = ['O','I','Z','E','A','S','G','T','B','P']

casos = int(stdin.readline().strip())

for n in range(casos):

    cadena = list(stdin.readline().rstrip('\n'))

    while cadena!=[]: 
    
        for i in range(len(cadena)):

            if ord('0')<= ord(cadena[i]) <= ord('9'):
                
                cadena[i] = lista[int(cadena[i])]

        print("".join(cadena))

        cadena = list(stdin.readline().rstrip('\n'))
    
    if n+1<casos:

        print("")
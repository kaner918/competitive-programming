#https://onlinejudge.org/external/124/12468.pdf
#12468

from sys import stdin 

numeros = [int(x) for x in stdin.readline().rstrip('\n').split()]

while numeros != [-1,-1]:

    if numeros[0] < numeros[1]:

        if abs(numeros[0]-numeros[1]) <= numeros[0]-numeros[1] + 100:

            print(abs(numeros[0]-numeros[1]))
        
        else:

            print(numeros[0]-numeros[1] + 100)
    
    elif numeros[0]>numeros[1]:

        if abs(numeros[0]-numeros[1]) <= numeros[1]-numeros[0] + 100:

            print(abs(numeros[0]-numeros[1]))
        
        else:

            print(numeros[1]-numeros[0] + 100)

    else:

        print("0")

    numeros = [int(x) for x in stdin.readline().rstrip('\n').split()]


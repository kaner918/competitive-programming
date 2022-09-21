#https://onlinejudge.org/external/5/591.pdf
#591

from sys import stdin

cantidad = int(stdin.readline())
set = 1

while cantidad != 0:
    
    suma = 0

    bloques = [int(x) for x in stdin.readline().split()]

    for i in range(cantidad):

        suma+= bloques[i]
    
    numero = suma//cantidad

    suma = 0
    
    for i in range(cantidad):
        
        if bloques[i] > numero:

            suma+=bloques[i] - numero 

    print(f"Set #{set}")
    print(f"The minimum number of moves is {suma}.")

    set+=1
    print()
    
    cantidad = int(stdin.readline())
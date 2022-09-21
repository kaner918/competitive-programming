#https://onlinejudge.org/external/107/10783.pdf
#10783

from sys import stdin 

casos = int(stdin.readline().strip())

for i in range(1,casos+1):

    numero1 = int(stdin.readline().strip())
    numero2 = int(stdin.readline().strip())

    suma = 0
    
    for x in range(numero1, numero2+1):

        if x % 2 != 0:

            suma+=x
    
    print(f"Case {i}: {suma}")

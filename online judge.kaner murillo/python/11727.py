#https://onlinejudge.org/external/117/11727.pdf
#11727

from sys import stdin

casos = int(stdin.readline().strip())

for i in range(1,casos+1):

    empleados = [int(x) for x in stdin.readline().rstrip('\n').split()]

    if (empleados[0] > empleados[1] and empleados[0] < empleados[2]) or (empleados[0] < empleados[1] and empleados[0] > empleados[2]):
        print(f"Case {i}: {empleados[0]}")
    
    elif (empleados[1] > empleados[0] and empleados[1]<empleados[2]) or (empleados[1] < empleados[0] and empleados[1]>empleados[2]):
        print(f"Case {i}: {empleados[1]}")

    else:
        print(f"Case {i}: {empleados[2]}") 

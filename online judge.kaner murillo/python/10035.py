#https://www.udebug.com/UVa/10035
#10035

from sys import stdin

numero1, numero2 = [int(x) for x in stdin.readline().split()]

while numero1 != 0 or numero2 != 0:

    contador = 0
    carreado = 0

    while numero1 > 0 or numero2 > 0:

        if numero1%10 + numero2%10 + carreado >=10:
            carreado = 1
            contador+=1

        else:
            carreado = 0 

        numero1 //=10
        numero2 //=10

    if contador==1:

        print(f"{contador} carry operation.")

    elif contador>1:
        print(f"{contador} carry operations.")
    
    else:
        print("No carry operation.")

    numero1, numero2 = [int(x) for x in stdin.readline().split()]
#https://onlinejudge.org/external/3/306.pdf
#306

from sys import stdin

numero = int(input())

while numero!=0:

    lNumeros = [int(x) for x in input().split()]
    movimientos = []

    cadena = stdin.readline().rstrip('\n')

    pasos = []

    for i in range(numero):

        flag = False
        valor = lNumeros[i]
        contador = 0

        while valor != lNumeros[i] or flag == False:

            flag = True
            valor = lNumeros[valor-1]
            contador+=1
                
        pasos.append(contador)

    while cadena!="0":

        k = []
        lLetras = []
        letricas = []
        #extrar el numero
        i = 0
        while i < len(cadena) and ord("0")<= ord(cadena[i]) <=ord("9"):
            
            k.extend(cadena[i])
            i+=1
        
        k = int("".join(k))
        #armar la cadena, no utilizamos split, para no eliminar los espacios entre palabras
        i+=1
        while i<len(cadena):

            lLetras.extend(cadena[i])
            letricas.append(" ")
            i+=1

        #si la cadena no tiene las suficiones letras, se termina de llenar con espacios
        while len(lLetras)<len(lNumeros):
            lLetras.extend(" ")
            letricas.append(" ")
            

        contador = numero
        resultado = []


        for i in range(numero):

            valor = i+1
            pasitos = k%pasos[i]
            while pasitos>0:
                
                valor=lNumeros[valor-1]
                pasitos-=1
                
            resultado.append(valor-1)
            letricas[valor-1] = lLetras[i]

        print("".join(letricas))
        cadena = stdin.readline().rstrip('\n')


    numero = int(input())
    print("")
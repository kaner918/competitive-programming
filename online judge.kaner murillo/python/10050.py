#https://onlinejudge.org/external/100/10050.pdf
#10050

from sys import stdin 

casos = int(stdin.readline().strip())

for i in range(casos):

    acomulado = 0
    diasTotales = int(stdin.readline().strip())
    cDias = int(stdin.readline().strip())
    conjunto = set()

    for n in range(cDias):

        dMarcha = int(stdin.readline().strip())        
        cTiempo = diasTotales // dMarcha
        contador = 0

        for x in range(cTiempo):

            contador+=dMarcha

            if((contador%7)% 6 != 0 and (contador%7)%7 != 0):

                if contador not in conjunto:

                    conjunto.add(contador)
                    acomulado+=1
              
    print(acomulado)
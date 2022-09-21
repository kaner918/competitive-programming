#https://onlinejudge.org/external/116/11614.pdf
#11614
import math

casos = int(input())

for i in range(casos):

    soldados = int(input())

    respuesta = int(math.sqrt(soldados*2))

    if respuesta*(respuesta+1)/2 > soldados:
        respuesta-=1

    print(respuesta)



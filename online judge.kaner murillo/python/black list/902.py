#https://onlinejudge.org/external/9/902.pdf
#902

from sys import stdin

mensaje = stdin.readline().strip()

while mensaje != "":

    dic = {}
    cantidad, cadena = mensaje.split()
    nombre = ""

    for i in range(len(cadena) - int(cantidad)+1):
        
        nombre = cadena[i: i+int(cantidad)]

        if nombre in dic:
            dic[nombre]+=1
        
        else:
            dic[nombre] = 1

    ordenado = sorted(dic.items(), key=lambda x: x[1])

    print(ordenado[-1][0])

    mensaje = stdin.readline().strip()
#https://onlinejudge.org/external/9/902.pdf
#902

from sys import stdin

mensaje = stdin.readline().strip()

while mensaje != "":

    dic = {}
    cantidad, cadena = mensaje.split()
    nombre = ""
    aux_nombre = ""
    higer = 0
    i = 0

    while i <= len(cadena)-int(cantidad):
        
        nombre = cadena[i: int(cantidad)]

        if nombre in dic:
            dic[nombre]+=1
        
        else:
            dic[nombre] = 1

        if dic[nombre] > higer:
            
            higer = dic[nombre]
            aux_nombre = nombre

        i+=1

    print(dic)

    mensaje = stdin.readline().strip()
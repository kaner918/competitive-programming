#https://onlinejudge.org/external/100/10062.pdf
#10062

from sys import stdin

cadena = stdin.readline()

while cadena != "":

    dic = {}
    
    for i in range(len(cadena)-1):

        if ord(cadena[i]) not in dic:
            dic[ord(cadena[i])] = 1
        
        else:
            dic[ord(cadena[i])]+=1
    
    dicOrdenado = sorted(dic.items(), key=lambda x: (x[1], -x[0]))
    
    for i in dicOrdenado:
        print(i[0], i[1])

    cadena = stdin.readline()
    
    if cadena != "":
        print()

    
    
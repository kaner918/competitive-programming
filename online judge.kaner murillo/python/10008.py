#https://onlinejudge.org/external/100/10008.pdf
#10008

from sys import stdin 

lineas = int(stdin.readline().rstrip())
dic = {}

for i in range(lineas):

    linea = stdin.readline().rstrip('\n').upper()

    for i in range(len(linea)):

        if ord(linea[i]) >= ord('A') and ord(linea[i]) <= ord('Z'):

            if linea[i] not in dic:

                dic[linea[i]] = 1
            
            else:

                dic[linea[i]]+=1

dicOrdenado = sorted(dic.items(), key=lambda x: (-x[1], x[0]))

for i in dicOrdenado:

    print(i[0], i[1])

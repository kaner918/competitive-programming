#https://onlinejudge.org/external/1/119.pdf
#119
#varias operaciones y trucos con diccionarios fueron sacados del siguiente link: https://www.delftstack.com/es/howto/python/one-line-for-loop-python/#:~:text=...%20else%20.-,Bucle%20simple%20de%20una%20l%C3%ADnea%20for%20en%20Python,%2C%20matriz%2C%20conjunto%20o%20diccionario.

from sys import stdin 

cantidad = stdin.readline().strip()

while cantidad != "":

    dic = {}

    personas = stdin.readline().split()

    for i in personas:

        dic[i] = 0
    
    for i in range(int(cantidad)):

        transaccion = stdin.readline().split()

        if transaccion[1] != '0' and transaccion[2] != '0':

            dic[transaccion[0]] -= int(transaccion[1])-(int(transaccion[1])%int(transaccion[2]))
            
            for n in range(3,len(transaccion)):

                dic[transaccion[n]] += int(transaccion[1]) // int(transaccion[2]) 

    
    for key, val in dic.items():

        print(key,val)

    cantidad = stdin.readline().strip()

    if cantidad != "":

        print()
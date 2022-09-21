#https://onlinejudge.org/external/126/12650.pdf
#12650

from sys import stdin 

buzos = [int(x) for x in stdin.readline().split()]

while buzos != []:

    reporte = [int(x) for x in stdin.readline().split()]

    if buzos[0] != buzos[1]:

        dic = {}

        for i in range(buzos[0]):

            dic[i+1] = 0

        for i in range(buzos[1]):
            dic[reporte[i]] = 1

        cadena = []

        for i in dic:

            if dic[i] == 0:

                cadena.append(str(i))
                cadena.append(" ")

        print("".join(cadena))        
    
    else:
        print("*")

    buzos = [int(x) for x in stdin.readline().split()]
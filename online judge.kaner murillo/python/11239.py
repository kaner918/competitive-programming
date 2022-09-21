#https://onlinejudge.org/external/112/11239.pdf
#11239

from sys import stdin

cadena = stdin.readline().rstrip('\n')
dic = {}
vetados = []
clave = ""

while cadena != '0':

    if cadena == '1':

        sort = sorted(dic.items(), key = lambda x: (-len(x[1]), (x[0])))

        for i in sort:
            print(i[0], len(i[1]))
        
        dic = {}
        vetados = []

    else:

        if ord(cadena[0]) >= ord('A') and ord(cadena[0]) <= ord('Z'): 

            dic[cadena] = set()
            clave = cadena
        
        else:

            if cadena not in vetados:

                ans = False
 
                for i in dic:

                    if cadena in dic[i] and i != clave:

                        dic[i].remove(cadena)
                        vetados.append(cadena)
                        ans = True

                if ans == False:

                    dic[clave].add(cadena) 


    cadena = stdin.readline().rstrip('\n')

    
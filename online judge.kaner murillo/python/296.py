#https://onlinejudge.org/external/2/296.pdf
#https://www.udebug.com/UVa/296
#296

from sys import stdin

cases = int(stdin.readline().strip())

descartar = []
cadena = []

for i in range(cases):

    conjeturas = int(stdin.readline().strip())
    ans = False
    flag = False

    n = 0
    
    while n < cases and ans == False:
        
        conjectura = stdin.readline().rstrip('\n').split()

        if flag == False and (conjectura[1][0]!='0' or conjectura[1][2]!='0'):
            
            for x in conjectura[0]:
                cadena.append(x)
            
            flag = True 
        
        elif conjectura[1][0]=='0' and conjectura[1][2]=='0':

            for x in range(4):

                if conjectura[0][x] == cadena[x]:
                    cadena[x] = 'x'
                    
                    if conjectura[0][x] not in descartar:
                        descartar.append(conjectura[0][x])
        
        elif conjectura[1][0]=='0' and conjectura[1][2] != '0':

            for x in range(4):

                if conjectura[0][x] not in descartar and cadena[x] not in conjectura[0]:

                    descartar.append(cadena[x])
                    cadena[x] = conjectura[0][x]
                    
        
        n+=1
        print(cadena)

#https://onlinejudge.org/external/102/10260.pdf
#10260

from sys import stdin

cadena = stdin.readline().strip()
dic = {'1':('B', 'F', 'P', 'V'), '2':('C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'), '3':('D', 'T'), '4':('L'), '5':('M', 'N'), '6':('R')}

while cadena != "":

    cad = []
    anterior = '0'

    for i in range(len(cadena)):
        
        ans = False

        for n in dic:

            if cadena[i] in dic[n]: 
            
                if n!=anterior:

                    cad.append(n)
                    anterior = n
                    
                ans = True

        if ans == False:
            anterior = '0'    

    print("".join(cad))

    cadena = stdin.readline().strip()

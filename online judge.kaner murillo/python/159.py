#https://onlinejudge.org/external/1/159.pdf
#159

from sys import stdin 

cadena  = stdin.readline().rstrip('\n').split()

while cadena!=['#']:

    comproba = 0
    comproba2 = 0

    posicionMenor1 = len(cadena[0])
    posicionMenor2 = len(cadena[1])

    for i in range(len(cadena[0])):
        
        if cadena[0][i] in cadena[1]:

            comproba+=1
            n = 0
            ans = False

            while n<len(cadena[1]) and ans == False:
                
                if cadena[0][i] == cadena[1][n]:
                    
                    if i<posicionMenor1 and n<posicionMenor2:

                        posicionMenor1 = i
                        posicionMenor2 = n
                    
                    ans = True

                n+=1

    posicionMenor3 = len(cadena[2])
    posicionMenor4 = len(cadena[3])

    for i in range(len(cadena[2])):
        
        if cadena[2][i] in cadena[3]:

            comproba2+=1
            n = 0
            ans = False

            while n<len(cadena[3]) and ans == False:
                
                if cadena[2][i] == cadena[3][n]:
                    
                    if i<posicionMenor3 and n<posicionMenor4:

                        posicionMenor3 = i
                        posicionMenor4 = n
                    
                    ans = True

                n+=1

#QJZSAT HQ GNFALYJUVA YJWF

    if comproba>0 and comproba2>0:
        
        contador = 0

        if posicionMenor2>posicionMenor4:

            i = 0

            while i<(len(cadena[1])+len(cadena[3])) and (i<len(cadena[1]) or contador<=len(cadena[3])):

                if ((i<posicionMenor2 or i>posicionMenor2) and i<posicionMenor2-posicionMenor4) and (i<len(cadena[1]) or contador>len(cadena[3])-1):
                    print(" "*posicionMenor1+cadena[1][i])

                elif ((i<posicionMenor2 or i>posicionMenor2) or i<posicionMenor2-posicionMenor4) and (i<len(cadena[1]) and contador>len(cadena[3])-1):
                    print(" "*posicionMenor1+cadena[1][i])

                elif (i<posicionMenor2 or i>posicionMenor2) and i>=(posicionMenor2-posicionMenor4) and i< len(cadena[1]):
                    print(" "*posicionMenor1+cadena[1][i]+" "*(len(cadena[0])-posicionMenor1+posicionMenor3+2)+cadena[3][contador])
                    contador+=1

                elif i == posicionMenor2:
                    print(cadena[0]," ",cadena[2])
                    contador+=1

                elif i>=len(cadena[1])-1 and contador<=len(cadena[3])-1:
                    print(" "*(posicionMenor1+1)+" "*(len(cadena[0])-posicionMenor1+posicionMenor3+2)+cadena[3][contador])
                    contador+=1

                i+=1

        elif posicionMenor2<posicionMenor4:
            
            i = 0

            while i<(len(cadena[1])+len(cadena[3])) and (i<=len(cadena[1]) or contador<=len(cadena[3])):

                if ((i<posicionMenor4 or i>posicionMenor4) and i<posicionMenor4-posicionMenor2) or (i<len(cadena[3]) and contador>len(cadena[1])-1):
                    print(" "*(len(cadena[0])+posicionMenor3+3)+cadena[3][i])

                elif i == posicionMenor4:
                    print(cadena[0]," ",cadena[2])
                    contador+=1

                elif i>len(cadena[3])-1 and contador<len(cadena[1]):
                    print(" "*posicionMenor1+cadena[1][contador])
                    contador+=1 

                elif ((i<posicionMenor2 or i>posicionMenor2) or i>=(posicionMenor2-posicionMenor4)-1) and contador< len(cadena[1]): 
                    (print(" "*posicionMenor1+cadena[1][contador]+" "*(len(cadena[0])-posicionMenor1+posicionMenor3+2)+cadena[3][i]))
                    contador+=1
                i+=1

        else:

            i = 0

            while i<(len(cadena[3])+len(cadena[1])) and (i<len(cadena[1]) or contador<len(cadena[3])):

                if (i<posicionMenor2 or i>posicionMenor2) and (i<len(cadena[1]) and contador<len(cadena[3])):
                    print(" "*posicionMenor1+cadena[1][i]+" "*(len(cadena[0]) -posicionMenor1+posicionMenor3+2)+cadena[3][contador])
                    contador+=1

                elif i == posicionMenor2:
                    print(cadena[0]," ",cadena[2])
                    contador+=1
                
                elif contador>=len(cadena[3])-1 and i < len(cadena[1]):
                    print(" "*posicionMenor1+cadena[1][i])

                elif i>=len(cadena[1])-1 and contador<=len(cadena[3])-1:
                    print(" "*posicionMenor1+" "*(len(cadena[0])-posicionMenor1+posicionMenor3+3)+cadena[3][contador])
                    contador+=1  

                i+=1 
    
    else:
        print("Unable to make two crosses")
    
    
    cadena = stdin.readline().rstrip('\n').split()

    if cadena != ['#']:
        print("")

#https://onlinejudge.org/external/115/11586.pdf
#11586

from sys import stdin 

casos = int(stdin.readline().strip())

for i in range(casos):

    pista = stdin.readline().split()

    aux = list(pista)

    if len(pista) > 1:

        ans = True 
        aux.pop(0)
        pistaA = [pista[0]]

        n = 0

        while n < len(pista)-1 and ans == True:

            flag = False
            
            m = 0

            while m < len(aux) and flag == False:

                if pistaA[n][-1] != aux[m][0]:

                    pistaA.append(aux[m])
                    aux.pop(m)
                    flag = True
                    
                elif pistaA[n][-1] != aux[m][-1]:

                    pistaA.append(aux[m][::-1])
                    aux.pop(m)
                    flag = True

                m+=1
        
            if flag ==  False:

                ans  = False
        
            n+=1

        if ans == True and pistaA[0][0] != pistaA[-1][-1]:
            print("LOOP")
        
        else:

            print("NO LOOP")
    else:
        print("NO LOOP")
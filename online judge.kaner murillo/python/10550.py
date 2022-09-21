#Combination Lock
#https://onlinejudge.org/external/105/10550.pdf

clave = [int(x) for x in input().split()]

while clave!= [0,0,0,0]:

    suma = 120

    for i in range(1,len(clave)):

        contador = 0 

        if i==1:
            
            n = clave[0] 

            while n!=clave[1]:
                
                n-=1

                if n<0:
                    n=39
                
                contador+=1
            
            
            suma+=contador

    
        elif i==2:

            n = clave[1] 

            while n!=clave[2]:
                
                n+=1

                if n>39:
                    n=0
                
                contador+=1
            
            
            suma+=contador
        
        else:
            
            n = clave[2] 

            while n!=clave[3]:
                
                n-=1

                if n<0:
                    n=39
                
                contador+=1
            
            
            suma+=contador
    
    print(suma*9)

    clave = [int(x) for x in input().split()]
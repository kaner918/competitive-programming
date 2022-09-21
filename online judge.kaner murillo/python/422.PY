#https://onlinejudge.org/external/4/422.pdf
#422

from sys import stdin

#lectura de datos
filas = int(input())
lista = []

for i in range(filas):

    cadena = stdin.readline().rstrip('\n')
    lista.append(list(cadena))

#solucion
cadena = stdin.readline().rstrip('\n')

while cadena!='0':
    
    ans = 0
    i = 0

    while i < len(lista) and ans == 0:

        #para reducir la cantidad de operaciones, solo envaluo las listas que tienen la letra inicial de la palabra
        if(cadena[0] in lista[i]):
            n = 0
            while n<len(lista[i]) and ans==0:
                
                #buscar la palabra solo hacia delante
                if(cadena[0]==lista[i][n] and n+1<len(cadena)):
                    
                    x = n
                    contador = 0
                    palabra = ""
                    while contador < len(cadena) and x < len(lista[i]):
                        
                        palabra+=lista[i][x]
                        x+=1
                        contador+=1
                    
                    if(palabra==cadena):
                        ans = 1
                        print(f"{i+1},{n+1} {i+1},{x}")
                
                #encontrar la palabra hacia atras y adelante:
                
                elif(cadena[0] == lista[i][n] and n+1>=len(cadena)):
                    
                    x = n
                    contador = 0
                    palabra = ""
                    while contador < len(cadena) and x < len(lista[i]):
                        
                        palabra+=lista[i][x]
                        x+=1
                        contador+=1
                    
                    
                    if(palabra==cadena):
                        ans = 1
                        print(f"{i+1},{n+1} {i+1},{x}")

                    #si no lo encontro hacia adelante, evalua hacia atras
                    if ans ==0:

                        x = n
                        contador = 0
                        palabra = ""

                        while contador<len(cadena) and x >= 0:

                            
                            palabra += lista[i][x]
                            x-=1
                            contador+=1
                        
                        if palabra == cadena:
                            ans = 1
                            print(f"{i+1},{n+1} {i+1},{x+2}")
                    
                #de arriba hacia abajo
                if cadena[0]==lista[i][n] and n<len(lista[i]) and ans ==0:
                    
                    
                    x = i
                    contador = 0
                    palabra = ""
                    while contador<len(cadena) and x <len(lista):

                        palabra+=lista[x][n]
                        x+=1
                        contador+=1
                        
                    if(palabra==cadena):
                        ans = 1
                        print(f"{i+1},{n+1} {x},{n+1}")

                #diagonal de arriba hacia abajo - izquierda derecha
                if cadena[0]==lista[i][n] and n<len(lista[i]) and i+1<=len(cadena) and n+1<=len(cadena) and ans==0:
                    x = i
                    y = n
                    contador = 0

                    palabra = ""
                    
                    while contador<len(cadena) and x<len(lista) and y<len(lista[i]):

                        palabra+=lista[x][y]
                        x+=1
                        y+=1
                        contador+=1
                    
                    if palabra==cadena:
                        ans = 1
                        print(f"{i+1},{n+1} {x},{y}")
                
                #diagonal de abajo hacia arriba - derecha izquierda
                if cadena[0]==lista[i][n] and n<=len(lista[i]) and i+1>=len(cadena) and n+1>=len(cadena) and ans==0:

                    
                    x = i
                    y = n
                    contador = 0

                    palabra = ""
                    
                    while contador<len(cadena) and x<len(lista) and y<len(lista):
                        palabra+=lista[x][y]
                        
                        x+=1
                        y+=1
                        contador+=1
                    
                    if palabra==cadena:
                        ans = 1
                        print(f"{i+1},{n+1} {x},{y}")
                    
                    if ans ==0:
                        
                        x = i
                        y = n
                        contador = 0

                        palabra = ""
                        while contador<len(cadena) and x>=0 and y>=0:
                            
                            palabra+=lista[x][y]
                            x-=1
                            y-=1
                            contador+=1
                        
                        if palabra==cadena:
                            ans = 1
                            print(f"{i+1},{n+1} {x+2},{y+2}")
                
                if cadena[0]==lista[i][n] and n<len(lista[i]) and n+1>=len(cadena) and ans==0:

                    x = i
                    y = n
                    contador = 0

                    palabra = ""

                    while contador<len(cadena) and x<len(lista) and y>=0:

                        palabra+=lista[x][y]
                        x+=1
                        y-=1
                        contador+=1
                    
                    if palabra==cadena:
                        ans = 1
                        print(f"{i+1},{n+1} {x},{y+2}")
                
                if cadena[0]==lista[i][n] and n<len(lista[i]) and i+1>=len(cadena)and n+1<=len(cadena) and ans==0:
                  
                    x = i
                    y = n
                    contador = 0
                    palabra = ""

                    while contador<len(cadena) and x<len(lista) and y>=0:

                        palabra+=lista[x][y]
                        x+=1
                        y-=1
                        contador+=1
                    
                    if palabra==cadena:
                        ans = 1
                        print(f"{i+1},{n+1} {x},{y+2}")
                    
                    if ans == 0:

                        x = i
                        y = n
                        contador = 0

                        palabra = ""

                        while contador<len(cadena) and x>=0 and y<len(lista):

                            palabra+=lista[x][y]
                            x-=1
                            y+=1
                            contador+=1

                        if palabra==cadena:
                            ans = 1
                            print(f"{i+1},{n+1} {x+2},{y}")


                n+=1
        i+=1

    if ans == 0:
            print("Not found")

    cadena = stdin.readline().rstrip('\n')                     

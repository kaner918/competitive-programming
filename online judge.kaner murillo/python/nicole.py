###listas

##append ->agregar un elemento a la lista.
#len->tamaño del contenedor
#acceder a la posicion -> nombre[x]

number = int(input())

def drawTriangle(tamno):

    posicion = number-1
    flag = False

    for i in range(number*2-1):

        cad = ""
        
        for n in range(number):

            if n < posicion:

                cad+="O"
            
            else:

                cad+="X"
        
        if posicion ==  0:

            flag = True

        if flag == False:

            posicion-=1
        
        else:

            posicion+=1
        
        print(cad)
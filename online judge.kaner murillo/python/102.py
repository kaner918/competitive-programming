#102
#https://onlinejudge.org/external/1/102.pdf

from sys import stdin

cadena = stdin.readline().strip()

while cadena!="":
    
    suma = 0
    contador = 0

    colores  = [int(x) for x in cadena.split()]
    soluciones = []

    #BCG - 0           
    soluciones.append(colores[1] + colores[6]+colores[2]+colores[3]+colores[4]+colores[8])

    #BGC - 1
    soluciones.append(colores[1]+colores[3]+colores[2]+colores[6]+colores[5]+colores[7])

    #CBG - 2
    soluciones.append(colores[0] + colores[5]+colores[1]+colores[8]+colores[6]+colores[4])

    #CGB - 3
    soluciones.append(colores[1] + colores[5]+colores[0]+colores[8]+colores[3]+colores[7])

    #GBC - 4
    soluciones.append(colores[0] + colores[4]+colores[2]+colores[7]+colores[6]+colores[5])

    #GCB - 5
    soluciones.append(colores[2]+colores[4]+colores[0]+colores[7]+colores[8]+colores[3])

    menor = 0

    for i in range(1,len(soluciones)):

        if soluciones[i]<soluciones[menor]:
            menor = i
        
        elif soluciones[i]==soluciones[menor]:
            contador+=1

    if contador == 6 or menor == 0:
        print(f"BCG {soluciones[menor]}")

    elif menor ==1:
        print(f"BGC {soluciones[menor]}")

    elif menor ==2:
        print(f"CBG {soluciones[menor]}")

    elif menor ==3:
        print(f"CGB {soluciones[menor]}")

    elif menor ==4:
        print(f"GBC {soluciones[menor]}")

    else:
        print(f"GCB {soluciones[menor]}")

    cadena = stdin.readline().strip()

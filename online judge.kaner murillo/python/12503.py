#12503
#https://onlinejudge.org/external/125/12503.pdf

n = int(input())



for i in range(n):

    historial = []
    movimientos = int(input())
    posicion = 0

    for n in range(movimientos):
        movimiento = input()

        if "SAME AS" in movimiento:
            m = movimiento.split()
            movimiento=historial[int(m[2])-1]
            
        if movimiento=="LEFT":
            posicion-=1
            historial.append(movimiento)
        
        elif movimiento=="RIGHT":
            posicion+=1
            historial.append(movimiento)

    print(posicion)
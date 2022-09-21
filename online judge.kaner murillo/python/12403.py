#https://onlinejudge.org/external/124/12403.pdf
#12403

casos = int(input())
cuenta = 0

for i in range(casos):

    operacion = input().split()

    if operacion[0][0] == "d":
        cuenta+=int(operacion[1])
    
    else:
        print(cuenta)
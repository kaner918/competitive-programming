#https://onlinejudge.org/external/110/11093.pdf
#11093 Just Finish it up

casos = int(input()) 

for l in range(1,casos+1):
    
    estaciones = int(input())
    gasolina = []
    precio = []

    i = 0

    ans = False
    ans2 = 0

    suma = 0
    suma2 = 0

    while len(gasolina)< estaciones or len(precio)< estaciones:

        if len(gasolina)<estaciones:
            gasolina2=[int(x) for x in input().split()]
            gasolina.extend(gasolina2)
    
        else:
            precio2=[int(x) for x in input().split()]
            precio.extend(precio2)

    while i<estaciones and ans == False: #estaciones veces

        suma += gasolina[i] - precio[i]  #estaciones veces

        if gasolina[i] - precio[i]>=0 and ans2 == 0: #estaciones veces
            ans2 = i+1

        if ans2!= 0: #estaciones veces 
            suma2+= gasolina[i] - precio[i]

        if suma2<0:#estaciones veces 
            ans2 = 0
            suma2 = 0
                    
        i+=1 #estaciones veces

    if suma >= 0: #1
        ans = True


    if ans == True: #1
        print("Case %d: Possible from station %d"%(l,ans2))

    else: #1
        print("Case %d: Not possible"%l)

#https://onlinejudge.org/external/117/11764.pdf
#11764

casos = int(input())

for i in range(1,casos+1):

    n = int(input())

    mapa = [int(x)for x in input().split()]

    if n==1:
        print(f"Case {i}: 0 0")
    
    else:
        
        saltosA = 0
        saltosB = 0

        for x in range(n-1):

            if mapa[x]>mapa[x+1]:
                
                saltosB+=1
    
            elif mapa[x]<mapa[x+1]:
                saltosA+=1
                
        print(f"Case {i}: {saltosA} {saltosB}")


    
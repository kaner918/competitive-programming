#https://onlinejudge.org/external/117/11799.pdf
#11799

casos = int(input())

for i in range(1,casos+1):

    criaturas = [int(x)for x in input().split()]

    mayor = criaturas[1]

    for x in range(1,len(criaturas)):

        if criaturas[x]>mayor:
            mayor = criaturas[x]
    
    print(f"Case {i}: {mayor}")
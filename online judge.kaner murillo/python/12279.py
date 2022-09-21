#https://onlinejudge.org/external/122/12279.pdf
#12279

caso = int(input())
casos = 1
while caso!=0:

    motivos = [int(x) for x in input().split()]

    regalos = 0
    golosinas = 0

    for i in motivos:

        if i >0 and i<100:
            regalos+=1
        
        elif i==0:
            golosinas+=1
    
    print(f"Case {casos}: {regalos-golosinas}")
    casos+=1

    caso = int(input())
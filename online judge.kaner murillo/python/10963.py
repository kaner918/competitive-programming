#10963
#https://onlinejudge.org/external/109/10963.pdf

n = int(input())
for i in range(n):

    input()
    ans = "yes"
    columnas = int(input())

    fila = input().split()
    distancia1 = abs(int(fila[0])-int(fila[1]))
    m = 1

    while m<columnas:

        fila = input().split()

        if abs(int(fila[0])-int(fila[1]))!= distancia1:
            ans = "no"

        m+=1

    if i<n-1:
        print(ans)
        print("")
    else:
        print(ans)
        



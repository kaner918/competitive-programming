#https://onlinejudge.org/external/110/11044.pdf
#11044 

casos = int(input())

for i in range(casos):

    medidas = input().split()
    num1 = (int(medidas[0])//3)
    num2 = (int(medidas[1])//3)
    print(num1*num2)
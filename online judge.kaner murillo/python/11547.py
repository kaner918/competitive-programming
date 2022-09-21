#https://onlinejudge.org/external/115/11547.pdf
#11547 

casos = int(input())

for i in range(casos):

    numero = int(input())
    numero = ((((((numero*567)//9)+7492)*235)//47)-498)
    numero=str(numero)
    print(numero[-2])
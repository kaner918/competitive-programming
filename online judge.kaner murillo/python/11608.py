#https://onlinejudge.org/external/116/11608.pdf
#11608

from sys import stdin 

problemas = int(stdin.readline())
contador = 1

while problemas >= 0:

    adquiridos = [int(x) for x in stdin.readline().split()]
    necesarios = [int(x) for x in stdin.readline().split()]
    
    print(f"Case {contador}:")

    for i in range(12):

        if necesarios[i]<=problemas:
            
            print("No problem! :D")
            problemas-=necesarios[i]

        else:
            print("No problem. :(")
        
        problemas+=adquiridos[i]

    contador+=1

    problemas = int(stdin.readline())
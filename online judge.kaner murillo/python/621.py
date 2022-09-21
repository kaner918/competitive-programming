#https://onlinejudge.org/external/6/621.pdf
#621

from sys import stdin 

casos = int(stdin.readline().strip())

for i in range(casos):

    numeros  =  stdin.readline().rstrip('\n')

    if numeros == "1" or numeros == "4" or numeros == "78":
        print("+")

    elif numeros[-2:len(numeros)] == "35":
        print("-")
    
    elif (numeros[0] == "9" and numeros[-1]=="4") or numeros=="9":
        print("*")
    
    else:
        print("?")

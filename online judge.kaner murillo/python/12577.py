#12577
#https://onlinejudge.org/external/125/12577.pdf

cadena = input()
contador = 1
while cadena!="*":

    if cadena=="Hajj":
        print(f"Case {contador}: Hajj-e-Akbar")
    
    else:
        print(f"Case {contador}: Hajj-e-Asghar")
    
    cadena = input()
    contador+=1
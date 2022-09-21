#Language Detection
#https://onlinejudge.org/external/122/12250.pdf

cadena = input()
contador = 1

while cadena!="#":
    
    if cadena=="HELLO":
        print(f"Case {contador}: ENGLISH")

    elif cadena=="HOLA":
        print(f"Case {contador}: SPANISH")

    elif cadena=="HALLO":
        print(f"Case {contador}: GERMAN")

    elif cadena=="BONJOUR":
        print(f"Case {contador}: FRENCH")

    elif cadena=="CIAO":
        print(f"Case {contador}: ITALIAN")

    elif cadena=="ZDRAVSTVUJTE":
        print(f"Case {contador}: RUSSIAN")
    
    else:
        print(f"Case {contador}: UNKNOWN")
    cadena = input()
    contador+=1
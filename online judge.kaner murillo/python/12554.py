#https://onlinejudge.org/external/125/12554.pdf
#12554

from sys import flags, stdin 

cantidad = int(stdin.readline().strip())

palabras = ["Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"]
cantidadPalabras = 0
personas = []

for i in range(cantidad):

    personas.append(stdin.readline().rstrip('\n'))

contador = 0

for i in range(cantidad):

    if contador == 16:

        contador = 0

    print(f"{personas[i]}: {palabras[contador]}")

    contador+=1

n = 0

for i in range(contador,16):
    
    if n == cantidad:
        n = 0

    print(f"{personas[n]}: {palabras[i]}")

    n+=1
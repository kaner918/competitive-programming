#########variables.

## int
## string
## float
## boleanos - valores de verdad - > True or False.

'''
variable = 3
variable = 4
nombre = "kaner"
ans = True
### print ->imprimir por pantalla
### estructura de control
### operadores, ==, >, <, >=, <=, !=, and, or.

x = int(input())#cadena
y = int(input())

if y > 0 and x < 0:

    print("cuadrante 1")

elif y<0 and x<0:

    print("cuadrante 3")

elif y>0 and x>0:

    print("cuadrante 2")

else:

    print("cuadrante 4")

###### ciclos.
'''
#for.
'''
for i in range (2, 10, 2):
    print(i)

for i in range (1, 11):

    if i % 2 == 0:
        print(i)
'''
#while.

'''
while i<10:

    i = i + 1 

i = "hola"
n = 0

while i != "nicole":

    print("hola")

    if n == 11:

        i = "nicole"

    n = n + 1

'''

#numeros no primos.

lista = [1]
n = int(input())

for i in range(1, n+1):

    ans = False

    for n in range(2, i):

        if i % n == 0:

            ans = True
        
    if ans == True:

        lista.append(i)

print(lista)





     
    


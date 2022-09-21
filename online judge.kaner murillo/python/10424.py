#https://onlinejudge.org/external/104/10424.pdf
#10424

from sys import stdin

cadena = stdin.readline().strip().lower()


diccionario = {'a':1, 'b':2, 'c':3, 'd':4, 'e':5, 'f':6, 'g':7, 'h':8, 'i':9, 'j':10, 'k':11, 'l':12, 'm':13, 'n':14, 'o':15, 'p':16, 'q':17, 'r':18, 's':19, 't':20, 'u':21, 'v':22, 'w':23, 'x':24, 'y':25, 'z':26}

while cadena!="":
    cadena2 = stdin.readline().strip().lower()

    cantidadCadena1 = 0
    cantidadCadena2 = 0

    for i in cadena:
        if i in diccionario:
            cantidadCadena1+=diccionario[i]
        

    for i in cadena2:
        if i in diccionario:
            cantidadCadena2+=diccionario[i]
    
    sumacantidadCadena1 = 0
    sumacantidadCadena2 = 0

    while cantidadCadena1>0:
        
        sumacantidadCadena1+=cantidadCadena1%10

        cantidadCadena1//=10

        if cantidadCadena1 <= 0 and sumacantidadCadena1>9:
            cantidadCadena1 = sumacantidadCadena1
            sumacantidadCadena1 = 0
    
    while cantidadCadena2>0:

        sumacantidadCadena2+=cantidadCadena2%10
        cantidadCadena2//=10

        if cantidadCadena2 <= 0 and sumacantidadCadena2>9:
            cantidadCadena2 = sumacantidadCadena2
            sumacantidadCadena2 = 0

    
    if sumacantidadCadena1>sumacantidadCadena2:
       print("{:.2f} %".format((sumacantidadCadena2/sumacantidadCadena1)*100))
    
    elif sumacantidadCadena2>sumacantidadCadena1:
       print("{:.2f} %".format((sumacantidadCadena1/sumacantidadCadena2)*100))
    
    else:
       print("100.00 %")

    cadena = stdin.readline().strip().lower()
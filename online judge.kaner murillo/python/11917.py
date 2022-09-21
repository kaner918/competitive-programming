#https://onlinejudge.org/external/119/11917.pdf
#11917

from sys import stdin

casos = int(stdin.readline())

for i in range(1, casos+1):

    cantidadMaterias = int(stdin.readline())
    diccionario = {}

    for n in range(cantidadMaterias):

        materia = stdin.readline().split()
        diccionario[materia[0]] = materia[1]
    
    limiteTiempo = int(stdin.readline())
    tarea = stdin.readline().strip()  

    if tarea in diccionario and limiteTiempo>= int(diccionario[tarea]):
        print(f"Case {i}: Yesss")
    
    elif tarea in diccionario and limiteTiempo+5 >= int(diccionario[tarea]):
        print(f"Case {i}: Late")

    else:   
        print(f"Case {i}: Do your own homework!")
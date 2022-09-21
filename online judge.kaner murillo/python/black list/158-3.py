#https://onlinejudge.org/external/1/158.pdf
#158

from sys import stdin

def convertirCadena(lista,indice):

    retornar = []
    numero = [indice]
    nombre = []
    cadena = ""
    flag = False
    contador,i = 1,2

    while contador < 5:

        if contador < 4 and ord(lista[i]) == 32 and flag == True:
 
            numero.append(int(cadena))
            cadena = ""
            contador+=1
            flag = False

        elif contador < 4 and ord(lista[i]) != 32:

            cadena += lista[i]
            flag = True

        elif ord(lista[i]) != 32 and contador == 4:

            nombre.append(lista[slice(i,len(lista))])
            contador  = 5

        i+=1

    retornar.append(numero)
    retornar.append(nombre)

    return retornar

def calcularMenor(actual, mes, nuevoDia, recordatorio):

    if actual[2] != '12':

        if mes>recordatorio[0][2]:
            return 1
        
        elif mes==recordatorio[0][2]:
            if nuevoDia>=recordatorio[0][1]:
                return 1
    
    else:
        
        if mes==1:
            
            if recordatorio[0][2] == 12:
                return 1

            elif recordatorio[0][2] == mes:

                if recordatorio[0][1] <=nuevoDia:
                    return 1

        elif mes==recordatorio[0][2]:
            if nuevoDia>=recordatorio[0][1]:
                return 1     

    return 0

def calcular(actual, recordatorio,anio):

    mes = int(actual[2])
    nuevoDia = int(actual[1]) + recordatorio[0][3]
    estrellas = 0

    if((mes!= 12 and mes<recordatorio[0][2]) or ((mes!= 12 and mes==recordatorio[0][2]) and int(actual[1]) < recordatorio[0][1])):

        estrellas = recordatorio[0][1]- int(actual[1])-1
        
        if nuevoDia > 28 and mes == 2 and anio%4!=0:
            nuevoDia = nuevoDia-28
            mes+=1

            if recordatorio[0][2] > int(actual[2]):
                estrellas = 28- int(actual[1]) + recordatorio[0][1]-1

            else:
                estrellas = recordatorio[0][1]- int(actual[1])-1

        elif nuevoDia > 29 and mes == 2 and anio%4==0:
            nuevoDia = nuevoDia-29
            mes+=1

            if recordatorio[0][2] > int(actual[2]):
                estrellas = 29- int(actual[1]) + recordatorio[0][1]-1

            else:
                estrellas = recordatorio[0][1]- int(actual[1])-1

        elif nuevoDia >31 and (mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10):

            nuevoDia = nuevoDia - 31
            mes+=1

            if recordatorio[0][2] > int(actual[2]):
                estrellas = 31- int(actual[1]) + recordatorio[0][1]-1

            else:
                estrellas = recordatorio[0][1]- int(actual[1])-1

        return int(recordatorio[0][3] - estrellas), calcularMenor(actual, mes, nuevoDia, recordatorio)
 
    elif mes==12 and ((mes>recordatorio[0][2]) or (mes==recordatorio[0][2] and int(actual[1])<recordatorio[0][1])):
        
        estrellas = recordatorio[0][1]- int(actual[1])-1

        if nuevoDia > 31:

            nuevoDia = nuevoDia-31
            mes = 1

            if recordatorio[0][2] < int(actual[2]):
                estrellas = 31- int(actual[1]) + recordatorio[0][1]-1

            else:
                estrellas = recordatorio[0][1]- int(actual[1])-1

        return int(recordatorio[0][3] - estrellas), calcularMenor(actual, mes, nuevoDia, recordatorio)

    return 0,0

def armarCadena(lista,tipo):

    
    cad = []

    if lista[0][1] > 9:
        cad.append(" ")
        cad.append(str(lista[0][1])) 

    else:

        cad.append("  ")
        cad.append(str(lista[0][1]))      

    if lista[0][2] > 9:
        cad.append(" ")
        cad.append(str(lista[0][2]))
        cad.append(" ")
    
    else:
        cad.append("  ")
        cad.append(str(lista[0][2]))
        cad.append(" ")

    if tipo == 1:

        for i in range(7):

            if i<lista[-1]:
                cad.append("*")
            
            else:
                cad.append(" ")

        cad.append(" ")

        cad.extend(lista[1])
    
    else:

        cad.extend("*TODAY* ")
        cad.extend(lista[1])

    print("".join(cad))
    
def main():
     
    anio = int(stdin.readline().strip())
    indice = 0
    recordar = stdin.readline().rstrip('\n')
    recordatorios = []
    fechas = []
    contador = 0

    while recordar != '#':
        
        if recordar[0] == 'A':
            
            recordar = convertirCadena(recordar,indice)
            indice+=1
            recordatorios.append(recordar)
        
        else:
            fechas.append(recordar.split())
            contador+=1

        recordar =  stdin.readline().rstrip('\n')

    mesAnterior = int(fechas[0][2])

    contador2 = 0

    for i in fechas:

        respuesta = []             
        print("Today is: %2s %2s" %(i[1],i[2]))
        
        if(int(i[2])<mesAnterior):
            anio+=1

        for n in recordatorios:
            
            aux = list(n)

            if int(i[2]) == n[0][2] and int(i[1]) == n[0][1]:
                aux.append(calcular(i,n,anio)[0])
                respuesta.append(aux)
                
            elif calcular(i,n,anio)[1] == 1:
                
                aux.append(calcular(i,n,anio)[0])
                respuesta.append(aux)
        
        if i[2] == '12':

            respuesta.sort(key= lambda x: (-x[0][2], x[0][1], -x[-1], x[0][0]))

        else:

            respuesta.sort(key= lambda x: (x[0][2], x[0][1], -x[-1], x[0][0]))

        for n in respuesta:
            
            if n[2] == 0:
                armarCadena(n,0)
            
            else:
                armarCadena(n,1)

        if contador2 < contador-1:

            print()
        
        contador2+=1
        mesAnterior = int(i[2])
main()
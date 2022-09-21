#https://onlinejudge.org/external/1/158.pdf
#158

from sys import stdin

def convertirCadena(lista,indice):

    retornar = []
    numero = [indice]
    nombre = []
    numerito = ""
    ans = True
    contador = 0
    i = 0

    while ans == True:

        i+=1
        if ord('0') <= ord(lista[i]) <= ord('9'):
            ans = False
    
    
    for i in range(i,len(lista)):
        
        if ((ord('a')<= ord(lista[i]) <= ord('z')) or (ord('A')<= ord(lista[i]) <= ord('Z')) or ord('0') <= ord(lista[i]) <= ord('9')) and contador == 3:
            ans = True

        if (ord('0') <= ord(lista[i]) <= ord('9') or  contador<3) and ans==False: 
     
            if ord('0') <= ord(lista[i]) <= ord('9'):
                
                numerito+=lista[i]

            else:    
                
                if numerito !="":

                    numero.append(int(numerito))
                    contador+=1
                numerito = ""

        if ans == True:

            nombre.append(lista[i])
    
    retornar.append(numero)
    retornar.append(nombre)

    print(retornar)
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
        
        if nuevoDia > 28 and mes == 2 and (anio%4!=0 and (anio%100 == 0 or anio%400!=0)):
            nuevoDia = nuevoDia-28
            mes+=1

            if recordatorio[0][2] > int(actual[2]):
                estrellas = 28- int(actual[1]) + recordatorio[0][1]-1

            else:
                estrellas = recordatorio[0][1]- int(actual[1])-1

        elif nuevoDia > 29 and mes == 2 and (anio%4==0 and (anio%100 != 0 or anio%400==0)):
            nuevoDia = nuevoDia-29
            mes+=1

            if recordatorio[0][2] > int(actual[2]):
                estrellas = 29- int(actual[1]) + recordatorio[0][1]-1

            else:
                estrellas = recordatorio[0][1]- int(actual[1])-1

        elif nuevoDia >31 and (mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10):

            nuevoDia = nuevoDia-31
            mes+=1

            if recordatorio[0][2] > int(actual[2]):
                estrellas = 31- int(actual[1]) + recordatorio[0][1]-1

            else:
                estrellas = recordatorio[0][1]- int(actual[1])-1

        return int(recordatorio[0][3] - estrellas), calcularMenor(actual, mes, nuevoDia, recordatorio)
 
    if mes==12 and mes>recordatorio[0][2] or (mes==recordatorio[0][2] and int(actual[1])<recordatorio[0][1]):
        
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

    
    cad = [lista]
    cad2 = []

    if lista[0][1] > 9:
        cad2.append(" ")
        cad2.append(str(lista[0][1])) 

    else:

        cad2.append("  ")
        cad2.append(str(lista[0][1]))      

    if lista[0][2] > 9:
        cad2.append(" ")
        cad2.append(str(lista[0][2]))
        cad2.append(" ")
    
    else:
        cad2.append("  ")
        cad2.append(str(lista[0][2]))
        cad2.append(" ")

    if tipo == 1:

        for i in range(7):

            if i<lista[-1]:
                cad2.append("*")
            
            else:
                cad2.append(" ")

        cad2.append(" ")

        cad2.extend(lista[1])
    
    else:

        cad2.extend("*TODAY* ")
        cad2.extend(lista[1])
    
    cad.extend([cad2])
    return cad
    
def main():
     
    anio = int(stdin.readline().strip())
    indice = 0
    recordar =  stdin.readline().rstrip('\n')
    recordatorios = []
    fechas = []

    while recordar != '#':
        
        if recordar[0] == 'A':
            
            recordar = convertirCadena(recordar,indice)
            indice+=1
            recordatorios.append(recordar)
        
        else:
            fechas.append(recordar.split())

        recordar =  stdin.readline().rstrip('\n')

    ans = 1

    for i in fechas:

        respuesta = []             
        cad = ["Today is:"]

        if len(i[1])==2:
            cad.append(" ")
            cad.append(i[1]) 
                
        else:
            cad.append("  ")
            cad.append(i[1])

        if len(i[2])==2:
            cad.append(" ")
            cad.append(i[2])
                
        else:
            cad.append("  ")
            cad.append(i[2])
            

        print("".join(cad))
        
        if(int(i[2])==1) and ans == 1:
            anio+=1
            ans = 2
        
        elif (int(i[2])!=1) and ans == 2:
            ans = 1

        for n in recordatorios:
            
            if int(i[2]) == n[0][2] and int(i[1]) == n[0][1]:
                n.append(0)
                respuesta.append(armarCadena(n,0))
                
            
            elif calcular(i,n,anio)[1] == 1:
                
                n.append(calcular(i,n,anio)[0])
                respuesta.append(armarCadena(n,1))
        
        if i[2] == '12':

            respuesta.sort(key= lambda x: (-x[0][0][2], x[0][0][1], -x[0][-1], x[0][0][0] ))

        else:

            respuesta.sort(key= lambda x: (x[0][0][2], x[0][0][1], -x[0][-1], x[0][0][0] ))

        for n in respuesta:
            print("".join(n[1]))

        if i!= fechas[-1]:

            print()
main()
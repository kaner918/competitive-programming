#https://onlinejudge.org/external/1/158.pdf
#158

from sys import stdin

def calcularFecha(fecha,recordatorios,anio,ans):

    aux = list(fecha)
    Nuevodia = int(recordatorios[3])+int(fecha[1])
    calculo  = 0

    if Nuevodia >29 and fecha[2] == "2" and ((anio%4 == 0 and anio%100!=0) or anio%400==0):
        
        aux[1] = Nuevodia-29       
        aux[2] = int(aux[2])+1

        if recordatorios[2] > fecha[2]:

            calculo = 29-int(fecha[1]) + int(recordatorios[1])-1

        else:

            calculo = int(recordatorios[1]) - int(fecha[1])-1

    elif Nuevodia >28 and fecha[2] == "2" and (anio%4 != 0 and anio%400!=0):

        aux[1] = Nuevodia-28
        aux[2] = int(aux[2])+1

        if recordatorios[2] > fecha[2]:
            calculo = 28-int(fecha[1]) + int(recordatorios[1])-1
        else:

            calculo = int(recordatorios[1]) - int(fecha[1])-1

    elif Nuevodia >31 and (fecha[2] == "1" or fecha[2] == "3" or fecha[2] == "5" or fecha[2] == "7" or fecha[2] == "8" or fecha[2] == "10"):
                    
        aux[1] = Nuevodia-31
        aux[2] = int(aux[2])+1  

        if recordatorios[2] > fecha[2]:
            calculo = 31-int(fecha[1]) + int(recordatorios[1])-1

        else:
            calculo = int(recordatorios[1]) - int(fecha[1])-1

    elif Nuevodia>31 and fecha[2] == "12":
        
        aux[1] = Nuevodia-31
        aux[2] = 1
        if recordatorios[2] < fecha[2]:
            calculo = 31-int(fecha[1]) + int(recordatorios[1])-1
        else:
            calculo = int(recordatorios[1]) - int(fecha[1])-1

        anio+=1
        ans = False

    elif Nuevodia >30 and Nuevodia<=31 and (fecha[2] == "4" or fecha[2] == "6" or fecha[2] == "9" or fecha[2] == "11"):
        aux[1] = Nuevodia-30
        aux[2] = int(aux[2])+1
        if recordatorios[2] > fecha[2]:
            calculo = 30-int(fecha[1]) + int(recordatorios[1])-1
        else:

            calculo = int(recordatorios[1]) - int(fecha[1])-1

    else:

        aux[1] = Nuevodia
        aux[2] = int(aux[2])
        calculo = int(recordatorios[1]) - int(fecha[1])-1

    return aux,anio,ans,calculo

def main():

    anio = int(stdin.readline().strip())
    anio2 = anio
    calculo = 0
    ans = True
    
    cadena = stdin.readline().rstrip('\n')

    recordatorios = []
    fechas = []

    while cadena != "#":

        if cadena[0] == "A":

            recordatorios.append(cadena.split())   

        else:
            fechas.append(cadena.split())

        cadena = stdin.readline().rstrip('\n')

    for i in range(len(fechas)):

        respuestas = []
        cad = ["Today is:"]

        if len(fechas[i][1])==2:
            cad.append(" ")
            cad.append(fechas[i][1]) 
                
        else:
            cad.append("  ")
            cad.append(fechas[i][1])

        if len(fechas[i][2])==2:
            cad.append(" ")
            cad.append(fechas[i][2])
                
        else:
            cad.append("  ")
            cad.append(fechas[i][2])
            

        print("".join(cad))
        for n in range(len(recordatorios)):
            
            aux = list(fechas[i])

            if int(fechas[i][2]) == int(recordatorios[n][2]) and int(fechas[i][1]) == int(recordatorios[n][1]):
                
                aux,anio,ans,calculo = calcularFecha(fechas[i],recordatorios[n],anio,ans)

                cad = []

                if len(recordatorios[n][1])==2:
                    cad.append(" ")
                    cad.append(recordatorios[n][1]) 
                
                else:
                    cad.append("  ")
                    cad.append(recordatorios[n][1])

                if len(recordatorios[n][2])==2:
                    cad.append(" ")
                    cad.append(recordatorios[n][2])
                    cad.append(" ")
                else:
                    cad.append("  ")
                    cad.append(recordatorios[n][2])
                    cad.append(" ")
                cad.append("*TODAY*")
                cad2 = " "

                for x in range(4,len(recordatorios[n])-1):
                    cad2+=recordatorios[n][x]+" "
                    
                cad2 += recordatorios[n][-1]
                cad.append(cad2)
                recordatorios2 = list( recordatorios[n])
                recordatorios2.insert(0,calculo)

                respuestas.append([recordatorios2,cad])
                ans = True
            elif int(fechas[i][2]) < int(recordatorios[n][2]):

                aux,anio,ans,calculo = calcularFecha(fechas[i],recordatorios[n],anio,ans)
                
                cad = []

                if len(recordatorios[n][1])==2:
                    cad.append(" ")
                    cad.append(recordatorios[n][1]) 
                
                else:
                    cad.append("  ")
                    cad.append(recordatorios[n][1])

                if len(recordatorios[n][2])==2:
                    cad.append(" ")
                    cad.append(recordatorios[n][2])
                    cad.append(" ")
                else:
                    cad.append("  ")
                    cad.append(recordatorios[n][2])
                    cad.append(" ")
                for x in range(7):

                    if x<int(recordatorios[n][3])-calculo:

                        cad.append("*")
                        
                    else:
                        cad.append(" ")

                    cad2 = " "

                for x in range(4,len(recordatorios[n])-1):
                    cad2+=recordatorios[n][x]+" "
                    
                cad2 += recordatorios[n][-1]
                cad.append(cad2)

                if int(aux[2]) >  int(recordatorios[n][2]):
                    
                    recordatorios2 = list( recordatorios[n])
                    recordatorios2.insert(0,calculo)

                    respuestas.append([recordatorios2,cad])
                    
                elif int(aux[2]) ==  int(recordatorios[n][2]):
                    
                    if int(aux[1]) >=  int(recordatorios[n][1]):
                        recordatorios2 = list( recordatorios[n])
                        recordatorios2.insert(0,calculo)

                        respuestas.append([recordatorios2,cad])
                        
            elif int(fechas[i][2]) > int(recordatorios[n][2]):
                
                aux,anio,ans,calculo = calcularFecha(fechas[i],recordatorios[n],anio,ans)

                cad = []

                if len(recordatorios[n][1])==2:
                    cad.append(" ")
                    cad.append(recordatorios[n][1]) 
                
                else:
                    cad.append("  ")
                    cad.append(recordatorios[n][1])

                if len(recordatorios[n][2])==2:
                    cad.append(" ")
                    cad.append(recordatorios[n][2])
                    cad.append(" ")
                else:
                    cad.append("  ")
                    cad.append(recordatorios[n][2])
                    cad.append(" ")
                for x in range(7):

                    if x<int(recordatorios[n][3])-calculo:

                        cad.append("*")
                        
                    else:
                        cad.append(" ")

                    cad2 = " "

                for x in range(4,len(recordatorios[n])-1):
                    cad2+=recordatorios[n][x]+" "
                    
                cad2 += recordatorios[n][-1]
                cad.append(cad2)
                if int(aux[2]) >  int(recordatorios[n][2]) and ans ==False:

                    print(aux,recordatorios[n],ans)
                    recordatorios2 = list( recordatorios[n])
                    recordatorios2.insert(0,calculo)

                    respuestas.append([recordatorios2,cad])
                   
                elif int(aux[2]) ==  int(recordatorios[n][2]):
                    
                    if int(aux[1]) >=  int(recordatorios[n][1])and ans ==False:
                        recordatorios2 = list( recordatorios[n])
                        recordatorios2.insert(0,calculo)

                        respuestas.append([recordatorios2,cad])
                        
                ans = True      

            elif int(fechas[i][2]) == int(recordatorios[n][2]):

                if int(fechas[i][1]) <= int(recordatorios[n][1]):

                    aux,anio,ans,calculo = calcularFecha(fechas[i],recordatorios[n],anio,ans)

                    cad = []

                    if len(recordatorios[n][1])==2:
                        cad.append(" ")
                        cad.append(recordatorios[n][1]) 
                    
                    else:
                        cad.append("  ")
                        cad.append(recordatorios[n][1])

                    if len(recordatorios[n][2])==2:
                        cad.append(" ")
                        cad.append(recordatorios[n][2])
                        cad.append(" ")
                    else:
                        cad.append("  ")
                        cad.append(recordatorios[n][2])
                        cad.append(" ")
                        
                    for x in range(7):

                        if x<int(recordatorios[n][3])-calculo:

                            cad.append("*")
                            
                        else:
                            cad.append(" ")
                    cad2 = " "

                    for x in range(4,len(recordatorios[n])-1):
                        cad2+=recordatorios[n][x]+" "
                        
                    cad2 += recordatorios[n][-1]
                    cad.append(cad2)

                    if int(aux[2]) > int(recordatorios[n][2]):
                        recordatorios2 = list( recordatorios[n])
                        recordatorios2.insert(0,calculo)

                        respuestas.append([recordatorios2,cad])
                            
                    elif int(aux[2]) ==  int(recordatorios[n][2]):

                        if int(aux[1]) >=  int(recordatorios[n][1]):
                            recordatorios2 = list( recordatorios[n])
                            recordatorios2.insert(0,calculo)

                            respuestas.append([recordatorios2,cad])
                                
                    elif int(aux[2]) < int(recordatorios[n][2]) and ans == False:
                        recordatorios2 = list( recordatorios[n])
                        recordatorios2.insert(0,calculo)

                        respuestas.append([recordatorios2,cad])
                            
                        ans = True        
            
        if fechas[i][2] == '12':

            respuestas.sort(key= lambda x: (-int(x[0][3]), int(x[0][2]), -int(x[0][4])-x[0][0],recordatorios.index(x[0][1:len(x[0])])))

        else:

            respuestas.sort(key= lambda x: (int(x[0][3]), int(x[0][2]), -int(x[0][4])-x[0][0],recordatorios.index(x[0][1:len(x[0])])))
           
        for n in respuestas:
            print("".join(n[1]))
        
        if i<len(fechas)-1:
            print()
    
main()

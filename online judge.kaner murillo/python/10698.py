#https://onlinejudge.org/external/106/10698.pdf
#10698

from sys import stdin 

equipos, partidos = [int(x) for x in stdin.readline().split()]
equipo1,equipo2 = 0,0

while equipos != 0 or partidos != 0:

    lEquipos = []
    posicion = 1

    for i in range(equipos):

        lEquipos.append([stdin.readline().rstrip('\n'), 0, 0, 0, 0, 0, 0, 0.0])

    for i in range(partidos):

        partido = stdin.readline().split()

        n = 0
        ans = True 
        ans2 = True 

        while n<equipos:

            if lEquipos[n][0] == partido[0]:

                equipo1 = n
                ans = False

            elif lEquipos[n][0] == partido[4]:

                equipo2 = n
                ans2 = False 
            n+=1

        if int(partido[1])>int(partido[3]):

            puntosEquipo1 = 3
            puntosEquipo2 = 0
        
        elif int(partido[1])<int(partido[3]):
            
            puntosEquipo1 = 0
            puntosEquipo2 = 3
        
        else:
            puntosEquipo1 = 1
            puntosEquipo2 = 1

        lEquipos[equipo1][1]+=puntosEquipo1
        lEquipos[equipo1][2]+=1
        lEquipos[equipo1][3]+=int(partido[1])
        lEquipos[equipo1][4]+=int(partido[3])
        lEquipos[equipo1][5]=lEquipos[equipo1][3]-lEquipos[equipo1][4]
        lEquipos[equipo1][6]+=3
        lEquipos[equipo1][7]= (lEquipos[equipo1][1]*100.0)/lEquipos[equipo1][6]

        lEquipos[equipo2][1]+=puntosEquipo2
        lEquipos[equipo2][2]+=1
        lEquipos[equipo2][3]+=int(partido[3])
        lEquipos[equipo2][4]+=int(partido[1])
        lEquipos[equipo2][5]=lEquipos[equipo2][3]-lEquipos[equipo2][4]
        lEquipos[equipo2][6]+=3
        lEquipos[equipo2][7]= (lEquipos[equipo2][1]*100.0)/lEquipos[equipo2][6]


    lEquipos.sort(key=lambda x:(-x[1], -x[5], -x[3], x[0].lower()))

    for i in range(equipos):

        if i>0:

            if(lEquipos[i][1] == lEquipos[i-1][1] and lEquipos[i][5]==lEquipos[i-1][5] and lEquipos[i][3]==lEquipos[i-1][3]):
                
                if lEquipos[i][2] > 0:

                    print("%4s%15s%4d%4d%4d%4d%4d%7.2f"%(" ",lEquipos[i][0],lEquipos[i][1],lEquipos[i][2],lEquipos[i][3],lEquipos[i][4],lEquipos[i][5],lEquipos[i][7]))

                else:

                    print("%4s%15s   0   0   0   0   0    N/A" %(" ",lEquipos[i][0]))
            
            else:

                if lEquipos[i][2] > 0:

                    print("%2d. %15s%4d%4d%4d%4d%4d%7.2f"%(posicion,lEquipos[i][0],lEquipos[i][1],lEquipos[i][2],lEquipos[i][3],lEquipos[i][4],lEquipos[i][5],lEquipos[i][7]))
                
                else:

                    print("%2d. %15s   0   0   0   0   0    N/A" %(posicion,lEquipos[i][0]))
        else:

            if lEquipos[i][2] > 0:

                print("%2d. %15s%4d%4d%4d%4d%4d%7.2f" %(posicion,lEquipos[i][0],lEquipos[i][1],lEquipos[i][2],lEquipos[i][3],lEquipos[i][4],lEquipos[i][5],lEquipos[i][7]))
            
            else:

                print("%2d. %15s   0   0   0   0   0    N/A" %(posicion,lEquipos[i][0]))

        posicion+=1

    equipos, partidos = [int(x) for x in stdin.readline().split()]

    if(equipos != 0 or partidos!=0):
        print()
//https://onlinejudge.org/external/106/10698.pdf
//10698

#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

struct Equipo{

    string nombre;
    int puntos=0;
    int puntosR = 0;
    int partidos=0;
    int goles = 0;
    int golesR = 0;
    int diferencia = 0;
    double promedio = 0;

    Equipo(){}

    Equipo(string nom){

        nombre = nom;
    }

    bool operator< (Equipo &oth){

        bool ans;
        int i;

        if(puntos == oth.puntos){

            if(diferencia == oth.diferencia){

                if(goles == oth.goles){

                    string aux1 = nombre;
                    string aux2 = oth.nombre;


                    for (i = 0; i < aux1.length(); i++) {
    
                        aux1[i] = tolower(aux1[i]);
                    }
                    
                    for (i = 0; i < aux2.length(); i++) {
    
                        aux2[i] = tolower(aux2[i]);
                    }

                    ans = aux1 <aux2;
                }

                else{
                    
                    ans = goles>oth.goles;
                }
            }

            else{
                ans = diferencia>oth.diferencia;
            }
        }

        else{

            ans = puntos > oth.puntos;
        }

        return ans;
    }

};

int main(){

    int teams, games, i, n,golesEquipo1, golesEquipo2,posicion=1;
    double r,p;
    bool flag1, flag2;
    string name;
    char equipo1[16], equipo2[16];
    vector<Equipo>torneo;

    cin>>teams>>games;

    while(teams!= 0 || games != 0){

        torneo.clear();

        for(i=0; i<teams; ++i){

            cin >> name;

            torneo.push_back(Equipo(name));

        }

        for(i=0; i<games; ++i){
            
            flag1 = false;
            flag2 = false;
            
            scanf("%s %d - %d %s", equipo1, &golesEquipo1, &golesEquipo2, equipo2);
            
            n = 0;

            while(n<torneo.size() && (flag1 == false || flag2 == false)){

                if(torneo[n].nombre == equipo1){

                    if (golesEquipo1>golesEquipo2){
                        torneo[n].puntos+=3;
                    }

                    else if(golesEquipo1==golesEquipo2){
                        torneo[n].puntos+=1;
                    }

                    torneo[n].partidos+=1;
                    torneo[n].puntosR+=3;
                    torneo[n].goles+=golesEquipo1;
                    torneo[n].golesR+=golesEquipo2;
                    torneo[n].diferencia = torneo[n].goles-torneo[n].golesR;

                    p = torneo[n].puntos;
                    r = torneo[n].puntosR;
                    
                    torneo[n].promedio = (p*100.0)/r;

                    flag1 = true;
                }

                else if(torneo[n].nombre == equipo2){
                    
                    if (golesEquipo2>golesEquipo1){
                        torneo[n].puntos+=3;
                    }

                    else if(golesEquipo1==golesEquipo2){
                        torneo[n].puntos+=1;
                    }

                    torneo[n].partidos+=1;
                    torneo[n].puntosR+=3;
                    torneo[n].goles+=golesEquipo2;
                    torneo[n].golesR+=golesEquipo1;
                    torneo[n].diferencia = torneo[n].goles-torneo[n].golesR;

                    p = torneo[n].puntos;
                    r = torneo[n].puntosR;

                    torneo[n].promedio = (p*100.0)/r;

                    flag2 = true;
                }

                n+=1;
            }
        }

        sort(torneo.begin(), torneo.end());

        posicion = 1;
        
        for(i=0;i<torneo.size();i++){

                if(i>0){

                    if(torneo[i].puntos==torneo[i-1].puntos&&torneo[i].goles == torneo[i-1].goles&&torneo[i].diferencia==torneo[i-1].diferencia){
                        
                        if(torneo[i].partidos>0){

                            printf("    %15s%4d%4d%4d%4d%4d%7.2f\n", torneo[i].nombre.c_str(),torneo[i].puntos,torneo[i].partidos,torneo[i].goles,torneo[i].golesR,torneo[i].diferencia,torneo[i].promedio);
                        }

                        else{

                            printf("    %15s   0   0   0   0   0    N/A\n", torneo[i].nombre.c_str());

                        }
                        
                    }

                    else{
                        
                        if(torneo[i].partidos>0){

                            printf("%2d. %15s%4d%4d%4d%4d%4d%7.2f\n", posicion,torneo[i].nombre.c_str(),torneo[i].puntos,torneo[i].partidos,torneo[i].goles,torneo[i].golesR,torneo[i].diferencia,torneo[i].promedio);
                        }

                        else{

                            printf("%2d. %15s   0   0   0   0   0    N/A\n", posicion,torneo[i].nombre.c_str());

                        }
                    }
                }

                else{

                    if(torneo[i].partidos>0){

                        printf(" 1. %15s%4d%4d%4d%4d%4d%7.2f\n", torneo[i].nombre.c_str(),torneo[i].puntos,torneo[i].partidos,torneo[i].goles,torneo[i].golesR,torneo[i].diferencia,torneo[i].promedio);
                    }

                    else{

                        printf("%2d. %15s   0   0   0   0   0    N/A\n", posicion,torneo[i].nombre.c_str());

                    }
                }
                posicion+=1;
                }

        cin>>teams>>games;

        if(teams != 0 || games != 0){
            printf("\n");
        }
    }   

    return 0;   
}
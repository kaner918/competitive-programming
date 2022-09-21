//https://onlinejudge.org/external/102/10258.pdf
//10258

#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>

using namespace std;

struct Competidor{

    int id;
    int presentacion = 0;
    int tiempo = 0;
    int aceptados = 0;
    int resoluciones[9] = {0,0,0,0,0,0,0,0,0};

    Competidor(){}

    Competidor(int i){

        id = i;
    }

    bool operator< (Competidor &oth){

        bool ans;

        if(aceptados == oth.aceptados){

            if(tiempo == oth.tiempo){

                ans = id < oth.id;
            }

            else{
                ans = tiempo<oth.tiempo;
            }
          
        }
        
        else{
            ans = aceptados>oth.aceptados;
        }

        return ans;
    }

};

int main(){

    int id=0, ejercicio, tiempo,casos,i,n,m,x;
    char evaluacion;
    bool ans,ans2;
    string cadena;
    vector<Competidor>competidores;

    cin >>casos;
    cin.ignore();
    cin.ignore();

    for(i = 0; i<casos;i++){
        
        competidores.clear();

        for(n = 1; n<101; ++n){
            
            competidores.push_back(Competidor(n));
        }
    
        while(getline(cin,cadena)&& cadena.length() != 0){
            
            stringstream in(cadena);

            in>> id >>ejercicio >> tiempo>> evaluacion;

            competidores[id-1].presentacion = 1;

            if(competidores[id-1].resoluciones[ejercicio-1] != -1){

                if(evaluacion == 'C'){

                    competidores[id-1].tiempo+=tiempo+competidores[id-1].resoluciones[ejercicio-1];
                    competidores[id-1].resoluciones[ejercicio-1] = -1;
                    competidores[id-1].aceptados+=1;
                }

                else if(evaluacion == 'I'){

                    if(competidores[id-1].resoluciones[ejercicio-1]>=0){
                        competidores[id-1].resoluciones[ejercicio-1]+=20;
                    }
                }
            }

        }  

        sort(competidores.begin(), competidores.end());

        for(n = 0; n<competidores.size();n++){

            if(competidores[n].presentacion == 1){
                
                cout<<competidores[n].id<<" "<<competidores[n].aceptados<<" "<<competidores[n].tiempo<<endl;
            }
        }

        if(i<casos-1){
            printf("\n");
        }  
    }   
    return 0;
}

//https://onlinejudge.org/external/132/13293.pdf
//13293

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

struct Jugador{

    string nombre;
    int puntos;

    Jugador(){}
    Jugador(string nomb, int punt){

        nombre = nomb;
        puntos = punt;
    }

    bool operator< (Jugador &oth){

        bool ans;
        int i;

        if(puntos == oth.puntos){

            string aux1=nombre, aux2=oth.nombre;

            for(i = 0; i<aux1.length(); i++){

                aux1[i] = tolower(aux1[i]);
            }

            for(i = 0; i<aux2.length(); i++){

                aux2[i] = tolower(aux2[i]);
            }

            ans = aux1<aux2;
        }

        else{
            ans = puntos>oth.puntos;
        }

        return ans;
    }
};

int main(){

    int jugadores, i, n=1, m, puntos;
    vector<Jugador>Torneo;
    bool ans;
    string nomb,cadena,cadena2;

    while(scanf("%d\n", &jugadores)){
        
        Torneo.clear();

        for(m=0; m<jugadores; m++){
            
            getline(cin, cadena);
            nomb="";
            puntos = 0;
            ans = false;

            for(i=0; i<cadena.length()-1; i++){
                
                if(cadena[i]==';'){
                    ans = true;
                }

                if (ans == false){

                    nomb+=cadena[i];
                }

                else if(cadena[i]=='1' && cadena[i+1] == ';'){
                    puntos+=2;
                }

                else if(cadena[i]=='1' && cadena[i+1] != ';'){
                    puntos+=1;
                }
            }

            if(cadena.back()=='1'){
                puntos+=2;
            }

            Torneo.push_back(Jugador(nomb,puntos));
        }
        
        sort(Torneo.begin(), Torneo.end());

        printf("Case %d:\n", n);

        for(i=0; i<Torneo.size(); ++i){

            cout<<Torneo[i].nombre<<" "<<Torneo[i].puntos<<endl;
        }

        n++;
    }
    return 0;
}
//https://onlinejudge.org/external/6/612.pdf
//612

#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

struct Cadenas{

    string cadena;
    int inversiones = 0;
    int indice = 0;

    Cadenas(){}

    Cadenas(string cad, int cantidad, int ind){

        cadena = cad;

        int i,n,contador=0;
        for(i = 0; i<cantidad-1; i++){

            for(n = i+1; n<cantidad; n++){

                if(cadena[i]>cadena[n]){

                    contador+=1;
                }
            }
        }

        inversiones = contador;
        indice = ind;
    }

    bool operator< (Cadenas &oth){

        bool ans;

        if(inversiones==oth.inversiones){
            ans = indice < oth.indice;
        }

        else{
            ans = inversiones<oth.inversiones;
        }

        return ans;
    }
}; 
int main(){

    int casos,i,n,fila,columna;
    string blanco = "", cadena = "";

    cin>>casos;

    for(i=0; i<casos; ++i){

        scanf("\n");

        scanf("%d %d\n", &columna, &fila);

        vector<Cadenas>vecCad;

        for(n = 0; n<fila; n++){
            
            cin>>cadena;
            vecCad.push_back(Cadenas(cadena,columna,n));
        }

        sort(vecCad.begin(), vecCad.end());

        for(n = 0; n<vecCad.size(); n++){
            
            cout<<vecCad[n].cadena<<endl;
        }

        if(i<casos-1){
            printf("\n");
        }
    }

    return 0;
}
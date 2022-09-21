//https://onlinejudge.org/external/4/400.pdf
//400

#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main(){

    int lineas,i,n,m,cLetras,mayor,contador,columnas,filas,espacios;
    string cadena;
    vector<string>cadenas;

    while(cin>>lineas){
        
        cadenas.clear();
        mayor = 0;

        for(i = 0; i<lineas; ++i){

            cin>>cadena;

            if(cadena.length()>mayor){
                mayor = cadena.length();
            }
            cadenas.push_back(cadena);
        }

        sort(cadenas.begin(), cadenas.end());

        printf("------------------------------------------------------------\n");
        
        if (mayor>=59){
            columnas = 1;
        }

        else{
            
            columnas = 60/(mayor+2);
        }
    
        if(lineas%columnas==0){
            filas = lineas / columnas;
        } 

        else{

            filas = (lineas / columnas) + 1; 
        }

        for(i = 0; i<filas; ){

            string cadenas2;
            contador = 0;
            espacios = 0;
            m = i;

            while(contador < columnas && m<lineas){
                
                cadenas2+= cadenas[m];

                if(contador<columnas-1 && espacios+mayor+2<60 && m+filas<lineas){

                    for(n = 0; n<mayor+2-cadenas[m].length();n++){

                    cadenas2+=" ";
                    }
                }

                else{
                    for(n = 0; n<mayor-cadenas[m].length();n++){

                    cadenas2+=" ";
                    }
                }

                espacios+=mayor+2;
                contador ++;
                m+=filas;
            }
            
            cout<<cadenas2<<endl;
            i++;
        }
    }

    return 0;
}
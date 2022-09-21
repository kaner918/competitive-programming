//https://onlinejudge.org/external/110/11062.pdf
//11062
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Elementos{

    string cadena;
    int linea;

    Elementos(){}

    Elementos( string cad, int lin){

        cadena = cad;
        linea = lin;
    }  

};
int main(){

    int i, n, indice = 0;
    string palabra, nuevaPalabra = "", ultimaPalabra, linea;

    vector<string>resultado;
    stack<Elementos>diccionario;

    while(getline(cin,linea)){
        
        palabra = "";

        for(n = 0; n<linea.length(); n++){
            
            if((linea[n]>= 'a' && linea[n]<= 'z') || (linea[n]>= 'A' && linea[n]<= 'Z') || (linea[n] == '-')){

                palabra+=tolower(linea[n]);
            }

            if(((linea[n]< 'a' || linea[n]> 'z') && (linea[n]< 'A' || linea[n]> 'Z') && linea[n] != '-') || n == linea.length()-1){

                if(!diccionario.empty()){

                    ultimaPalabra = diccionario.top().cadena;

                    if(ultimaPalabra.back() == '-' && diccionario.top().linea != indice){
                        
                        for(i = 0; i<ultimaPalabra.length()-1; i++){
                            
                            nuevaPalabra+=ultimaPalabra[i];
                        }

                        nuevaPalabra+=palabra;

                        diccionario.pop();
                        diccionario.push(Elementos(nuevaPalabra, indice));;
                        nuevaPalabra = "";
                    }

                    else{
                        
                        diccionario.push(Elementos(palabra, indice));;
                    }

                }

                else{

                    diccionario.push(Elementos(palabra, indice));
                }
                palabra = "";
            }
        } 

        indice++;
              
    }
    
    while(!diccionario.empty()){

        resultado.push_back(diccionario.top().cadena);
        diccionario.pop();
    }

    sort(resultado.begin(), resultado.end());

    for(i = 1; i<resultado.size(); i++){

        if(resultado[i] != resultado[i-1]){

            printf("%s\n", resultado[i].c_str());

        }
    }
    return 0;
}
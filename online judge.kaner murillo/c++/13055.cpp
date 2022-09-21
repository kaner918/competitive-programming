//https://onlinejudge.org/external/130/13055.pdf
//13055

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    int i, n, consultas;
    stack<string>viajes; 
    string cadena, accion, nombre;
    bool ans;

    scanf("%i\n", &consultas);

    for(i = 0; i<consultas; i++){
        accion = "";
        nombre = "";
        ans = false;

        getline(cin, cadena);

        for(n = 0; n<cadena.length(); n++){

            if(cadena[n] == 32){
                
                ans = true;
            }

            if(ans == false && cadena[n] != 32){

                accion+=cadena[n];
            }

            else if(ans == true && cadena[n] != 32){

                nombre+=cadena[n];
            }
        }

        if(accion == "Sleep"){

            viajes.push(nombre);
        }

        else if(accion == "Kick"){

            if(!viajes.empty()){

                viajes.pop();
            }

        }

        else{

            if(!viajes.empty()){

                printf("%s\n", viajes.top().c_str());
            }

            else{

                printf("Not in a dream\n");
            }
        }
    }

    return 0;
}
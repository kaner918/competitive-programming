#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

int contador;

using namespace std;

bool comparar(int a, int b){

    bool ans;

    if(a>b){
        
        contador++;
        
    }

    return a>b;
}

int main(){

    int cantidad, v,i,aux,x;
    string cadena;
    vector<int>numeros;
    bool ans, flag, flag2;

    
    while(cin>>cantidad && cantidad != 0){

        numeros.clear();

        for(i = 0; i<cantidad; i++){

            cin>>v;
            numeros.push_back(v);
        }   

        ans = true;
        flag = false;
        contador = 0;

        while(ans == true){

            flag2 = false;
            i = 0;
            contador++;

            while(flag2 == false && i<numeros.size()-1){

                if(numeros[i] > numeros[i+1]){

                    aux = numeros[i];
                    numeros[i] = numeros[i+1];
                    numeros[i+1] = aux;

                    if(flag == false){
                        flag = true;
                    }

                    else{
                        flag = false;
                    }

                    flag2 = true;
                                
                }

                i++;
            }

            for(x = 0; x<numeros.size(); x++){
                printf("%i ", numeros[x]);

            }

            printf("\n");

            if(i == numeros.size()-1 && flag2 == false){

                ans = false;
            }
        }

        if(flag == false){
            printf("%i - Marcelo\n", contador);
        }   

        else{
            printf("%i - Carlos\n", contador);
        }
    }
    
    return 0;
}
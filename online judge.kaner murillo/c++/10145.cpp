//https://onlinejudge.org/external/101/10145.pdf
//10145

#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct Elemento{

    char tipo;
    int indicador;
    int elemento;

    Elemento(){}

    Elemento(char t, int i, int e){

        tipo = t;
        indicador = i;
        elemento = e; 
    }

};

int main(){

    int i, casos, indicador, elemento;
    char tipo;
    bool ans;
    vector<int>denegados;

    scanf("%i", &casos);

    while(casos--){

        cin.ignore();

        deque<Elemento>lista;
        denegados.clear();

        while(cin>>tipo && tipo!='#'){

            scanf("%i %i", &indicador,&elemento);

            if(lista.empty()){

                lista.push_back(Elemento(tipo, indicador, elemento));
                printf("GRANTED\n");

            }
            
            else{
                
                ans = false;
                
               auto result = find(denegados.begin(), denegados.end(), indicador);

                if( result != end(denegados)){

                    printf("IGNORED\n");
                }

                else{

                    for(i = 0; i<lista.size() && ans == false; i++){

                        if(lista[i].elemento == elemento){

                            if(lista[i].indicador != indicador && (lista[i].tipo == 'X' || tipo == 'X')){

                                printf("DENIED\n");
                                denegados.push_back(indicador);
                                ans = true;
                            }
                        }
                    }

                    if(ans == false){
                        printf("GRANTED\n");
                        lista.push_back(Elemento(tipo, indicador, elemento));
                    }
                }
                
            }
        }      

        if(casos+1>1){
            printf("\n");
        }
    }
    return 0;
}
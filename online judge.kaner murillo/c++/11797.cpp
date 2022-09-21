//https://onlinejudge.org/external/117/11797.pdf
//11797

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Viajero{

    string nombre;
    queue<string>cola;
    int tiempo=0;

    Viajero(){}
    Viajero(string nom){
        nombre = nom;
    }
};
int main(){

    int casos, i, n, m, tiempo, tiempoTotal,cantidadLista, contador;
    string nombre,nombreLista;
    vector<Viajero>viajeros;
    bool ans;

    scanf("%i", &casos);
    
    for(i=1; i<casos+1; i++){

        contador = 0;
        viajeros.clear();

        viajeros.push_back(Viajero("Ja"));
        viajeros.push_back(Viajero("Sam"));
        viajeros.push_back(Viajero("Sha"));
        viajeros.push_back(Viajero("Sid"));
        viajeros.push_back(Viajero("Tan"));

        scanf("%i %i", &tiempo, &tiempoTotal);
        cin>>nombre;

        for(n = 0; n<5; n++){
            
            scanf("%i", &cantidadLista);

            for(m=0; m<cantidadLista; m++){

                cin>>nombreLista;
                viajeros[n].cola.push(nombreLista);
            }
        }
        
        while(contador<tiempoTotal){

            ans = false;

            for(m=0; m<viajeros.size() && ans==false; m++){
                
                if(viajeros[m].nombre == nombre){
                    
                    if(contador+tiempo<tiempoTotal){
                        
                        viajeros[m].tiempo+=tiempo;
                        nombre = viajeros[m].cola.front();
                        viajeros[m].cola.pop();
                        viajeros[m].cola.push(nombre);

                        contador+=tiempo+2;

                    }

                    else{

                        viajeros[m].tiempo+=tiempoTotal-contador;
                        contador+=tiempo;
                    }

                    ans = true;
                }
            } 
        }

        printf("Case %i:\n", i);
        for(n = 0; n<viajeros.size(); n++){
        
            printf("%s %i\n", viajeros[n].nombre.c_str(), viajeros[n].tiempo);
        }
    }
    return 0;
}
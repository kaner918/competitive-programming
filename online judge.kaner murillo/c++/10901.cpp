//https://onlinejudge.org/external/109/10901.pdf
//10901

#include<queue>
#include<cstdio>
#include<iostream>
#include<string>
#include<deque>

using namespace std;

struct Carro{

    int tiempo;
    int indice;

    Carro(){}
    Carro(int tiemp, int ind){
        tiempo = tiemp;
        indice = ind;
    }

};

int main(){

    int casos, cantidad, tiempo, cantidadCarros, acomulado, llegada,contador,i;
    string posicion;
    bool ans;
    

    scanf("%i", &casos);

    while(casos--){

        scanf("%i %i %i", &cantidad, &tiempo, &cantidadCarros);
        queue<Carro>izquierda;
        queue<Carro>derecha;
        deque<int>respuesta;

        i = 0;

        while(cantidadCarros--){
        
            cin>>llegada>>posicion;
            
            if(posicion == "left"){
                izquierda.push(Carro(llegada,i));
            }

            else{
                derecha.push(Carro(llegada,i));
            }
            
            respuesta.push_back(i);
            i+=1;

        }   

        acomulado = 0;
        
        if(!izquierda.empty() && !derecha.empty() && izquierda.front().tiempo<derecha.front().tiempo){
            
            acomulado = izquierda.front().tiempo;
            
        }

        else if(!izquierda.empty() && !derecha.empty() && izquierda.front().tiempo>derecha.front().tiempo){

            acomulado = derecha.front().tiempo;
        }

        else if(!izquierda.empty()){
            acomulado = izquierda.front().tiempo;
        }

        else if(!derecha.empty()){
            acomulado = derecha.front().tiempo;
        }
        
        contador = 0;
        ans = false;

        while(!izquierda.empty() || !derecha.empty()){

            if(ans == false){

                if(!izquierda.empty() && izquierda.front().tiempo <= acomulado){

                    contador = 0;

                    while(!izquierda.empty() && izquierda.front().tiempo<=acomulado && contador<cantidad){

                        respuesta[izquierda.front().indice] = acomulado+tiempo;
                        izquierda.pop();
                        contador+=1;
                    }
                    acomulado+=tiempo;
                    ans = true;
                }

                else if(!derecha.empty() && derecha.front().tiempo<=acomulado){
                    acomulado+=tiempo;
                    ans = true;
                }

                else{
                    acomulado+=1;
                }
                
            }

            else{

                if(!derecha.empty() && derecha.front().tiempo <= acomulado){

                    contador = 0;

                    while(!derecha.empty() && derecha.front().tiempo<=acomulado && contador<cantidad){

                        respuesta[derecha.front().indice] = acomulado+tiempo;
                        derecha.pop();
                        contador+=1;
                    }
                    acomulado+=tiempo;
                    ans = false;
                }

                else if(!izquierda.empty() && izquierda.front().tiempo<=acomulado){
                    acomulado+=tiempo;
                    ans = false;
                }

                else{
                    acomulado+=1;
                }
            }
        }

        for(i = 0; i<respuesta.size(); i++){
            printf("%i\n", respuesta[i]);
        }

        if(casos>0){
            printf("\n");
        }
    }
    return 0;
}
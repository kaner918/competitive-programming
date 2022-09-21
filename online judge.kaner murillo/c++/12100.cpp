//https://onlinejudge.org/external/121/12100.pdf
//12100

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Impresora{

    int prioridad;
    int indice;

    Impresora(){}

    Impresora(int ho, int in){
        prioridad = ho;
        indice = in;
    }
};

int main(){

    int i, n, m, casos, mayor, mayor2, cantidad, objetivo,v,contador;
    bool ans;
    Impresora actual,aux;
    
    scanf("%i", &casos);

    for(i = 0; i<casos; i++){

        scanf("%i %i", &cantidad, &objetivo);

        if(cantidad == 1){
            scanf("%i", &v);
            printf("1\n");
        }

        else{

            mayor = 0;
            mayor2 = 0;
            contador = 1;
            queue<Impresora>impresiones;
            ans = false;
            for(n = 0; n<cantidad; n++){

                scanf("%i", &v);
                impresiones.push(Impresora(v,n));
                
                if(v>mayor){
                    mayor = v;

                }

            }

            while(!impresiones.empty() && ans == false){

                actual  = impresiones.front();
                
                if(actual.prioridad == mayor){
                    
                    if (actual.indice == objetivo){
                        ans = true;
                    } 

                    else{
                        
                        impresiones.pop();
                        contador++;
                        mayor = 0;

                        for(m = 0; m<impresiones.size();m++){
                            
                            aux = impresiones.front();

                            if(aux.prioridad > mayor){
                                mayor = aux.prioridad;
                            }

                            impresiones.pop();
                            impresiones.push(aux);
                        }         
                    }
                }

                else{
                    
                    impresiones.pop();
                    impresiones.push(actual);
                }
            }

            printf("%i\n",contador);
        }

    }
    return 0;
}
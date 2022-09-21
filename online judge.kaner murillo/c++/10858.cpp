//https://onlinejudge.org/external/108/10858.pdf
//10858

#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

int main(){

    int numero, divisor,i,n, m,aux, aux2, contador;
    bool ans;
    string cadena;
    vector<int>opcion;
    
    while(scanf("%i", &numero) && numero != 0){

        i = 2;
        vector<string>Respuesta;
        stack<int>multiplos;
        deque<int>primos;
        contador = 0;
        ans = false;

        while(i<numero){
            
            if(numero%i == 0){
               
                if(ans == false){

                    multiplos.push(i);
                    aux = numero;
                    n = i;

                    while(aux > 1){

                        if(aux%n == 0){

                            primos.push_back(n);
                            aux = aux/n;
                        }

                        else{

                            n+=1;
                        }
                    }

                    ans = true;
                }

                else{

                    multiplos.push(i);

                }
            }

            i+=1;

        }
        
        
        while(!multiplos.empty()){
        
            ans = false,
            i = 0;
            aux2 = multiplos.top();
            
            cout<<multiplos.top()<<" ";
            
            while(ans == false){

                for(i; i<primos.size(); i++){
                    
                    n = i;
                    opcion.clear();
                    aux = multiplos.top();
                    
                    while(aux<numero && n<primos.size()){

                        opcion.push_back(primos[n]);
                        aux = aux * primos[n];

                        n+=1;
                    }
                    
                    opcion.push_back(aux2);
                    
                    if(aux == numero){
                        cadena = "";
                        sort(opcion.begin(), opcion.end());
                        
                        for(m = 0; m<opcion.size()-1; m++){
                            
                            cadena+=to_string(opcion[m]);
                            cadena+=" ";
                        }
                        
                        cadena+=to_string(opcion.back());
                        
                        Respuesta.push_back(cadena);
                        
                        ans = true;
                    }
                }
            }

            multiplos.pop();
        }
        
        cout<<endl;
        
        sort(Respuesta.begin(), Respuesta.end());
        
        cout<<Respuesta[0]<<endl;
        
        for(i = 1; i<Respuesta.size(); i++){
            
            if(Respuesta[i] != Respuesta[i-1]){
                cout<<Respuesta[i]<<endl;
            }
            
        }
    }

    return 0;
}
//https://onlinejudge.org/external/111/11111.pdf
//11111

#include<cstdio>
#include<iostream>
#include<stack>
#include<deque>
#include<cmath>
#include<string>
#include<sstream>

using namespace std;

struct Munequita{

    int numero;
    int contador = 0;

    Munequita(){}

    Munequita(int num){
        numero = num;
    }
};

int  main(){

    int v, i, n, contador, eliminado;
    string cadena;
    bool ans;

    while(getline(cin,cadena)){

        deque<int>muneca;
        stack<Munequita>secuencia;

        ans = true;
        n = 0;

        if(cadena.length()>0){

            stringstream stk(cadena);

            while(stk>>v){
                muneca.push_back(v);
            }

            if(muneca.size() > 1){

                while(n<muneca.size() && ans == true){

                    if(muneca[n] < 0){

                        if(secuencia.size() > 0){
                           
                            if(!secuencia.empty()){

                                if(abs(muneca[n])<abs(secuencia.top().numero)){

                                    secuencia.top().contador+=abs(muneca[n]);
                                    secuencia.push(Munequita(muneca[n]));
                                }

                                else{
                                    ans = false;
                                }
                            }
                        }
                        
                        else{
                            secuencia.push(Munequita(muneca[n]));
                        }
                    }

                    else{

                            if(abs(secuencia.top().numero) == muneca[n]){
                                
                                if(secuencia.top().contador >= abs(secuencia.top().numero)){
                                    
                                    ans = false;
                                }
                                secuencia.pop();
                            }

                            else{

                                ans = false;
                            }              
                    }

                    n+=1;
                }
            }

            else{
                ans = false;
            }
    }

    else{

        ans = true;
    }

    if(ans==true && secuencia.empty()){
                
            printf(":-) Matrioshka!\n");
        }
            
    else{
        
        printf(":-( Try again.\n");
    }
    }
    return 0;
}
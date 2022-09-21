//https://onlinejudge.org/external/119/11995.pdf
//11995


#include<queue>
#include<stack>
#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int evaluaciones, codigo, numero;
    bool flag1,flag2,flag3;

    while(scanf("%i", &evaluaciones)!=EOF){

        flag1 = true;
        flag2 = true;
        flag3 = true;

        queue<int>cola;
        stack<int>pila;
        priority_queue<int>colaPrioritaria;

        while(evaluaciones--){
            
            scanf("%i %i", &codigo, &numero);

            if(codigo == 1){

                cola.push(numero);
                pila.push(numero);
                colaPrioritaria.push(numero);
            }

            else{

                if(!cola.empty()){

                    if(cola.front() != numero){

                        flag1 = false;
                    }

                    else{

                        cola.pop();

                    }
                }

                else{

                    flag1 = false;
                }

                if(!pila.empty()){

                    if(pila.top() != numero){

                        flag2 = false;
                    }

                    else{
                        
                        pila.pop();
                            
                    }
                }

                else{

                    flag2 = false;
                }

                if(!colaPrioritaria.empty()){

                    if(colaPrioritaria.top() != numero){

                        flag3 = false;
                    }

                    else{

                        colaPrioritaria.pop();

                    }
                }

                else{
                    flag3 = false;
                }
            }
        }

        if((flag1 == true && flag2 == true && flag3 == true) || (flag1 == false && flag2 == true && flag3 == true) || (flag1 == true && flag2 == false && flag3 == true) || (flag1 == true && flag2 == true && flag3 == false)){

            printf("not sure\n");
        }

        else if(flag1 == true && flag2 == false && flag3 == false){

            printf("queue\n");
        }

        else if(flag1 == false && flag2 == true && flag3 == false){

            printf("stack\n");
        }

        else if(flag1 == false && flag2 == false && flag3 == true){

            printf("priority queue\n");
        }

        else{

            printf("impossible\n");

        }
        
    }

    return 0;
}
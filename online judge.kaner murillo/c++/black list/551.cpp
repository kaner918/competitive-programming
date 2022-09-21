#include<stack>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    int contador, i;
    string cadena, nomb, letra1, letra2;  
    bool ans;

    while(getline(cin,cadena)){

        ans = true;
        i = 0;
        contador = 0;

        stack<string>pila;
        
        while(i<cadena.size() && ans == true){
            
            letra1 = cadena[i];

            if(letra1 == "("){

                pila.push(letra1);
            }
            
            else if(letra1 == "["){

                pila.push(letra1);
            }

            else if(letra1 == "{"){

                pila.push(letra1);
            }

            else if(letra1 == "<"){

                pila.push(letra1);
            }

            else if(letra1 == "*" && pila.top() == "("){
                
                pila.top()+="*";
                
            }

            if(letra1 == ")"){

                if(i>0){

                    letra2 = cadena[i-1];

                    if(!pila.empty() && pila.top() == "(*" && letra2 == "*"){
                        pila.pop();
                    }

                    else if(!pila.empty() && pila.top() == "(" && letra2 != "*"){
                        pila.pop();
                    }

                    else{
                        ans = false;
                    }
                }
                
                else{

                    if(!pila.empty() && pila.top() == "("){
                        pila.pop();
                    }

                    else{
                        ans = false;
                    }
                }
            }

            else if(letra1 == "]"){

                if(!pila.empty() && pila.top() == "["){
                    pila.pop();
                }

                else{
                    ans = false;
                }
            }

            else if(letra1 == "}"){

                if(!pila.empty() && pila.top() == "{"){
                    pila.pop();
                }

                else{
                    ans = false;
                }
            }

            else if(letra1 == ">"){

                if(!pila.empty() && pila.top() == "<"){
                    pila.pop();
                }

                else{
                    ans = false;
                }
            }

            i+=1;
            contador+=1;
        } 

        if(!pila.empty()){
            ans = false;
        }

        if(ans == true){
            printf("YES\n");
        }

        else{
            printf("NO %i\n", i);
        }
    }
    return 0;
}
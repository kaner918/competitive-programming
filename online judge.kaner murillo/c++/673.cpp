//https://onlinejudge.org/external/6/673.pdf
//673

#include<cstdio>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){

    int casos, i;
    bool ans;
    string cadena, letra;


    scanf("%i", &casos);
    cin.ignore();

    while(casos--){

        ans = true;
        stack<string>pila;

        getline(cin,cadena);

        i = 0;

        while(i<cadena.length() && ans == true){
            
            letra = cadena[i];

            if(letra == "[" || letra == "("){
                pila.push(letra);
            }

            else if(letra == "]" || letra == ")"){

                if(!pila.empty() && pila.top() == "[" && letra == "]"){
                    pila.pop();
                }

                else if(!pila.empty() && pila.top() == "(" && letra == ")"){
                    pila.pop();
                }

                else{
                    ans = false;
                }
            }
            i+=1;
        }

        if(!pila.empty()){
            ans = false;
        }

        if(ans == true){
            printf("Yes\n");
        }

        else{
            printf("No\n");
        }
    }
    return 0;
}
//https://onlinejudge.org/external/119/11988.pdf
//11900

#include<cstdio>
#include<deque>
#include<iostream>
#include<stack>
using namespace std;

int main(){

    string cadena;
    int i;
    bool ans;

    while(getline(cin,cadena)){

        ans = false;
        deque<char>lista;
        for(i=0; i<cadena.length(); i++){

            if(cadena[i] == '['){
                i++;
                stack<char>cola;
                while(cadena[i] != '[' and cadena[i] != ']' and i<cadena.length()){

                    cola.push(cadena[i]);
                    i++;
                }

                while(cola.size()>0){

                    lista.push_front(cola.top());
                    cola.pop();
                }

                if(cadena[i] == '['){
                    i-=1;
                }
            }

            else if(cadena[i] != ']' && cadena[i] != '['){

                lista.push_back(cadena[i]);
            }

        }

        for(i = 0; i<lista.size(); i++){
            printf("%c", lista[i]);
        }

        printf("\n");
    }
    return 0;
}
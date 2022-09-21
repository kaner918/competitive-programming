//https://onlinejudge.org/external/117/11786.pdf
//11786

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){

    int cases, i, contador, acomulado;
    string cad;
    int letter;

    scanf("%i", &cases);
    cin.ignore();

    while(cases--){

        getline(cin,cad);
        stack<int>valleys;

        contador = 0;

        for(i = 0; i < cad.length(); i++){

            letter = cad[i];

            if(letter == 92){

                valleys.push(0);
            }

            else if(letter == 47 && !valleys.empty()){

                acomulado = valleys.top()+1;
                valleys.pop();

                if(!valleys.empty()){

                    valleys.top()+=acomulado+1;
                }
                
                contador+=acomulado;
            }
            
            else if(letter ==  95 && !valleys.empty()){

                valleys.top()+=1;
                
            }

        }

        printf("%i\n", contador);
    }
    return 0;
}
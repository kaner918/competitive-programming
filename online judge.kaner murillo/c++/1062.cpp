#include<vector>
#include<stack>
#include<cstdio>
#include<iostream>
#include<string>


using namespace std;

struct Pilas{

    stack<char>pila;
    
    Pilas(){}
    Pilas(char letra){

        pila.push(letra);
    }
};

int main(){

    int i,n,contador = 1;
    string cadena;
    vector<Pilas>pilas;
    bool ans;

    while(getline(cin,cadena) && cadena!="end"){

        pilas.clear();
        
        for(i = 0; i<cadena.size(); i++){

            ans = false;

            for(n = 0; n<pilas.size() && ans == false; n++){

                if(cadena[i]<=pilas[n].pila.top()){
                    pilas[n].pila.push(cadena[i]);
                    ans = true;
                }
            }

            if(ans == false){
                pilas.push_back(Pilas(cadena[i]));
            }
        }

        printf("Case %i: %i\n", contador,pilas.size());
        contador+=1;

    }

    return 0;
}
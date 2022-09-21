#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){


    int cantidad, v, i;
    string cadena;
    vector<int>numeros;

    while(scanf("%i", &cantidad) && cantidad != 0){

        cin.ignore();
        
        getline(cin,cadena);

        stringstream stk(cadena);
        numeros.clear();

        while(stk>>v){
            numeros.push_back(v);
        }

        sort(numeros.begin(), numeros.end());

        for(i = 0; i<numeros.size()-1; i++){
            printf("%i ", numeros[i]);
        }

        printf("%i\n", numeros.back());

    }

    return 0;
}
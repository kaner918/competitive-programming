#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int mod;

bool comparar(int a, int b){

    bool ans;

    if(a%mod == b%mod){

        if(a%2 != 0 && b%2 !=0){
            ans = a>b;
        }
    
        else if(a%2 != 0 && b%2 == 0){
            ans = true;
        }

        else if(a%2 == 0 && b%2 != 0){
            ans = false;
        }

        else{
            ans = a<b;
        }
    }

    else{

        ans = a%mod < b%mod;
    }
    

    return ans;
}

int main(){

    int cantidad, i, v;
    vector<int>numeros;

    while(scanf("%i %i", &cantidad, &mod), cantidad != 0 || mod != 0){

        numeros.clear();
        
        for(i = 0; i<cantidad; i++){

            scanf("%i", &v);
            numeros.push_back(v);
        }

        sort(numeros.begin(), numeros.end(), comparar);

        printf("%i %i\n", cantidad, mod);

        for(i = 0; i<numeros.size(); i++){
            printf("%i\n", numeros[i]);
        }
        
    }

    printf("0 0\n");

    return 0;
}

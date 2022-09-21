//https://onlinejudge.org/external/110/11039.pdf
//11039

#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

bool comparar(int numero1, int numero2){

    bool ans;

    ans = abs(numero1)>abs(numero2);

    return ans;
}

int main(){

    int cases,i,n,m,flat,flats;

    cin>>cases; 

    for(i = 0; i<cases; ++i){
        
        int contador;

        cin>>flats;
        vector<int>building(flats);

        for(n = 0; n<flats; ++n){

            cin>>flat;
            building.push_back(flat);

        }
        sort(building.begin(), building.end(),comparar);

        if(flats == 0){
            printf("0\n");
        }

        else{
            
            contador = 1;
            for(n = 0; n<flats-1; n++){

                if ((building[n]<0 && building[n+1] >0 || building[n]>0 && building[n+1] <0) && abs(building[n])>abs(building[n+1])){
            
                    contador+=1;
                }
            }
            
            printf("%i\n", contador);
        }
        
    }

    return 0;
}
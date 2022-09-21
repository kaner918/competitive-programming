// 11764
// https://onlinejudge.org/external/117/11764.pdf

#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;

int main(){
    int casos,paredes,i,j,altura,arriba,abajo;
    scanf("%i",&casos);
    vector<int>alturas;

    for(i=1;i<casos+1;i++){
        scanf("%i",&paredes);
        alturas.clear();
        arriba = 0;
        abajo = 0;

        for(j=0;j<paredes;j++){

            scanf("%i",&altura);
            alturas.push_back(altura);
        }

        for(j=0;j<paredes-1;j++){

            if(alturas[j]>alturas[j+1]){
                
                arriba+=1;
            }

            else if(alturas[j]<alturas[j+1]){
                abajo+=1;
            }
        }
        
        printf("Case %i: %i %i\n",i ,abajo ,arriba);
    }
    return 0;
}
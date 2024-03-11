//https://onlinejudge.org/external/110/11003.pdf
//11003

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int weight[1002], load[1002], tab[1002][3002];

int solve(int size_boxes, int maxi){

    int i, j, aux;

    for(i = 0; i<=maxi; i++){
        tab[0][i] = 0;
    }

    for(i = 1; i<=size_boxes; i++){
        for(j = 0; j<=maxi; j++){
            
            if(j<=load[i-1]){
                aux = 1;
                if(j+weight[i-1]<=maxi){
                    aux+= tab[i-1][j+weight[i-1]];
                }

                tab[i][j] = max(tab[i-1][j], aux);
            }

            else{
                tab[i][j] = tab[i-1][j];
            }
        }
    }

    return tab[size_boxes][0];
}

int main(){

    int size_boxes, i, j, maxi;

    while(scanf("%i", &size_boxes) && size_boxes){
        maxi = 0;
        for(i = 0; i<size_boxes; i++){
            scanf("%i %i", &weight[i], &load[i]);
            maxi = max(maxi, load[i]);
        }

        printf("%i\n", solve(size_boxes, maxi));

    }

    return 0;
}
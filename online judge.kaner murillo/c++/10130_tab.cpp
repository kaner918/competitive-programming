//https://onlinejudge.org/external/101/10130.pdf
//10130

#include<cstdio>
#include<iostream>

using namespace std;

int prices[1002], weights[1002], weightsPeople[102], tab[1002][32];

void dp(int n, int find){

    int i, j;

    for(i = 0; i<=find; i++){
        tab[0][i] = 0;
    }

    for(i = 1; i<=n; i++){
        for(j = 0; j<=find; j++){
            tab[i][j] = tab[i-1][j];
            if(weights[i-1]<=j){
                tab[i][j] = max(tab[i][j], tab[i-1][j-weights[i-1]] + prices[i-1]);
            }
        }
    }
}

int main(){

    int cases, objects, peoples, i, j, sums, maxi;

    scanf("%i", &cases);

    while(cases--){
        sums = 0;
        maxi = 0;

        scanf("%i", &objects);

        for(i = 0; i<objects; i++){
            scanf("%i %i", &prices[i], &weights[i]);
        }

        scanf("%i", &peoples);

        for(i = 0; i<peoples; i++){
            scanf("%i", &weightsPeople[i]);
            maxi = max(maxi, weightsPeople[i]);
        }
        
        dp(objects, maxi);

        for(i = 0; i<peoples; i++){
            sums+=tab[objects][weightsPeople[i]];
        }
        printf("%i\n", sums);
    }

    return 0;
}
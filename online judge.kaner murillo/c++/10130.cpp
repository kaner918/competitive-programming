//https://onlinejudge.org/external/101/10130.pdf
//10130

#include<cstdio>
#include<iostream>

using namespace std;

int prices[1002], weights[1002], weightsPeople[102], mem[1002][32];

int dp(int n, int find){

    int ans;

    if(mem[n][find] != -1){
        ans = mem[n][find];
    }

    else{

        if(!n){
            ans = 0;    
        }
        else{
            int a = 0, b = 0;

            a = dp(n-1, find);
            
            if(weights[n-1] <= find){
                b = dp(n-1, find-weights[n-1]) + prices[n-1];
            }

            ans = max(a, b);
        }

        mem[n][find] = ans;
    }

    return ans;
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

        for(i = 0; i<= objects; i++){
            for(j = 0; j<= maxi; j++){
                mem[i][j] = -1;
            }
        }
        
        for(i = 0; i<peoples; i++){
            sums+=dp(objects, weightsPeople[i]);
        }
        printf("%i\n", sums);
    }

    return 0;
}
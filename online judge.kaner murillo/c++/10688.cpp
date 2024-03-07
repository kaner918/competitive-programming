//https://onlinejudge.org/external/106/10688.pdf
//10688

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int mem[502][502];

int dp(int l, int r, int k){

    int ans = INT_MAX;

    if(mem[l][r] != INT_MAX){
        ans = mem[l][r];
    }

    else{

        if(r-l+1 == 1){
            ans = 0;
        }

        else if(r-l+1 == 2){
            ans = (l+k) * 2;
        }

        else if(r-l+1 == 3){
            ans = (l+1+ k) * 3;
        }

        else{

            int i;

            for(i = l; i<=r; i++){
                ans = min((r-l+1) * (i+k) + dp(l, i-1+(i==l), k) + dp(i+1-(i==r), r, k), ans);
            }   

        }

        mem[l][r] = ans;
    }
    
    return ans;
}   

int main(){

    int cases, apples, k, m, i, j;

    scanf("%i", &cases);

    for(i = 1; i<=cases; i++){

        scanf("%i %i", &apples, &k);

        for(j = 0; j<=apples; j++){
            for(m = 0; m<=apples; m++){
                mem[j][m] = INT_MAX;
            }
        }

        printf("Case %i: %i\n", i, dp(1, apples, k));
    }


    return 0;
}
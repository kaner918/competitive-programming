//https://onlinejudge.org/external/108/10819.pdf
//10819

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int prices[101], benefits[101], mem[102][14002];

int dp(int i, int n, int sums, int money){

    int ans;

    if(mem[i][sums] != -1){
        ans = mem[i][sums];
    }

    else{
        if((sums > money && money <= 1800) || (sums > money + 200)){
            ans = -600;
        } 

        else if(i == n){

            ans = 0;
            if(sums>money && sums<=2000){
                ans = -600;
            }
        }

        else{

            ans = max(dp(i+1, n, sums, money), dp(i+1, n, sums+prices[i], money) + benefits[i]);
        }

        mem[i][sums] = ans;
    }

    return ans;
}

int main(){

    int money, items, i, j;

    while(scanf("%i %i", &money, &items) != EOF){
        
        for(i = 0; i<=items; i++){
            if(i<items){
                scanf("%i %i", &prices[i], &benefits[i]);
            }
            for(j = 0; j<=14002; j++){
                mem[i][j] = -1;
            }
        }

        printf("%i\n", dp(0, items, 0, money));
    }


    return 0;
}
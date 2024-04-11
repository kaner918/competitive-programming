//https://cses.fi/problemset/task/1633

#include<cstdio>
#include<iostream>

using namespace std;

int mem[1000002][7];
const int M = 1e9+7;

int dp(int num, int dice){

    int ans = 0;

    if(mem[num][dice] != -1){
        ans = mem[num][dice];
    }

    else{
        if(!num){
            ans = 1;
        }
        else{
            int i;
            for(i = 1; i<7; i++){
                if(num-i>-1){
                    ans = (ans + dp(num-i, i))%M;
                }
            }
            mem[num][dice] = ans;
        }
    }

    return ans;
}

int main(){

    int num, i, j;
    scanf("%i", &num);

    for(i = 0; i<=num; i++){
        for(j = 0; j<7; j++){
            mem[i][j] = -1;
        }
    }

    printf("%i\n", dp(num, 0));

    return 0;
}
//https://onlinejudge.org/external/106/10690.pdf
//10690

#include<cstdio>
#include<iostream>

using namespace std;

int arr[102], mem[102][2501][2501];

int dp(int index, int size, int n, int m){

    int ans;

    if(mem[index][n][m] != -1){
        ans = mem[index][n][m];
    }

    else{
        
        if(index == size){
        
        }
    }
}

int main(){

    int n, m, i, j, k, maxi;

    while(scanf("%i %i", &n, &m) != EOF){
        maxi = 0;
        for(i = 0; i<n+m; i++){
            scanf("%i", &arr[i]);
            maxi+=arr[i];
        }

        for(i = 0; i<n+m; i++){
            for(j = 0; j<=maxi; j++){
                for(k = 0; k<=maxi; k++){
                    mem[i][j][k] = -1;
                }
            }
        }

    }

    return 0;
}
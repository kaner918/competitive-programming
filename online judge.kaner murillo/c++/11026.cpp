//https://onlinejudge.org/external/110/11026.pdf
//11026

#include<cstdio>
#include<iostream>

using namespace std;

int arr[1001], M;
long long int mem[1001][1001], sums[10001];

long long int dp(int n, int k){

    long long int ans;

    if(mem[n][k] != -1){
        ans = mem[n][k];
    }
    else{
        if(!n){
            ans = 0;
        }
        else if(k==1){
            ans = sums[n-1];
        }
        else{
            ans = (dp(n-1, k) + arr[n-1] * dp(n-1, k-1))%M;
        }
        mem[n][k] = ans;
    }
    return ans;
}

int main(){

    int size, i, j;
    long long int ans, acu;

    while(scanf("%i %i", &size, &M) && (size || M)){
        acu = 0;
        ans = 0;
        for(i = 0; i<size; i++){
            scanf("%i", &arr[i]);
            acu+=arr[i];
            acu%=M;
            sums[i] = acu;
        }

        for(i = 0; i<=size; i++){
            for(j = 0; j<=size; j++){
                mem[i][j] = -1;
            }
        }

        for(i = 1; i<=size; i++){
            ans = max(ans, dp(size, i));
        }
        printf("%i\n", ans);
    }

    return 0;
}
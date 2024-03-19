//https://onlinejudge.org/external/106/10690.pdf
//10690

#include<cstdio>
#include<iostream>
#include<map>
#include<tuple>
#include<climits>

using namespace std;

int arr[102], tab[10002][51];

void solve(int n, int counter, int sums){

    int i, j, k, index;

    for(i = 0; i<=sums; i++){      
        for(j = 0; j<= counter; j++){
            tab[i][j] = 0;
        }
    }

    tab[0][0] = 1;

    for(i = 0; i<n; i++){
        for(j = sums; j>arr[i]-1; j--){
            for(k = 1; k<=counter; k++){
                tab[j][k]|= tab[j-arr[i]][k-1];
            }
        }
    }
}

int main(){

    int n, m, i, sums, mini, maxi;

    while(scanf("%i %i", &n, &m) != EOF){
        
        sums = 0;
        mini = INT_MAX;
        maxi = INT_MIN;

        for(i = 0; i<n+m; i++){
            scanf("%i", &arr[i]);
            arr[i]+=51;
            sums+=arr[i];
        }

        solve(n+m, n, sums);
        
        for(i = 0; i<=sums; i++){
            if(tab[i][n]){
                maxi = max(maxi, ((sums-(51*(n+m)))-(i-51*n))*(i-51*n));
                mini = min(mini, ((sums-(51*(n+m)))-(i-51*n))*(i-51*n));

            }
        }
        printf("%i %i\n", maxi, mini);
    }

    return 0;
}
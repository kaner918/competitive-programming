//https://cses.fi/problemset/task/1638

#include<cstdio>
#include<iostream>

using namespace std;

const int M = 1e9+7;
char grid[1002][1002];
long long int table[1002][1002];

int main(){

    int n, i, j;
    scanf("%i", &n);

    for(i = 0; i<n; i++){
        cin.ignore();
        for(j = 0; j<n; j++){
            scanf("%c", &grid[i][j]);
        }
    }

    if(grid[0][0]!='*' && grid[n-1][n-1]!='*'){
        
        table[n-1][n-1] = 1;

        for(i = n-1; i>-1; i--){
            for(j = n-(1+(i==n-1)); j>-1; j--){
                if(grid[i][j+1] != '*'){
                    table[i][j] = (table[i][j] + table[i][j+1])%M;
                }
                if(grid[i+1][j] != '*'){
                    table[i][j] = (table[i][j] + table[i+1][j])%M;
                }
            }
        }
    }

    printf("%lld\n", table[0][0]);

    return 0;
}
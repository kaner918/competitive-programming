//https://cses.fi/problemset/task/1158

#include<cstdio>
#include<iostream>

using namespace std;

const int M = 1e8 + 7;
int books[1002], prices[1002], table[M];

int main(){

    int i, j, n, x;

    scanf("%i %i", &n, &x);

    for(i = 0; i<n; i++){
        scanf("%i", &prices[i]);
    }

    for(i = 0; i<n; i++){
        scanf("%i", &books[i]);
    }

    for(i = 0; i<n; i++){
        for(j = x; j>=prices[i]; j--){
            table[j] = max(table[j], table[j-prices[i]]+books[i]);
        }
    }

    printf("%i", table[x]);

    return  0;
}   
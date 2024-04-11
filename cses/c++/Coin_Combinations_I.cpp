//https://cses.fi/problemset/task/1634

#include<cstdio>
#include<iostream>

const int M = 1e9+7;
int arr[102];
long long int tab[1000002];

int main(){ 

    int n, x, i, j;
    
    scanf("%i %i", &n, &x);

    for(i = 0; i<n; i++){
        scanf("%i", &arr[i]);
    }

    tab[0] = 1;

    for(i = 1; i<=x; i++){
        for(j = 0; j<n; j++){
            if(i-arr[j] > -1){
                tab[i] = (tab[i]+tab[i-arr[j]])%M;
            }
        }
    }

    printf("%lld\n", tab[x]);

    return 0;
}
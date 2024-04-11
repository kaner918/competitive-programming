//https://cses.fi/problemset/task/1634

#include<cstdio>
#include<iostream>

int arr[102];
long long int tab[1000002];

int main(){ 

    int n, x, i, j;

    scanf("%i %ni", &n, &x);

    for(i = 0; i<n; i++){
        scanf("%i", &arr[i]);
    }
    tab[0] = 0;

    for(i = 1; i<=x; i++){
        tab[i] = 1e6+1;
        for(j = 0; j<=n; j++){
            if(i-arr[j] > -1){
                tab[i] = std::min(tab[i], tab[i-arr[j]]+1);
            }
        }
    }
    if(tab[x]>=1e6+1){
        printf("-1\n");
    }
    else{
        printf("%lld\n", tab[x]);
    }

    return 0;
}
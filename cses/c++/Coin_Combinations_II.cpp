//https://cses.fi/problemset/task/1636/
 
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
 
    for(i = 0; i<n; i++){
        for(j = 1; j<=x; j++){
            if(j-arr[i] > -1){
                tab[j] = (tab[j]+tab[j-arr[i]])%M;
            }
        }
    }
 
    printf("%lld\n", tab[x]);
 
    return 0;
}

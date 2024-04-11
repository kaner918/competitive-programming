//https://cses.fi/problemset/task/1637

#include<cstdio>
#include<iostream>

int tab[1000002];

int main(){ 

    int n, i, j;
    
    scanf("%i", &n);

    for(i = 1; i<=n; i++){
        tab[i] = 1e6;
        for(j = i; j>0; j/=10){
            if(i-(j%10) > -1){
                tab[i] = std::min(tab[i], tab[i-(j%10)]+1);
            }
        }
    }

    printf("%i\n", tab[n]);

    return 0;
}
//https://cses.fi/problemset/task/1071

#include<cstdio>
#include<iostream>

int main(){

    int cases;
    long long int x, y;

    scanf("%i", &cases);

    while(cases--){
        scanf("%lld %lld", &x, &y);

        if(x%2 == 0){
            printf("%lld\n", x*x - (y-1));
        }
        else{ 
            x--;
            printf("%lld\n", (x*x+1) - (y-1));
        }
    }
    return 0;
}

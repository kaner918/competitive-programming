//https://onlinejudge.org/external/123/12324.pdf
//12324
//solucion implementada en python, terminar esta.

#include<cstdio>
#include<iostream>
#include<climits>
#include<map>

using namespace std;

int travels[101], feces[101];

int dp(int index, int size, int sizeFeces){

    if(index == size){
        return 0;
    }

    else if(memo[index] != -1){
        return memo[index];
    }

    else{

        int a, b = INT_MAX;

        a = travels[index] + dp(index+1, size, sizeFeces+feces[index]);

        if(sizeFeces){
            b = (travels[index] / 2) + dp(index+1, size, sizeFeces+feces[index]-1);
        }

        memo[index] = min(a, b);
        return memo[index];
    }
}

int main(){

    int size, i;

    while(scanf("%i", &size) && size){

        for(i = 0; i<size; i++){
            scanf("%i %i", &travels[i], &feces[i]);
            memo[i] = -1;
        }

        memo[0] = travels[0];
        printf("%i\n", travels[0] + dp(1, size, feces[0]));
    }

    return 0;
}
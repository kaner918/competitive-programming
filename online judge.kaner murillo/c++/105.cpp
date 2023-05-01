//https://onlinejudge.org/external/1/105.pdf
//105

#include<cstdio>
#include<iostream>

using namespace std;

int arr[10001];

int main(){

    int x, y, height, i, low = 10001, hight = 0;

    for(i = 0; i< 10001; i++){

        arr[i] = 0;
    }

    while(scanf("%i %i %i", &x, &height, &y) != EOF){
        
        low = min(low, x);
        hight = max(hight, y);
        i = x;

        if(x!=low){
            i = x+1;
        }

        for(i; i<=y; i++){

            if(arr[i] < height){

                arr[i] = height;
            }
        }
    }
    
    printf("%i", low);

    for(i = low+1; i<=hight; i++){

        if(arr[i]!=arr[i-1]){

            printf(" %i %i", arr[i-1], i-1);
        }
    }

    printf(" %i %i 0\n", arr[hight], hight);

    return 0;
}
//https://cses.fi/problemset/task/1070

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int size, i;
    scanf("%i", &size);

    if(size>1 && size<=3){
        printf("NO SOLUTION\n");
    }
    else if(size == 4){
        printf("2 4 1 3\n");
    }
    else{
        printf("%i", size);
        for(i = size-2;i>=1; i-=2){
            printf(" %i", i);
        }

        for(i = size-1;i>=1; i-=2){
            printf(" %i", i);
        }
        printf("\n");
    }

    return 0;
}
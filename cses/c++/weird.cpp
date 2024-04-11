//https://cses.fi/problemset/task/1068/

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    long long int number;
    scanf("%lld", &number);
    printf("%lld", number);
    while(number != 1){
        if(number%2){
            number = number * 3 + 1;
        }
        else{
            number/=2;
        }
        printf(" %lld", number);
    }
    printf("\n");

    return 0;
}
//https://onlinejudge.org/external/118/11879.pdf
//11879

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    long int numero;

    while(scanf("%i", &numero) && numero != 0){


        if(numero%17==0){

            printf("1\n");
        }

        else{
            printf("0\n");
        }
    } 

    return 0;
}
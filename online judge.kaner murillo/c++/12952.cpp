//https://onlinejudge.org/external/129/12952.pdf
//12952

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int num1, num2;

    while(scanf("%i %i", &num1, &num2) != EOF){

        if(num1 > num2){
            printf("%i\n", num1);
        }

        else if(num2 > num1){
            printf("%i\n", num2);
        }

        else{
            printf("%i\n", num2);
        }
    }
    return 0;
}
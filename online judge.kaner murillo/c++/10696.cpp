//https://onlinejudge.org/external/106/10696.pdf
//10696

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int val;

    while(scanf("%i", &val) && val != 0){

        if(val >= 101){

            printf("f91(%i) = %i\n", val, val-10);
        }

        else{

            printf("f91(%i) = 91\n", val);
        }
    }

    return 0;
}
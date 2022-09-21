//https://onlinejudge.org/external/108/10880.pdf
//10880

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int cases, i, n, cookies, result;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){
        
        scanf("%i %i", &cookies, &result);
        printf("Case #%i:", i);

        if(cookies == result){

            printf(" 0");
        }

        else{
            for(n = cookies-result; n>0; n--){

                if((cookies-result)% n == 0 && (cookies-result)/ n > result){
                    printf(" %i", (cookies-result)/n);
                }
            }
        }

        printf("\n");
    }
    return 0;
}
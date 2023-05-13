//https://onlinejudge.org/external/5/524.pdf
//524

#include<cstdio>
#include<iostream>

int primes[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
    res[17], flags[17];

using namespace std;

void solved(int index, int limit){

    if(index == limit-1){

        if(primes[res[index] + res[0]]){

            int i;
            printf("1");
            for(i = 1; i<limit; i++){

                printf(" %i", res[i]);
            }
            printf("\n");
        }
    }

    else{

        int i;

        for(i = 2; i<limit+1; i++){
            
            if(flags[i-1] && primes[res[index] + i]){

                flags[i-1] = 0;
                res[index+1] = i;
                solved(index+1, limit);
                flags[i-1] = 1;
            }
        }
    }
}

int main(){

    int i, counter = 1, size;

    while(scanf("%i", &size) != EOF){

        if(counter>1){
            printf("\n");
        }
        for(i = 0; i<size; i++){
            flags[i] = 1;
            res[i] = -1;
        }
        res[0] = 1;
        printf("Case %i:\n", counter++);
        solved(0, size);
    }

    return 0;
}


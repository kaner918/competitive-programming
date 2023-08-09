//https://onlinejudge.org/external/100/10003.pdf
//10003

#include<cstdio>
#include<iostream>

using namespace std;

int memo[51][1000], cuts[51];

int main(){

    int i, n, sizeCuts, cut, stick;

    while(scanf("%i", &stick) && stick){

        scanf("%i", &sizeCuts);

        for(i = 0; i<sizeCuts; i++){
            scanf("%i", &cuts[i]);
            for(n = 0; n<1000; n++){
                memo[i][n] = -1;
            }
        }
    }

    return 0;
}
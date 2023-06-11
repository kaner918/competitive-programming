//https://onlinejudge.org/external/126/12654.pdf
//12654

#include<cstdio>
#include<iostream>

int patches[1001], memo[1001];

int dp(int index, int size){

    if(index > size){

        index = (index - (index%size) * size)-1;
    }

    if(memo[index] != -1){
        return memo[index];
    }

    else{

        int index1 = index, index2 = index;
    }
}

int main(){

    int size, c, t1, t2, number, i;

    while(scanf("%i %i %i %i", &size, &c, &t1, &t2) != EOF){

        for(i = 0; i<size; i++){
            scanf("%i", &partches[i]);
            memo[i] = -1;
        }
    }

    return 0;
}
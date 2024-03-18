//https://onlinejudge.org/external/118/11832.pdf
//11832

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int numbers[42], negative[42], positive[42];

int dp(int i, int n, int sums, int find, map<pair<int, int>, int>&mem){

    int ans;

    if(mem.count({i, sums})){
        ans = mem[{i, sums}];
    }
    else{

        if(i == n){
            ans = sums == find;
        }

        else{

            int a, b;

            a = dp(i+1, n, sums+numbers[i], find, mem);
            b = dp(i+1, n, sums-numbers[i], find, mem);

            if(a){
                positive[i]++;
            }
            if(b){
                negative[i]++;
            }

            ans = a || b;
        }
        mem[{i, sums}] = ans;
    }

    return ans;
}

int main(){ 

    int sizeNumbers, i, transaction, ans;

    while(scanf("%i %i", &sizeNumbers, &transaction) && (sizeNumbers || transaction)){
        
        for(i = 0; i<sizeNumbers; i++){
            scanf("%i", &numbers[i]);
            positive[i] = 0;
            negative[i] = 0;
        }

        map<pair<int, int>, int>mem;

        ans = dp(0, sizeNumbers, 0, transaction, mem);

        if(!ans){
            printf("*\n");
        }

        else{
            for(i = 0; i<sizeNumbers; i++){
                if(positive[i] && negative[i]){
                    printf("?");
                }
                else if(positive[i]){
                    printf("+");
                }
                else{
                    printf("-");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
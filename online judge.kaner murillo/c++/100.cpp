//https://onlinejudge.org/external/1/100.pdf
//100

#include<cstdio>
#include<iostream>
#include<climits>
#include<map>

using namespace std;

map<long long int, long long int>memo;

long long int f(long long int num){

    int res = 1;

    while(num>1){

        res++;

        if(memo.find(num) == memo.end()){

            if(!(num%2)){

                num/=2;
            }

            else{

                num = num * 3 + 1;
            }
        }    

        else{

            res+=memo[num];
            num = 1;
        }
    }

    memo[num] = res;

    return res;
}

int main(){

    long long int i, j, x, c, p, num, max1, aux;

    while(scanf("%lld %lld", &i, &j) != EOF){

        max1  = 0;
        x = i;
        c = j;

        if(i>j){

            swap(i, j);
        }

        for(p = i; p<= j; p++){

            aux = f(p);

            if(aux > max1){

                max1 = aux;
            }
        }

        printf("%lld %lld %lld\n", x, c, max1);
    }

    return 0;
}
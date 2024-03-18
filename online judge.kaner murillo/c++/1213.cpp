//https://onlinejudge.org/external/12/1213.pdf
//1213

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int mem[190][20][1121];

vector<bool> isPrime; // with https://aprende.olimpiada-informatica.org/algoritmia-criba-eratostenes
vector<int> primes;
void criba(int n) {
    isPrime = vector<bool>(n, true);
    primes = vector<int>();
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h=2; h*i<n; ++h) isPrime[i*h] = 0;
        }
    }
}

int dp(int i, int n, int k, int find){

    int ans;

    if(mem[i][k][find] != -1){
        ans = mem[i][k][find];
    }

    else{

        if(!k){
            ans = !find;
        }

        else if(i == n){
            ans = 0;
        }

        else if(primes[i] > find){
            ans = 0;
        }

        else{

            ans = dp(i+1, n, k, find) + dp(i+1, n, k-1, find-primes[i]);
        }

        mem[i][k][find] = ans;
    }

    return ans;
}   

int main(){

    criba(1124);
    
    int i, j, l,  n, k;

    while(scanf("%i %i", &n, &k) && (n || k)){

        for(i = 0; i<=primes.size(); i++){
            for(j = 0; j<=k; j++){
                for(l = 0; l<= n; l++){
                    mem[i][j][l] = -1;
                }
            }
        }

        printf("%i\n", dp(0, primes.size(), k, n));
    }

    return 0;
}
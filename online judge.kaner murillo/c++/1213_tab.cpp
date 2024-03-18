//https://onlinejudge.org/external/12/1213.pdf
//1213

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int tab[1121][20];

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

int solve(int n, int k, int find){

    int i, j, l;

    for(i = 0; i<=find; i++){
        for(j = 0; j<=k; j++){
            tab[i][j] = 0;
        }
    }

    tab[0][0] = 1;

    for(l = 0; l<n; l++){
        for(i = find; i>-1; i--){
            for(j = 1; j<=k; j++){
                if(i-primes[l]>=0){
                    tab[i][j] += tab[i-primes[l]][j-1];
                }
            }
        }
    }

    return tab[find][k];
}   

int main(){

    criba(1124);
    
    int i, j, l,  n, k;

    while(scanf("%i %i", &n, &k) && (n || k)){
        printf("%i\n", solve(primes.size(), k, n));
    }

    return 0;
}
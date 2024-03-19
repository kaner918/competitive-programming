//https://onlinejudge.org/external/115/11566.pdf
//11566

#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int dims[12], prices[12], t, x;

int dp(int i, int n, int sums, int counter){

    int ans;

    if(i == n){
        ans = 0;
    }
    else{

        int a, b = 0;
        float cal = ceil((sums+t)*0.1);

        a = dp(i+1, n, sums, 0);

        //cout<<sums<<" "<<cal<<endl;
        if(x-(sums+t+cal)>=0 && counter<2){
            b = dp(i, n, sums+prices[i], counter+1) + dims[i];
        }

        ans = max(a, b);
    }

    return ans;
}

int main(){

    int n, k, i, j, num;

    while(scanf("%i %i %i %i", &n, &x, &t, &k) && (n||x||t||k)){

        x*=(n);
        t*=(n+1);
        for(i = 0; i<k; i++){
            dims[i] = 0;
            scanf("%i", &prices[i]);
            for(j = 0; j<=n; j++){
                scanf("%i", &num);
                dims[i]+=num;
            }
        }

        printf("%.2f\n", (double)(1e-9+dp(0, k, 0, 0))/(n+1));
    }

    return 0;
}
//https://onlinejudge.org/external/5/562.pdf
//562

#include<cstdio>
#include<iostream>

using namespace std;

int arr[102], tab[102][51002];

int solve(int size, int maxSum){

    int i, j;

    for(i = 0; i<=maxSum; i++){
        tab[0][i] = 0;
    }

    for(i = 1; i<=size; i++){
        for(j = 0; j<=maxSum; j++){
            
            if(arr[i-1] <= j){
                tab[i][j] = max(tab[i-1][j], tab[i-1][j-arr[i-1]] + arr[i-1]);
            }

            else{
                tab[i][j] = tab[i-1][j];
            }
        }
    }   

    return tab[size][maxSum];
}

int main(){

    int cases, size, i, j, ans, maxSum;

    cin>>cases;

    for(i = 0; i<cases; i++){
        cin>>size;
        maxSum = 0;

        for(j = 0; j<size; j++){
            cin>>arr[j];
            maxSum+=arr[j];
        }
        ans = solve(size, maxSum/2);
        cout<<maxSum-ans*2<<endl;
    }

    return 0;
}
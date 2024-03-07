//https://onlinejudge.org/external/5/562.pdf
//562

#include<cstdio>
#include<iostream>

using namespace std;

int arr[102], tab[102][51002];

int solve(int size, int maxSum){

    int i, j;

    for(i = 0; i<=maxSum; i++){
        tab[size][i] = i;
    }

    for(i = size-1; i>-1; i--){
        for(j = maxSum; j>-1; j--){
            
            if(j+arr[i] <= maxSum){
                tab[i][j] = max(tab[i+1][j], tab[i+1][j+arr[i]]);
            }

            else{
                tab[i][j] = tab[i+1][j];
            }
        }
    }   

    return tab[0][0];
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
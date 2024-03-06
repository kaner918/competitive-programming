//https://onlinejudge.org/external/5/562.pdf
//562

#include<cstdio>
#include<iostream>

using namespace std;

int arr[101], mem[101][50001];

int dp(int i, int size, int sum1, int sum2){

    int ans;

    if(mem[i][abs(sum1-sum2)] != -1){
        ans = mem[i][abs(sum1-sum2)];
    }
    else{

        if(i == size){
            ans = abs(sum1 - sum2);
        }

        else{
            ans = min(dp(i+1, size, sum1+arr[i], sum2), dp(i+1, size, sum1, sum2+arr[i]));   
            mem[i][abs(sum1-sum2)] = ans;
        }
    }

    return ans;
}

int main(){

    int cases, size, i, j, l, maxi;

    cin>>cases;

    for(i = 0; i<cases; i++){
        cin>>size;
        maxi = 0;

        for(j = 0; j<size; j++){
            cin>>arr[j];
            maxi+=arr[j];
        }

        for(j = 0; j<size+1; j++){
            for(l = 0; l<=maxi; l++){
                mem[j][l] = -1;
            }
        }
        cout<<dp(0, size, 0, 0)<<endl;
    }

    return 0;
}
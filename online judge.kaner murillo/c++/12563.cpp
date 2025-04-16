//https://onlinejudge.org/external/125/12563.pdf
//12563

#include<cstdio>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

int arr_songs[51];

pair<int, int> dp(int i, int n, int sum, int time, vector<vector<pair<int, int>>>&mem){

    pair<int, int> ans;
    pair<int, int>key = {-1, -1};

    if(mem[i][sum]!=key){
        ans = mem[i][sum];
    }
    else{
        if(i == n){
            ans = {sum, 0};
        }
        else{
            ans = dp(i+1, n, sum, time, mem);
            if(sum+arr_songs[i]<time){
                pair<int, int>aux_pair;
                aux_pair = dp(i+1, n, sum+arr_songs[i], time, mem);
                aux_pair.second++;
                if(aux_pair.second>ans.second || (aux_pair.second == ans.second && aux_pair.first>ans.first)){
                    ans = aux_pair;
                }
            }
        }
        mem[i][sum] = ans;
    }

    return ans;
}

int main(){

    int cases, songs, time, sumi, i, j;
    pair<int, int>ans;

    scanf("%i", &cases);
    
    for(i = 0; i<cases; i++){
        scanf("%i %i", &songs, &time);
        sumi = 0;
        for(j = 0; j<songs; j++){
            scanf("%i", &arr_songs[j]);
            sumi+=arr_songs[j];
        }
        vector<vector<pair<int, int>>>mem(songs+1, vector<pair<int, int>>(sumi+1, {-1, -1}));

        ans = dp(0, songs, 0, time, mem);
        printf("Case %i: %i %i\n", i+1, ans.second+1, ans.first+678);
    }

    return 0;
}
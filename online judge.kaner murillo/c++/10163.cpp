//https://onlinejudge.org/external/101/10163.pdf
//10163

#include<cstdio>
#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int mens[31];

pair<int, int>dp(int n, int size_mens, int i, int low, vector<vector<vector<pair<int, int>>>>&mem){

    pair<int, int>ans;
    pair<int, int>key = {-1, -1};

    if(key != mem[n][i][low]){
        ans = mem[n][i][low];
    }
    else{
        if(!n){
            ans = {low, 0};
        }
        else{

            if(i == size_mens-1){
                ans = dp(0, size_mens, i+1, min(low, mens[i]/n), mem);
                ans.second+=mens[i];
            }
            else{
                ans = dp(n, size_mens, i+1, low, mem);
                int j;
                pair<int, int>aux;
                
                for(j = 1; j<= n; j++){
                    aux = dp(n-j, size_mens, i+1, min(low, mens[i]/j), mem);
                    aux.second+=mens[i];

                    if(aux.first>ans.first || (aux.first == ans.first && aux.second < ans.second)){
                        ans = aux;
                    }
                }
            }
        }
        mem[n][i][low] = ans;
    }
    return ans;
}

int main(){
    
    int i, j, k, size_storages, maxi, size_mens;
    pair<int, int>ans;
    vector<vector<vector<pair<int, int>>>>mem(101, vector<vector<pair<int, int>>>(31, vector<pair<int, int>>(1001, {-1, -1})));

    while(scanf("%i %i", &size_storages, &size_mens) && (size_storages || size_mens)){
        maxi = 0;
        for(i = 0; i<size_mens; i++){
            scanf("%i", &mens[i]);
            maxi = max(maxi, mens[i]);
        }

        for(i = 0; i<=size_storages; i++){
            for(j = 0; j<=size_mens; j++){
                for(k = 0; k<=maxi; k++){
                    mem[i][j][k] = {-1, -1};
                }
            }
        }
        ans = dp(size_storages, size_mens, 0, maxi, mem);
        if(!ans.first){
            ans.second = 0;
        }
        printf("%i %i\n", ans.first, ans.second);
    }

    return 0;
}
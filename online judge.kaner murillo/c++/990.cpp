//https://onlinejudge.org/external/9/990.pdf
//990

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int memo[32][1002];

int dp(int n, int t, int w, vector<pair<int, int>>&treasures){

    int ans;

    if(!n){
        ans = 0;    
    }
    else{

        int a, b = 0, take = t - ((treasures[n-1].first*w) + (treasures[n-1].first*w*2));

        cout<<n-1<<" "<<take<<endl;
        a = dp(n-1, t, w, treasures);

        if(take>=0){
            b = dp(n-1, take, w, treasures) + treasures[n-1].second;
        }

        ans = max(a, b);
    }

    return ans;
}

int main(){

    int t, size,  w, v, d, i, j, flag = 0;

    while(scanf("%i %i", &t, &w) != EOF){

        /* if(flag){ ouputs
            cin.ignore();
        }
        flag = 1; */

        scanf("%i", &size);
        vector<pair<int, int>>treasures;
        for(i = 0; i<size; i++){
            scanf("%i %i", &v, &d);
            treasures.push_back({v, d});
        }

        for(i = 0; i<=size; i++){
            for(j = 0; j<=t; j++){
                memo[i][t] = -1;
            }
        }

        printf("%i\n", dp(size, t, w, treasures));
    }
    return 0;
}
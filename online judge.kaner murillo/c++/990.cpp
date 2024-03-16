//https://onlinejudge.org/external/9/990.pdf
//990

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

map<pair<int, int>, pair<int, vector<int>>>mem;

pair<int, vector<int>> dp(int n, int t, int w, vector<pair<int, int>>&treasures){

    pair<int, vector<int>>ans;

    if(mem.count({n, t})){
        ans = mem[{n, t}];
    }

    else{

        if(!n){
            ans = {0, {}};    
        }
        else{

            int take = t - ((treasures[n-1].first*w) + (treasures[n-1].first*w*2));

            pair<int, vector<int>>a;
            pair<int, vector<int>>b;
            pair<int, vector<int>>aux;
            //cout<<n-1<<" "<<take<<endl;
            a = dp(n-1, t, w, treasures);
            if(take>=0){
                aux = dp(n-1, take, w, treasures); 
                aux.second.push_back(n-1);
                b.first = aux.first + treasures[n-1].second;
                b.second = aux.second;
            }

            if(a.first>=b.first){
                ans = a;
            }
            else{
                ans = b;
            }
        }
        mem[{n, t}] = ans;
    }

    return ans;
}

int main(){

    int t, size,  w, v, d, i, j, flag = 0;
    pair<int, vector<int>>ans;

    while(cin>>t){
        cin>>w;
        if(flag){
            printf("\n");
        }
        flag = 1;

        cin>>size;
        vector<pair<int, int>>treasures;
        for(i = 0; i<size; i++){
            cin>>v>>d;
            treasures.push_back({v, d});
        }
        
        ans = dp(size, t, w, treasures);

        printf("%i\n%i\n", ans.first, ans.second.size());
        
        for(i = 0; i<ans.second.size(); i++){
            printf("%i %i\n", treasures[ans.second[i]].first, treasures[ans.second[i]].second);
        }

    }
    return 0;
}
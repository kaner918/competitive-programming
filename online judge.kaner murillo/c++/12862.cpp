//https://onlinejudge.org/external/128/12862.pdf
//12862

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

pair<int, int>dp(int node, vector<vector<pair<int, int>>>&graph, vector<int>&flag_friends){

    pair<int, int>ans;
    if(!graph[node].size()){
        //cout<<"hi "<<node<<endl;
        ans = {0, 0};
    }
    else{

        int i, count = 0;  
        pair<int, int>higer = {0, 0};
        for(i = 0; i<graph[node].size(); i++){
            pair<int, int>aux = dp(graph[node][i].first, graph, flag_friends);
            if(flag_friends[graph[node][i].first]){
                aux.second+=graph[node][i].second;
            }
            count+=aux.second;
            if(aux.second>higer.second){
                higer = aux;
            }
        }
        ans = {count, count};
        if(graph[node].size()-higer.second>0){
            ans.first-=higer.second;
        }
        if(!flag_friends[node] && ans.second > 0){
            flag_friends[node] = 1;
        }

    }

    return ans;
}

int main(){

    int nodes, friends, i, j, a, b, coste, node;
    pair<int, int>ans;
    while(scanf("%i %i", &nodes, &friends)!=EOF){
        
        vector<vector<pair<int, int>>>graph(nodes);
        vector<int>flag_friends(nodes);
        for(i = 0; i<nodes-1; i++){
            scanf("%i %i %i", &a, &b, &coste);
            a--;
            b--;
            graph[a].push_back({b, coste});
        }
        for(i = 0; i<friends; i++){
            scanf("%i", &node);
            flag_friends[node-1] = 1;
        }

        ans = dp(0, graph, flag_friends);
        //cout<<ans.first<<" "<<ans.second<<endl;
        printf("%i\n", ans.first);
    } 

    return 0;
}
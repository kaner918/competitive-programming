//https://onlinejudge.org/external/104/10448.pdf
//10448

#include<cstdio>
#include<iostream>
#include<vector>
#include<tuple>
#include<climits>

using namespace std;

int dp(int coste, int sum, int node, int destiny, vector<vector<pair<int, int>>>&graph, vector<vector<int>>&paths, vector<vector<int>>&mem){

    int ans;
    if(mem[node][coste]!=-1){
        ans = mem[node][coste];
    }
    else{
        if(!coste){
            ans = 0;
        }
        else{

            int i;
            bool flag = false;
            ans = 1000000;
            for(i = 0; i<graph[node].size() && !flag; i++){
                if(graph[node][i].first == destiny && coste-graph[node][i].second == 0){
                    ans = dp(0, sum+1, destiny, destiny, graph, paths, mem) + 1;
                    flag = true;
                }
                else if(graph[node][i].first != destiny && paths[graph[node][i].first][destiny] && coste-graph[node][i].second>0){
                    ans = min(ans, dp(coste-graph[node][i].second, sum+1, graph[node][i].first, destiny, graph, paths, mem) + 1);
                }
            }
        }
        mem[node][coste] = ans;
    }

    return ans;
}   

void dfs(int node, int father, vector<vector<pair<int, int>>>&graph, vector<vector<int>>&paths, vector<int>&visits){

    int i, j;
    visits[node] = 1;
    paths[node][node] = 1;

    for(i = 0; i<graph[node].size(); i++){
        if(!visits[graph[node][i].first]){
            dfs(graph[node][i].first, node, graph, paths, visits);
        }

        if(graph[node][i].first!=father){
            for(j = 0; j<graph.size(); j++){
                paths[node][j]|=paths[graph[node][i].first][j];
            }
        }
    } 
}

int main(){

    int cases, i, j, size_unikas, paths, a, b, queries, coste, ans;

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){

        scanf("%i %i", &size_unikas, &paths);
        vector<vector<pair<int, int>>>graph(size_unikas);
        for(j = 0; j<paths; j++){
            scanf("%i %i %i", &a, &b, &coste);
            a--;
            b--;
            graph[a].push_back({b, coste});
            graph[b].push_back({a, coste});
        }

        scanf("%i", &queries);
        for(j = 0; j<queries; j++){
            scanf("%i %i %i", &a, &b, &coste);
            a--;
            b--;
            vector<vector<int>>paths(size_unikas, vector<int>(size_unikas, 0));
            vector<vector<int>>mem(size_unikas+1, vector<int>(coste+1, -1));
            vector<int>visits(size_unikas, 0);
            dfs(a, -1, graph, paths, visits);
            if(visits[b]){
                ans = dp(coste, 0, a, b, graph, paths, mem);
                if(ans!=1000000){
                    printf("Yes %i\n", ans);
                }
                else{
                    printf("No\n");
                }
            }
            else{
                printf("No\n");
            }
        }
        if(i<cases-1){
            printf("\n");
        }
    }

    return 0;
}
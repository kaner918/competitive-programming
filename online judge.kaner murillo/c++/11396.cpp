//https://onlinejudge.org/external/113/11396.pdf
//11396

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<int>visits(301);

bool dfs(int node, vector<vector<int>>&graph, int color){

    bool ans = 1;
    visits[node] = color;
    int i;

    for(i = 0; i < graph[node].size(); i++){
        //cout<<node << " " <<i<<endl;

        if(visits[graph[node][i]]== -1){

            ans = ans && dfs(graph[node][i], graph, !color);
        }

        else if(visits[graph[node][i]] == visits[node]){
            return false;
        }
    }

    return ans;
}

int main(){

    int nodes, a, b, flag, i;

    while(scanf("%i", &nodes) && nodes){

        vector<vector<int>>graph(nodes);
        flag = 1;
        for(i = 0; i<nodes; i++){
            visits[i] = -1;
        }

        while(scanf("%i %i", &a, &b) && (a || b)){

            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(i = 0; i<nodes && flag; i++){

            if(visits[i] == -1){
                flag = flag && dfs(i, graph, 1);
            }
        }

        if(flag){
            printf("YES\n");
        }

        else{
            printf("NO\n");
        }
    }
    return 0;
}
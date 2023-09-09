//https://onlinejudge.org/external/123/12363.pdf
//12363

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

vector<int>visits(10000);
vector<int>father(10000);
vector<int>childrens(10000);
vector<int>low(10000);
int index;

void tarjan(vector<vector<int>>&graph, vector<vector<int>>&graph2, int node){

    visits[node] = index;
    low[node] = index;
    index++;
    int i;

    for(i = 0; i<graph[node].size(); i++){

        if(visits[graph[node][i]] == -1){
            
            childrens[node]++;
            father[graph[node][i]] = node; 
            tarjan(graph, graph2, graph[node][i]);
            low[node] = min(low[node], low[graph[node][i]]);
            if(low[graph[node][i]] > visits[node]){
                graph2[node].push_back(graph[node][i]);
                graph2[graph[node][i]].push_back(node);
            }
        }
        else if(father[node] != graph[node][i]){
            low[node] = min(low[node], visits[graph[node][i]]);
        }
    } 
}

void dfs(vector<vector<int>>&graph, int node){

    visits[node] = index;
    int i;
    for(i = 0; i<graph[node].size(); i++){
        if(visits[graph[node][i]] == -1){
            dfs(graph, graph[node][i]);
        }
    }
}

int main(){

    int nodes, counter = 0, conections, queries, a, b, c, flag, i;

    while(scanf("%i %i %i", &nodes, &conections, &queries) && (nodes || conections || queries)){
        index = 1;
        counter = 1;
        vector<vector<int>>graph(nodes, vector<int>());
        vector<vector<int>>graph2(nodes, vector<int>());
        set<pair<int, int>>conj;

        for(i = 0; i<nodes; i++){
            visits[i] = -1;
            father[i] = -1;
            childrens[i] = 0;
            low[i] = -1;
        }

        for(i  = 0; i<conections; i++){

            scanf("%i %i", &a, &b);
            a--, b--;

            if(a>b){
                c = b;
                b = a;
                a = c; 
            }

            if(!conj.count({a, b})){
                graph[a].push_back(b);
                graph[b].push_back(a);
                conj.insert({a, b});
            }
        }

        for(i = 0; i<nodes; i++){
            if(visits[i] == -1){
                tarjan(graph, graph2, i);
            }
        }

        for(i = 0; i<nodes; i++){
            visits[i] = -1;
        }

        index = 1;
        for(i = 0; i<nodes; i++){
            if(visits[i] == -1){
                dfs(graph2, i);
                index++;
            }
        }


        for(i = 0; i<queries; i++){
            scanf("%i %i", &a, &b);
            a--, b--;

            if(visits[a] == visits[b]){
                printf("Y\n");
            }
            else{
                printf("N\n");
            }
        }

        printf("-\n");

    }

    return 0;
}
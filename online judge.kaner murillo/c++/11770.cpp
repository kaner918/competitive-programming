//https://onlinejudge.org/external/117/11770.pdf
//11770

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int indexC, indexTps;
vector<int>visits(10001);
vector<int>indexComponent(10001);
vector<int>tps(10001);

void kosarajuAux(int node, vector<vector<int>>&graph){

    if(!visits[node]){
        visits[node] = 1;

        int i;

        for(i = 0; i<graph[node].size(); i++){
            kosarajuAux(graph[node][i], graph);
        }
        tps[indexTps--] = node;
    }
}

void asing(int u, int v, vector<vector<int>>&graphT){

    indexComponent[u] = v;
    int i;

    for(i = 0; i<graphT[u].size(); i++){
        if(indexComponent[graphT[u][i]] == -1){
            asing(graphT[u][i], v, graphT);
        }
    }
}

void kosaraju(int nodes, vector<vector<int>>&graph, vector<vector<int>>&graphT){

    int i;

    for(i = 0; i<nodes; i++){
        kosarajuAux(i, graph);
    }

    for(i = 0; i<nodes; i++){
        if(indexComponent[tps[i]] == -1){
            indexC++;
            asing(tps[i], tps[i], graphT);
        }
    }
}

void dfs(int node, vector<vector<int>>&graph){

    if(!visits[node]){
        visits[node] = 1;

        int i;

        for(i = 0; i<graph[node].size(); i++){
            dfs(graph[node][i], graph);
        }
    }
}

bool comp(pair<int, int>&a, pair<int, int>&b){
    return a.second > b.second;
}

int main(){

    int cases, i, j, ans, counter = 1, nodes, conections, a, b;

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){

        scanf("%i %i", &nodes, &conections);
        vector<vector<int>>graph(nodes);
        vector<vector<int>>graphT(nodes);
        ans = 0;
        indexC = 0;
        indexTps = nodes-1;
        for(j = 0; j<nodes; j++){
            visits[j] = 0;
            indexComponent[j] = -1;
            tps[j] = 0;
        }

        for(j = 0; j<conections; j++){
            scanf("%i %i", &a, &b);
            a--, b--;

            graph[a].push_back(b);
            graphT[b].push_back(a);
        }

        kosaraju(nodes, graph, graphT);

        map<int, int>auxComponents;
        
        for(j = 0; j<nodes; j++){
            auxComponents[indexComponent[j]]++;
            visits[j] = 0;
        }

        vector<pair<int, int>>sorted(auxComponents.begin(), auxComponents.end());
        sort(sorted.begin(), sorted.end(), comp);
        
        /* for(j = 0; j<sorted.size(); j++){

            if(!visits[sorted[j].first]){
                dfs(sorted[j].first, graph);
                ans++;
            }
        } */

        for(j = 0; j<nodes; j++){ // no utilice el algortmo de kosaraju, solamente hice orden topologico.

            if(!visits[tps[j]]){
                dfs(tps[j], graph);
                ans++;
            }
        }

        printf("Case %i: %i\n", counter++, ans);
    }
    
    return 0;
}
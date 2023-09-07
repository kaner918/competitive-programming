//10765
//https://onlinejudge.org/external/107/10765.pdf

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int>father(10000, -1);
vector<int>childrens(10000, -1);
vector<int>low(10000, -1);
vector<int>visits(10000, -1);
int index;

bool comp(pair<int, int>&a, pair<int, int>&b){

    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second > b.second;
}

void tarjan(int node, map<int, int>&dic, vector<vector<int>>&graph){

    visits[node] = index;
    low[node] = index;
    index++;
    int i;

    for(i = 0; i<graph[node].size(); i++){

        if(visits[graph[node][i]] == -1){

            father[graph[node][i]] = node;
            childrens[node]++;
            tarjan(graph[node][i], dic, graph);
            low[node] = min(low[node], low[graph[node][i]]);

            if(father[node] != -1 && low[graph[node][i]] >= visits[node]){
                dic[node]++;
            }
        }

        else if(father[node] != graph[node][i]){
            low[node] = min(low[node], visits[graph[node][i]]);
        }
    }

    if(father[node]== -1){
        dic[node] = childrens[node];
        if(!childrens[node]){
            dic[node] = 1;
        }
    }
}

int main(){

    int a, b, nodes, candidates, i;

    while(scanf("%i %i", &nodes, &candidates) && (nodes || candidates)){

        vector<vector<int>>graph(nodes, vector<int>());
        map<int, int>dic;
        index = 1;
        for(i = 0; i<nodes; i++){

            father[i] = -1;
            childrens[i] = 0;
            low[i] = -1;
            visits[i] = -1;
            dic[i] = 1;
        }
        
        while(scanf("%i %i", &a, &b) && (a != -1 || b != -1)){

            graph[a].push_back(b);
            graph[b].push_back(a);
        }   

        for(i = 0; i<nodes; i++){
            if(visits[i] == -1){
                tarjan(i, dic, graph);
            }
        }

        vector<pair<int, int>> vector_mapa(dic.begin(), dic.end());
        sort(vector_mapa.begin(), vector_mapa.end(), comp);

        for(i = 0; i<candidates; i++){
            printf("%i %i\n", vector_mapa[i].first, vector_mapa[i].second);
        }
        printf("\n");
    }

    return 0;
}

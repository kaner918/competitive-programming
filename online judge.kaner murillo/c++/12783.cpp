//https://onlinejudge.org/external/127/12783.pdf
//12783

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>childrens(1001);
vector<int>fathers(1001);
vector<int>low(1001);
vector<int>visits(1001);
int index;

bool comp(pair<int, int>&a, pair<int, int>&b){

    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void tarjan(vector<vector<int>>&graph,  vector<pair<int, int>>&res, int node){

    visits[node] = index;
    low[node] = index;
    index++;
    int i, auxNode;

    for(i = 0; i<graph[node].size(); i++){
        auxNode = graph[node][i];

        if(!visits[auxNode]){

            childrens[node]++;
            fathers[auxNode] = node;
            tarjan(graph, res, auxNode);
            low[node] = min(low[node], low[auxNode]);

            if(low[auxNode] > visits[node]){
                res.push_back({min(node, auxNode), max(node, auxNode)});
            }
        }

        else if(fathers[node] != auxNode){
            low[node] = min(low[node], visits[auxNode]);
        }
    }
}

int main(){

    int i, a, b, nodes, conections;

    while(scanf("%i %i", &nodes, &conections) && (nodes || conections)){

        vector<vector<int>>graph(nodes);
        vector<pair<int, int>>res;
        index = 1;
        for(i = 0; i<nodes; i++){
            childrens[i] = 0;
            fathers[i] = -1;
            low[i] = -1;
            visits[i] = 0;
        }

        for(i = 0; i<conections; i++){
            scanf("%i %i", &a, &b);

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(i = 0; i<nodes; i++){
            if(!visits[i]){
                tarjan(graph, res, i);
            }
        }

        sort(res.begin(), res.end(), comp);

        printf("%i", res.size());
        for(i = 0; i<res.size(); i++){
            printf(" %i %i", res[i].first, res[i].second);
        }
        printf("\n");
    }

    return 0;
}
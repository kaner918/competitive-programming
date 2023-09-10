//https://onlinejudge.org/external/7/796.pdf
//796

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>father;
vector<int>visits;
vector<int>childrens;
vector<int>low;
int index;

void tarjan(vector<vector<int>>&graph, vector<pair<int, int>>&links, int node){

    visits[node] = index;
    low[node] = index;
    index++;

    int i, auxNode;

    for(i = 0; i<graph[node].size(); i++){

        auxNode = graph[node][i];
        if(visits[auxNode] == -1){

            childrens[node]++;
            father[auxNode] = node;
            tarjan(graph, links, auxNode);
            low[node] = min(low[node], low[auxNode]);
            if(low[auxNode] > visits[node]){
                links.push_back({min(node, auxNode), max(node, auxNode)});
            }
        }

        else if(father[node] != auxNode){
            low[node] = min(low[node], visits[auxNode]);
        }
    }
}

int main(){

    int size, auxSize,a, b, i, j, flag = 1;

    while(cin>>size){
      
        vector<vector<int>>graph(size);
        vector<pair<int, int>>links;
        index = 1;
        for(i = 0; i<size; i++){
            scanf("%i (%i)", &a, &auxSize);

            for(j = 0; j<auxSize; j++){
                scanf("%i", &b);
                graph[a].push_back(b);
            }

            if(i == father.size()){
                father.push_back(-1);
                visits.push_back(-1);
                low.push_back(-1);
                childrens.push_back(0);
            }
            else{
                father[i] = -1;
                visits[i] = -1;
                low[i] = -1;
                childrens[i] = 0;
            }
        }

        for(i = 0; i<size; i++){
            if(visits[i] == -1){
                tarjan(graph, links, i);
            }
        } 
        printf("%i critical links\n", links.size());
        sort(links.begin(), links.end());

        for(i = 0; i<links.size(); i++){
            printf("%i - %i\n", links[i].first, links[i].second);
        }
        printf("\n");
    }
    return 0;
}
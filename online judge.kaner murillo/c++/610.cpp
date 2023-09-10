//https://onlinejudge.org/external/6/610.pdf
//610

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int>childrens(1001);
vector<int>fathers(1001);
vector<int>low(1001);
vector<int>visits(1001);
int index;

void tarjan( vector<vector<int>>&graph,  map<pair<int, int>, int>&res, int node){

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
                res[{node, auxNode}] = 1;
            }

            else{
                res[{node, auxNode}] = 2;
            }
        }

        else if(fathers[node] != auxNode){
            low[node] = min(low[node], visits[auxNode]);
            if(res[{auxNode, node}] == 0){
                res[{node, auxNode}] = 2;
            }
        }
    }
}

int main(){

    int size, counter = 1, conections, i, a, b, c;

    while(scanf("%i %i", &size, &conections) && (size || conections)){

        index = 1;
        vector<vector<int>>graph(size);
        map<pair<int, int>, int>res;

        for(i = 0; i<size; i++){

            childrens[i] = 0;
            fathers[i] = -1;
            low[i] = -1;
            visits[i] = 0;
        }

        for(i = 0; i<conections; i++){

            scanf("%i %i", &a, &b);
            a--, b--;
            /* if(a > b){
                c = a;
                a = b;
                b = c;
            } */
            
            res[{a, b}] = 0;
            res[{b, a}] = 0;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(i = 0; i<size; i++){
            if(!visits[i]){
                tarjan(graph, res, i);
            }
        }

        printf("%i\n\n", counter);

        for(auto it = res.begin(); it != res.end(); it++){

            /* cout<<"hola "<<it->first.first+1<<" "<<it->first.second+1<<" "<<it->second<<endl; */
            if(it->second == 1){
                printf("%i %i\n%i %i\n", it->first.first+1, it->first.second+1, it->first.second+1, it->first.first+1);
            }

            else if(it->second == 2){
                printf("%i %i\n", it->first.first+1, it->first.second+1);
            }
        }
        printf("#\n");
        counter++;
    }

    return 0;
}
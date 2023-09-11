//https://onlinejudge.org/external/118/11838.pdf
//11838

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int indexTps, indexC;
vector<int>visits(2001);
vector<int>tps(2001);
vector<int>indexComponent(2001);

void dfs(int node, vector<vector<int>>&graph){

    if(!visits[node]){
        visits[node] = 1;
        int i, auxNode;

        for(i = 0; i<graph[node].size(); i++){
            auxNode = graph[node][i];

            if(!visits[auxNode]){
                dfs(auxNode, graph);
            }
        }
        tps[indexTps--] = node;
    }
}

void asing(int u, int v, vector<vector<int>>&graphT){
    indexComponent[u] = v;
    
    int i, auxNode;

    for(i = 0; i<graphT[u].size(); i++){
        auxNode = graphT[u][i];
        if(indexComponent[auxNode] == -1){
            asing(auxNode, v, graphT);
        }
    }
}

void kosaraju(int nodes,  vector<vector<int>>&graph,  vector<vector<int>>&graphT){

    int i;

    for(i = 0; i<nodes; i++){
        dfs(i, graph);
    }

    for(i = 0; i<nodes; i++){
        if(indexComponent[tps[i]] == -1){
            indexC++;
            asing(tps[i], tps[i], graphT);
        }
    }
}

int main(){

    int nodes, conections, a, b, c, i;

    while(scanf("%i %i", &nodes, &conections) && (nodes || conections)){

        vector<vector<int>>graph(nodes);
        vector<vector<int>>graphT(nodes);
        indexTps = nodes-1;
        indexC =  0;
        for(i = 0; i<nodes; i++){
            visits[i] = 0;
            tps[i] = -1;
            indexComponent[i] = -1;
        }

        for(i = 0; i<conections; i++){
            scanf("%i %i %i", &a, &b, &c);
            a--, b--;

            if(c == 1){

                graph[a].push_back(b);  
                graphT[b].push_back(a);
            }

            else{

                graph[a].push_back(b); 
                graph[b].push_back(a);  
                graphT[a].push_back(b);
                graphT[b].push_back(a);
            }
        }

        kosaraju(nodes, graph, graphT);
        printf("%i\n", (indexC==1));
    }

    return 0;
}
//https://onlinejudge.org/external/117/11709.pdf
//11709

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int indexC, indexTps;
vector<int>tps(1001);
vector<int>visits(1001);
vector<int>indexComponent(1001);

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

int main(){

    int nodes, conections, i;
    string cad1, cad2;

    while(scanf("%i %i", &nodes, &conections) && (nodes || conections)){

        map<string, int>indexs;
        vector<vector<int>>graph(nodes);
        vector<vector<int>>graphT(nodes);

        indexTps = nodes-1;
        indexC = 0;
        cin.ignore();
        for(i = 0; i<nodes; i++){
            getline(cin, cad1);
            visits[i] = 0;
            tps[i] = 0;
            indexComponent[i] = -1;
            indexs[cad1] = i;
        }

        for(i = 0; i<conections; i++){

            getline(cin, cad1);
            getline(cin, cad2);
            graph[indexs[cad1]].push_back(indexs[cad2]);
            graphT[indexs[cad2]].push_back(indexs[cad1]);    
        }
        kosaraju(nodes, graph, graphT);

        printf("%i\n", indexC);
    }
    return 0;
}
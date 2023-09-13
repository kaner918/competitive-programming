//https://onlinejudge.org/external/107/10731.pdf
//10731

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int indexC;
vector<int>tps;
vector<vector<int>>components;

void kosarajuAux(map<int, vector<int>>&graph, map<int, int>&visits, int node){

    if(!visits[node]){

        visits[node] = 1;
        int i;

        for(i = 0; i<graph[node].size(); i++){
            kosarajuAux(graph, visits, graph[node][i]);
        }
        tps.push_back(node);
    }
}

void asing(int u, int v, map<int, int>&indexComponent, map<int, vector<int>>&graphT){

    indexComponent[u] = v;
    components[indexC-1].push_back(u);

    int i;

    for(i = 0; i<graphT[u].size(); i++){

        if(indexComponent[graphT[u][i]] == -1){
            asing(graphT[u][i], v, indexComponent, graphT);
        }
    }
}

void kosaraju(map<int, vector<int>>&graph, map<int, vector<int>>&graphT, map<int, int>&indexComponent, map<int, int>&visits){

    for(auto it = visits.begin(); it!=visits.end(); it++){
        kosarajuAux(graph, visits, it->first);
    }

    int i;

    for(i = tps.size()-1; i>-1; i--){

        if(indexComponent[tps[i]] == -1){
            indexC++;
            components.push_back(vector<int>());
            asing(tps[i], tps[i], indexComponent, graphT);
            sort(components[components.size()-1].begin(), components[components.size()-1].end());
        }
    }
}

int main(){

    int conections, i, j, flag = 0;
    string cad;

    while(scanf("%i", &conections) && conections){
        
        if(flag){
            printf("\n");
        }
        map<int, vector<int>>graph;
        map<int, vector<int>>graphT;
        map<int, int>visits;
        map<int, int>indexComponent;
        indexC = 0;
        tps.clear();
        components.clear();
        cin.ignore();

        for(i = 0; i<conections; i++){
            getline(cin, cad);

            if(!graph.count(cad[cad.length()-1]-65)){
                graph[cad[cad.length()-1]-65] = vector<int>();
                visits[cad[cad.length()-1]-65] = 0;
                indexComponent[cad[cad.length()-1]-65] = -1;
            }

            for(j = 0; j<cad.length()-2; j+=2){
                graph[cad[cad.length()-1]-65].push_back(cad[j]-65);
                graphT[cad[j]-65].push_back(cad[cad.length()-1]-65);
                visits[cad[j]-65] = 0;
                indexComponent[cad[j]-65] = -1;
            }
        }

        kosaraju(graph, graphT, indexComponent, visits);
        sort(components.begin(), components.end());

        for(i = 0; i<components.size(); i++){
            for(j = 0; j<components[i].size()-1; j++){
                printf("%c ", components[i][j]+65);
            }
        printf("%c\n", components[i][j]+65);
        }
        flag = 1;
    }
    return 0;
}
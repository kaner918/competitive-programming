//https://onlinejudge.org/external/2/247.pdf
//247

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int indexTps, indexC;
vector<int>visits(26);
vector<int>indexComponent(26);
vector<int>tps(26);
vector<vector<int>>components;

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
    components[indexC-1].push_back(u);

    int i, auxNode;

    for(i = 0; i<graphT[u].size(); i++){
        auxNode = graphT[u][i];

        if(indexComponent[auxNode] == -1){
            asing(auxNode, v, graphT);
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
            components.push_back(vector<int>());
            asing(tps[i], tps[i], graphT);
        }
    }
}

int main(){

    int nodes, conections, counter2 = 1,counter, i, j;
    string cad1, cad2;

    while(scanf("%i %i", &nodes, &conections) && (nodes || conections)){
        
        if(counter2 > 1){

            printf("\n");
        }
        counter = 0;
        vector<vector<int>>graph(nodes);
        vector<vector<int>>graphT(nodes);
        map<string, int>indexs;
        map<int, string>indexs2;

        components.clear();

        indexC = 0;
        indexTps = nodes-1;
        for(i = 0; i<nodes; i++){
            tps[i] = -1;
            visits[i] = 0;
            indexComponent[i] = -1;
        }

        for(i = 0; i<conections; i++){

            cin>>cad1>>cad2;

            if(!(indexs.count(cad1))){

                indexs[cad1] = counter;
                indexs2[counter++] = cad1;
            }

            if(!(indexs.count(cad2))){

                indexs[cad2] = counter;
                indexs2[counter++] = cad2;
            }

            graph[indexs[cad1]].push_back(indexs[cad2]);
            graphT[indexs[cad2]].push_back(indexs[cad1]);
        }

        kosaraju(nodes, graph, graphT);

        printf("Calling circles for data set %i:\n", counter2);
  
        for(i = 0; i<components.size(); i++){

            for(j = 0; j<components[i].size()-1; j++){

                cout<<indexs2[components[i][j]]<<", ";
            }
            cout<<indexs2[components[i][components[i].size()-1]]<<endl;
        }
        counter2++;
    }
    return 0;
}
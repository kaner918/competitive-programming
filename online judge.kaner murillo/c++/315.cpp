//https://onlinejudge.org/external/3/315.pdf
//315

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<set>

using namespace std;

vector<int>visits(101);
vector<int>father(101);
vector<int>childrens(101);
vector<int>low(101);
int index;

void tarjan(vector<vector<int>>&graph, int node, set<int>&conj){

    visits[node] = index;
    low[node] = index;
    index++;

    int i, auxNode;

    for(i = 0; i<graph[node].size(); i++){

        auxNode = graph[node][i];

        if(visits[auxNode] == -1){

            father[auxNode] = node;
            childrens[node]++;
            tarjan(graph, auxNode, conj);
            low[node] = min(low[node], low[auxNode]);

            if(father[node] != -1 && low[auxNode] >= visits[node]){
                conj.insert(node);
            }
        }

        else if(father[node] != auxNode){
            low[node] = min(low[node], visits[auxNode]);
        }
    }

    if(father[node] == -1 && childrens[node] > 1){
        conj.insert(node);
    }
}
int main(){

    int nodes, index, auxNode, i;
    string cad;
    
    while(scanf("%i", &nodes) && nodes){
        
        index = 1;

        set<int>conj;
        for(i = 0; i<nodes; i++){
            visits[i] = -1;
            father[i] = -1;
            childrens[i] = 0;
            low[i] = -1;
        }

        vector<vector<int>>graph(nodes);
        cin.ignore();
        while(getline(cin, cad) && cad.length() > 1){

            stringstream stk(cad);
            stk>>index;
            index--;
            while(stk>>auxNode){
                auxNode--;
                graph[index].push_back(auxNode);
                graph[auxNode].push_back(index);
            }
        }

        for(i = 0; i<nodes; i++){
            if(visits[i] == -1){
                tarjan(graph, i, conj);
            }
        }

        printf("%i\n", conj.size());
    }
    return 0;
}
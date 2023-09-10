//https://onlinejudge.org/external/101/10199.pdf
//10199

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

vector<int>childrens(101);
vector<int>fathers(101);
vector<int>low(101);
vector<int>visits(101);
int index;

void tarjan(vector<vector<int>>&graph,  set<int>&auxRes, int node){

    low[node] = index;
    visits[node] = index;
    index++;

    int i, auxNode;

    for(i = 0; i<graph[node].size(); i++){
        auxNode = graph[node][i];

        if(!visits[auxNode]){

            childrens[node]++;
            fathers[auxNode] = node;
            tarjan(graph, auxRes, auxNode);
            low[node] = min(low[node], low[auxNode]);

            if(fathers[node] != -1 && low[auxNode] >= visits[node]){
                auxRes.insert(node);
            }   
        }

        else if(fathers[node] != auxNode){
            low[node] = min(low[node], visits[auxNode]);
        }
    }
    if(fathers[node] == -1 && childrens[node] > 1){
        auxRes.insert(node);
    }
}

int main(){ 

    int size, counter = 1, counter2, i, j, conections;
    string cad, cad2;

    while(scanf("%i", &size) && size){

        counter2 = 0;

        if(counter > 1){
            printf("\n");
        }
        index = 1;
        
        vector<vector<int>>graph(size);
        map<string, int>indexs;
        map<int, string>indexs2;
        vector<string>res;
        set<int>auxRes;

        for(i = 0; i<size; i++){

            childrens[i] = 0;
            fathers[i] = -1;
            low[i] = -1;
            visits[i] = 0;

            cin>>cad;
            indexs[cad] = counter2;
            indexs2[counter2] = cad;
            counter2++;
        }

        scanf("%i", &conections);

        for(i = 0; i<conections; i++){
            cin>>cad>>cad2;
            graph[indexs[cad]].push_back(indexs[cad2]);
            graph[indexs[cad2]].push_back(indexs[cad]);
        }

        for(i = 0; i<size; i++){
            if(!visits[i]){
                tarjan(graph, auxRes, i);
            }
        }

        for(auto it = auxRes.begin(); it!=auxRes.end(); it++){
            res.push_back(indexs2[*it]);
        }

        sort(res.begin(), res.end());
        printf("City map #%i: %i camera(s) found\n", counter, auxRes.size());

        for(i = 0; i<res.size(); i++){
            cout<<res[i]<<endl;
        }
        counter++;
    }

    return 0;
}
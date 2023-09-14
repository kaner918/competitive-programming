//https://onlinejudge.org/external/12/1229.pdf
//1229

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int indexC, indexTps;
vector<int>visits(101);
vector<int>tps(101);
vector<int>indexComponent(101);
vector<string>res;
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

void asing(int u, int v, vector<vector<int>>&graphAT){

    indexComponent[u] = v;
    int i;

    for(i = 0; i<graphAT[u].size(); i++){
        if(indexComponent[graphAT[u][i]] == -1){
            asing(graphAT[u][i], v, graphAT);
        }
    }
}

void kosaraju(int size, vector<vector<int>>&graph, vector<vector<int>>&graphaT){

    int i;

    for(i = 0; i<size; i++){
        kosarajuAux(i, graph);
    }

    for(i = 0; i<size; i++){
        if(indexComponent[tps[i]] == -1){
            asing(tps[i], tps[i], graphaT);
        }
    }
}

void dfs(int node, vector<vector<int>>&graph, map<int, string>&indexs2){

    int i;
    visits[node] = 1;

    for(i = 0; i<graph[node].size(); i++){
        
        if(!visits[graph[node][i]]){
            dfs(graph[node][i], graph, indexs2);
        }
    }

    res.push_back(indexs2[node]);
}

int main(){

    int size, counter, i, j;
    string cad, word1, word2;

    while(scanf("%i", &size) && size){

        cin.ignore();
        counter = 0;
        map<string, int>index;
        map<int, string>indexs2;    
        vector<vector<int>>graph(size);
        vector<vector<int>>graphaT(size);
        components.clear();
        res.clear();
        indexC = 0;
        indexTps = size -1;
        for(i = 0; i<size; i++){

            visits[i] = 0;
            indexComponent[i] = -1;
            tps[i] = -1;

            getline(cin, cad);
            stringstream stk(cad);
            stk>>word1;

            if(!index.count(word1)){
                index[word1] = counter;
                indexs2[counter++] = word1;
            }

            while(stk>>word2){

                if(!index.count(word2)){
                    index[word2] = counter;
                    indexs2[counter++] = word2;
                }
                
                graph[index[word1]].push_back(index[word2]);
                graphaT[index[word2]].push_back(index[word1]);
            }
        }

        kosaraju(size, graph, graphaT);
        map<int, int>auxDicts;

        for(i = 0; i<size; i++){
            auxDicts[indexComponent[i]]++;
            visits[i] = 0;
        }

        for(auto it = auxDicts.begin(); it!=auxDicts.end(); it++){

            if(it->second > 1 &&  !visits[it->first]){
                dfs(it->first, graph, indexs2);
            }
        }
        
        sort(res.begin(), res.end());
        printf("%i\n", res.size());
        for(i = 0; i<res.size()-1; i++){
            cout<<res[i]<<" ";
        }
        cout<<res[res.size()-1]<<endl;
    }

    return 0;
}
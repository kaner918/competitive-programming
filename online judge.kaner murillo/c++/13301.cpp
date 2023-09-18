//https://onlinejudge.org/external/133/13301.pdf
//13301

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int indexC, indexTps;
vector<int>visits(50001);
vector<int>compo(50001);
vector<int>range(50001);
vector<int>indexComponent(50001);
vector<int>tps;

int actu(int node){

    if(compo[node] == node){
        return node;
    }

    else{

        compo[node] = actu(compo[node]);
        return compo[node];
    }
}

void unionSet(int node1, int node2){

    node1 = actu(node1);
    node2 = actu(node2);

    if(node1 != node2){

        if(range[node1] < range[node2]){
            swap(node1, node2);
        }

        compo[node2] = node1;
        range[node1]+=range[node2];
    }
}

void kosarajuAux(int node, map<int, vector<int>>&graph){

    if(!visits[node]){
        visits[node] = 1;
        int i;

        for(i = 0; i<graph[node].size(); i++){
            kosarajuAux(graph[node][i], graph);
        }
        tps.push_back(node);
    }
}

void asing(int u, int v, map<int, vector<int>>&graphT){

    indexComponent[u] = v;
    int i;

    for(i = 0; i<graphT[u].size(); i++){
        if(indexComponent[graphT[u][i]] == -1){
            asing(graphT[u][i], v, graphT);
        }
    }
}

void kosaraju(int size, map<int, vector<int>>&graph, map<int, vector<int>>&graphT){

    int i;

    for(i = 0; i<size; i++){
        kosarajuAux(actu(i), graph);
    }

    for(i = tps.size()-1; i>-1; i--){
        
        if(indexComponent[tps[i]] == -1){
            indexC++;
            asing(tps[i], tps[i], graphT);
        }
    }
}

int main(){

    int size, conections, sizeC, i, j, k, a, b, miniCompo, flag;

    while(scanf("%i %i", &size, &conections) != EOF){

        vector<pair<int, int>>points;
        map<int, vector<int>>graph;
        map<int, vector<int>>graphT;
        set<int>numbers;
        flag = 1;
        indexC = 0;
        indexTps = size-1;
        tps.clear();
        for(i = 0; i<size; i++){
            visits[i] = 0;
            indexComponent[i] = -1;
            compo[i] = i;
            range[i] = 1;
        }

        for(i = 0; i<conections; i++){
            scanf("%i", &sizeC);

            if(sizeC == 1){
                scanf("%i %i", &a, &b);
                a--, b--;
                points.push_back({a, b});
                numbers.insert(a);
                numbers.insert(b);
            }

            else{   

                vector<int>aux;
                for(j = 0; j<sizeC; j++){
                    scanf("%i", &a);
                    a--;
                    aux.push_back(a);
                    numbers.insert(a);
                    if(j){
                        unionSet(aux[j], aux[j-1]);
                    }
                }
            }
        }

        for(i = 0; i<points.size(); i++){

            a = actu(points[i].first);
            b = actu(points[i].second);

            if(a != b){
                graph[a].push_back(b);
                graphT[b].push_back(a);
            }
        }

        miniCompo = actu(0);
        for(i = 0; i<size && flag; i++){
            if(actu(i) != miniCompo){
                flag = 0;
            }
        }

        if(flag){
            indexC = 1;
        }

        else{
            kosaraju(size, graph, graphT);
        }
        
        if(indexC == 1 && numbers.size() == size){
            printf("YES\n");
        }

        else{
            printf("NO\n");
        }
    }

    return 0;
}
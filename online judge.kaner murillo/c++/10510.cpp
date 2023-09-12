//https://onlinejudge.org/external/105/10510.pdf
//10510

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int indexC, indexTps, index;
vector<int>visits(10001);
vector<int>low(10001);
vector<int>visits2(10001);
vector<int>indexComponent(10001);
vector<int>tps(10001);

void kosarajuAux(int node,  vector<vector<int>>&graph){

    if(!visits[node]){
        visits[node] = 1;

        int i;

        for(i = 0; i<graph[node].size(); i++){
            kosarajuAux(graph[node][i], graph);
        }
        tps[indexTps--] = node;
    }
}

void asing(int u, int v,  vector<vector<int>>&graph,  vector<vector<int>>&graphT){

    indexComponent[u] = v;
    
    int i, auxNode;

    for(i = 0; i<graphT[u].size(); i++){
        auxNode = graphT[u][i];

        if(indexComponent[auxNode] == -1){
            asing(auxNode, v, graph, graphT);
        }
    }
}

void kosaraju(int nodes,  vector<vector<int>>&graph,  vector<vector<int>>&graphT){

    int i;
    for(i = 0; i<nodes; i++){
        kosarajuAux(i, graph);
    }

    for(i = 0; i<nodes; i++){
        if(indexComponent[tps[i]] == -1){
            indexC++;
            asing(tps[i], tps[i], graph, graphT);
        }
    }
}

bool dfs(int node, vector<vector<int>>&graph){

    bool ans = true;
    visits[node] = index;
    index++;

    int i, auxNode;

    for(i = 0; i<graph[node].size(); i++){

        auxNode = graph[node][i];

        if(!visits[auxNode]){

            ans = ans && dfs(auxNode, graph);
            
        }

        else{

            if(visits2[auxNode]){
                return false;
            }

            else if(low[auxNode] != -1 && !visits2[low[auxNode]] && visits[node] > visits[auxNode]){
                return false;
            }

            else {
                low[auxNode] = node;
            }
        }
    }

    visits2[node] =  index;
    index++;
    return ans;
}

int main(){

    int cases, i, nodes, conections, a, b, ans;
    scanf("%i", &cases);
    while(cases--){

        scanf("%i %i", &nodes, &conections);

        vector<vector<int>>graph(nodes);
        vector<vector<int>>graphT(nodes);
        indexC = 0;
        index = 1;
        indexTps = nodes-1;
        ans = 0;
        for(i = 0; i<nodes; i++){
            visits[i] = 0;
            indexComponent[i] = -1;
            tps[i] = -1;
        }

        for(i = 0; i<conections; i++){

            scanf("%i %i", &a, &b);
            
            graph[a].push_back(b);
            graphT[b].push_back(a);
        }


        kosaraju(nodes, graph, graphT);
        ans = (indexC == 1);

        if(ans){

            indexC = 0;
            for(i = 0; i<nodes; i++){
                visits[i] = 0;
                visits2[i] = 0;
                fathers[i] = -1;
                low[i] = -1;
            }

            ans = dfs(0, graph);
            ans = ans && (indexC <= 1);
        }

        if(ans){
            printf("YES\n");
        }

        else{
            printf("NO\n");
        }
    }

    return 0;
}
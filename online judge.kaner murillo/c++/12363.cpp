//https://onlinejudge.org/external/123/12363.pdf
//12363

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

vector<int>visits(10000);
vector<int>father(10000);
vector<int>childrens(10000);
vector<int>low(10000);
int index;

void tarjan(vector<vector<int>>&graph, int node, map<int, int>&comp, int mar){

    visits[node] = index;
    low[node] = index;
    index++;
    int i;

    for(i = 0; i<graph[node].size(); i++){

        if(visits[graph[node][i]] == -1){
            
            childrens[node]++;
            father[graph[node][i]] = node; 
            tarjan(graph, graph[node][i], comp, mar);
            low[node] = min(low[node], low[graph[node][i]]);
            if(father[node] != -1 && low[graph[node][i]] >= visits[node]){
                comp[node] = mar;
            }
        }
        else if(father[node] != graph[node][i]){
            low[node] = min(low[node], visits[graph[node][i]]);
        }
    } 

    if(father[node] == -1 && childrens[node] > 1){
        comp[node] = mar;
    }

    else if(low[node] == visits[node] && graph[node].size() <= 1){
        comp[node] =  mar;
    }
}

int main(){

    int nodes, counter = 0, conections, queries, a, b, c, flag, i;

    while(scanf("%i %i %i", &nodes, &conections, &queries) && (nodes || conections || queries)){
        index = 1;
        counter = 1;
        vector<vector<int>>graph(nodes, vector<int>());
        set<pair<int, int>>conj;
        map<int, int>comp;

        for(i = 0; i<nodes; i++){
            visits[i] = -1;
            father[i] = -1;
            childrens[i] = 0;
            low[i] = -1;
            comp[i] = -1;
        }

        for(i  = 0; i<conections; i++){

            scanf("%i %i", &a, &b);
            a--, b--;

            if(a>b){
                c = b;
                b = a;
                a = c; 
            }

            if(!conj.count({a, b})){
                graph[a].push_back(b);
                graph[b].push_back(a);
                conj.insert({a, b});
            }
        }

        for(i = 0; i<nodes; i++){
            if(visits[i] == -1){
                tarjan(graph, i, comp, counter);
                counter++;
            }
        }

        for(i = 0; i<queries; i++){
            scanf("%i %i", &a, &b);
            a--, b--;

            if(comp[a] == comp[b] && (comp[a] != -1 && comp[b] != -1)){
                printf("Y\n");
            }
            else{
                printf("N\n");
            }
        }

        printf("-\n");

        /* for(i = 0; i<nodes; i++){
            cout<<"node :"<<i+1<<" padre: "<<father[i]+1<<" low: "<<low[i]<<endl;
        } */
    }

    return 0;
}
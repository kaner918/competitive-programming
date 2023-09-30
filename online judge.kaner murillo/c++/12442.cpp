//https://onlinejudge.org/external/124/12442.pdf
//12442

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

int index, routers;
vector<int>visits(50001);
vector<pair<int, int>>low(50001);
vector<int>roots(50001);
map<pair<int, int>, int>maxis;
int dfs(int node, vector<vector<int>>&graph){

    visits[node] = index;
    low[node] = {node, index};
    roots[node] = routers;

    index++;
    
    int i, counter = 1, aux;

    for(i = 0; i<graph[node].size(); i++){

        if(!visits[graph[node][i]]){
            aux = dfs(graph[node][i], graph);
            if(low[node].second > low[graph[node][i]].second){
                low[node] = low[graph[node][i]];
            }
            counter+=aux;
        }

        else if(roots[node] == roots[graph[node][i]]){
            if(low[node].second > low[graph[node][i]].second){
                low[node] = low[graph[node][i]];
            }
        }
        
        else{   

            if(!maxis[{node, roots[graph[node][i]]}]){
                
                maxis[{node, roots[graph[node][i]]}] = visits[low[graph[node][i]].first];
                counter+=maxis[{node, roots[graph[node][i]]}];
            }

            else if(visits[low[graph[node][i]].first] > maxis[{node, roots[graph[node][i]]}]){

                counter-=maxis[{node, roots[graph[node][i]]}];
                maxis[{node, roots[graph[node][i]]}] = visits[low[graph[node][i]].first];
                counter+=maxis[{node, roots[graph[node][i]]}]; 
            }
        }
    }

    if(low[node].first == node){
        visits[node] = counter;
    }

    return counter;
}

int main(){

    int cases, martians, aux, higer, martian, i, n, m, u, v;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i", &martians);
        vector<vector<int>> graph(martians);
        vector<int>sizes(martians, 0);
        maxis.clear();

        higer = 0;
        martian = 0;
        index = 1;
        routers = 0;

        for(n = 0; n<martians; n++){

            scanf("%i %i", &u, &v);
            graph[u-1].push_back(v-1);
            visits[n] = 0;
            roots[n] = -1;
        }

        for(n = 0; n<martians; n++){
            
            if(!visits[n]){

                routers++;
                index = 1;
                aux = dfs(n, graph);

                if(aux > higer){

                    higer = aux;
                    martian = n;
                }
            }
        }

        printf("Case %i: %i\n", i, martian+1);
    }

    return 0;
}
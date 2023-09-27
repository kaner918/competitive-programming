//https://onlinejudge.org/external/124/12442.pdf
//12442

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int counter, index;

int dfs(int v, int low, int component, vector<vector<int>>&graph, vector<bool>&components, vector<bool>&visits, vector<int>sizes){

    int i, nodes = 1;
    visits[v] = low;
    components[v] = component;

    for(i = 0; i< graph[node].size(); i++){
        
        if(!visits[graph[node][i]]){
            nodes+=dfs(graph[node][i], low + 1, graph, visits, sizes);        
        }
    }

    return nodes;
}

int main(){

    int cases, martians, higer, martian, i, n, m, u, v;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i", &martians);
        vector<vector<int>> grafo(martians);
        vector<vector<int>> flags(martians, vector<int>(martians, 0));

        vector<bool>visits;
        vector<int>components(martians, 0);
        vector<int>sizes(martians, 0);

        higer = 0;
        martian = 0;
        index = 0;

        for(n = 0; n<martians; n++){

            scanf("%i %i", &u, &v);
            grafo[u-1].push_back(v-1);
            visits.push_back(false);
        }

        for(n = 0; n<martians; n++){
            
            if(visits[n] == false){

                counter = 0;
                index++;
                dfs(n, grafo, visits, visits2);

                components[index] = counter;

                if(counter > higer){

                    higer = counter;
                    martian = n;
                }

                else if(counter == higer && n<martian){
                    martian  = n;
                }

            }
        }

        printf("Case %i: %i\n", i, martian+1);
    }

    return 0;
}
//https://onlinejudge.org/external/105/10505.pdf
//10505

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<int>visits(201);
vector<int>colors(2);

bool dfs(int node, vector<vector<int>>&graph, int color){

    bool ans = true;
    int i;
    visits[node] = !color;
    colors[visits[node]]++;
    
    if(node<graph.size()){

        for(i = 0; i< graph[node].size(); i++){

            if(visits[graph[node][i]] == -1){
                ans = ans && dfs(graph[node][i], graph, !color);
            }

            else if(visits[graph[node][i]] == visits[node]){
                return false;
            }
        }
    }

    return ans;
}   

int main(){

    int cases, i, nodes, size, j, b, counter, flag;

    cin>>cases;

    while(cases--){

        cin>>nodes;
        counter = 0;
        flag = 1;
        vector<vector<int>>graph(nodes);

        for(i = 0; i<202; i++){
            visits[i] = -1;
        }

        for(i = 0; i<nodes; i++){
            cin>>size;

            for(j = 0; j<size; j++){

                cin>>b;
                b--;
                
                graph[i].push_back(b);

                if(b<nodes){
                    graph[b].push_back(i);
                }
            }
        }     

        for(i = 0; i<nodes && flag; i++){
            if(visits[i] == -1){
                colors[0] = 0;
                colors[1] = 0;
                flag = flag && dfs(i, graph, 1);
                counter+= max(colors[0], colors[1]);
            }
        }   

        if(!flag){
            counter = 0;
        }

        printf("%i\n", counter);
    }


    return 0;
}
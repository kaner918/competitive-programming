//https://onlinejudge.org/external/105/10505.pdf
//10505

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>visits(201);
vector<int>colors(2);

bool bfs(int node, vector<vector<int>>&graph, int color){

    bool ans = true;
    int i;
    visits[node] = color;
    colors[visits[node]]++;
    queue<int>q;
    q.push(node);

    while(!q.empty()){

        node = q.front();
        q.pop();

        for(i = 0; i<graph[node].size(); i++){

            if(visits[graph[node][i]] == -1){
                q.push(graph[node][i]);
                visits[graph[node][i]] = !visits[node];
                colors[visits[graph[node][i]]]++;
            }

            else if(visits[graph[node][i]] == visits[node]){
                ans = false;
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
                if(b<nodes){

                    graph[i].push_back(b);
                    graph[b].push_back(i);
                }
            }
        }     

        for(i = 0; i<nodes; i++){
            
            if(visits[i] == -1){
                colors[0] = 0;
                colors[1] = 0;
                flag = bfs(i, graph, 1);
                if(flag){
                    counter += max(colors[0], colors[1]);
                }
            }
        }   

        printf("%i\n", counter);
    }


    return 0;
}
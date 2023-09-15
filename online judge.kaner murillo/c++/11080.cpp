//https://onlinejudge.org/external/110/11080.pdf
//11080

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>visits(201);
int counter;
//0->black
//1->white

bool bfs(int node, vector<vector<int>>&graph){

    visits[node] = 0;
    int i;
    queue<int>q;
    q.push(node);

    while(!q.empty()){

        node = q.front();
        q.pop();

        for(i = 0; i<graph[node].size(); i++){

            if(visits[graph[node][i]] == -1){
                visits[graph[node][i]] = !visits[node];
                q.push(graph[node][i]);

            }

            else if(visits[graph[node][i]] == visits[node]){
                return 0;
            }
        }
    }

    return 1;
}

int main(){

    int cases, i, nodes, conections, a, b, flag = 1;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &nodes, &conections);
        vector<vector<int>>graph(nodes);
        counter = 0;

        for(i = 0; i<nodes; i++){
            visits[i] = -1;
        }

        for(i = 0; i<conections; i++){
            scanf("%i %i", &a, &b);

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(i = 0; i<nodes && flag; i++){
            if(visits[i] == -1){
                flag = flag && bfs(i, graph);
            }
        }

        if(flag){
            printf("%i\n", counter);
        }   

        else{

            printf("-1\n");
        }
    }
    return 0;
}
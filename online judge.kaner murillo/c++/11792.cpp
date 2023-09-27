//https://onlinejudge.org/external/117/11792.pdf
//11792

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int bfs(int node, vector<int>visits, vector<int>&lines, vector<vector<int>>&graph){

    int sum = 0, i;
    queue<int>q;
    visits[node] = 0;
    q.push(node);

    while(!q.empty()){

        node = q.front();
        q.pop();

        if(lines[node] > 1){
            sum+=visits[node];
        }

        for(i = 0; i<graph[node].size(); i++){

            if(visits[graph[node][i]] == -1){
                visits[graph[node][i]] = visits[node] + 1;
                q.push(graph[node][i]);
            }
        }
    }

    return sum;
}

int main(){

    int cases, i, j, nodes, conections, index, a, b, res, aux;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &nodes, &conections);

        vector<int>visits(nodes, -1);
        vector<int>lines(nodes, 0);
        vector<vector<int>>graph(nodes);
        res = INT_MAX;

        for(i = 0; i<conections; i++){
            scanf("%i", &a);
            lines[--a]++;
            while(scanf("%i", &b) && b){
                lines[--b]++;
                graph[a].push_back(b);
                graph[b].push_back(a);
                a = b;
            }
        }

        for(i = 0; i<nodes; i++){

            if(lines[i] > 1){
                aux = bfs(i, visits, lines, graph);
                if(aux < res){
                    res = aux;
                    index = i + 1;
                }
            }
        }

        printf("Krochanska is in: %i\n", index);
    }

    return 0;
}
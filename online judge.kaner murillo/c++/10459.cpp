//https://onlinejudge.org/external/104/10459.pdf
//10459

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>visits(5001);
vector<int>level(5001);
vector<int>grade(5001);
int maxi;

void bfs1(queue<int>&q, vector<vector<int>>&graph){

    int i, node;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(i = 0; i<graph[node].size(); i++){
            grade[graph[node][i]]--;
            if(grade[graph[node][i]] == 1){
                q.push(graph[node][i]);
                level[graph[node][i]] = level[node]+1;
                maxi = max(maxi, level[graph[node][i]]);
            }
        }
    }
}

void bfs2(queue<int>&q, vector<vector<int>>&graph){

    int i, node;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(i = 0; i<graph[node].size(); i++){
            if(!visits[graph[node][i]]){
                q.push(graph[node][i]);
                visits[graph[node][i]] = visits[node] + 1;
                maxi = max(maxi, visits[graph[node][i]]);
            }
        }
    }
}

int main(){

    int size, conections, node, i, j;

    while(scanf("%i", &size) != EOF){
        
        vector<vector<int>>graph(size);
        queue<int>q;
        maxi = 0;
        for(i = 0; i<size; i++){
            scanf("%i", &conections);
            for(j = 0; j<conections; j++){
                scanf("%i", &node);
                graph[i].push_back(node-1);
            }
            if(conections == 1){
                q.push(i);
            }
            visits[i] = 0;
            level[i] = 0;
            grade[i] = conections;
        }

        bfs1(q, graph);
        vector<int>res1;
        for(i = 0; i<size; i++){
            if(level[i] == maxi){
                res1.push_back(i+1);
                visits[i] = 1;
                q.push(i);
            }
        }

        printf("Best Roots  :");
        for(i = 0; i<res1.size(); i++){
            printf(" %i", res1[i]);
        }
        printf("\n");
        res1.clear();
        maxi = 0;
        bfs2(q, graph);
        for(i = 0; i<size; i++){
            if(visits[i] == maxi){
                res1.push_back(i+1);
            }
        }

        printf("Worst Roots :");
        for(i = 0; i<res1.size(); i++){
            printf(" %i", res1[i]);
        }
        printf("\n");
    }   

    return 0;
}
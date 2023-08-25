//https://onlinejudge.org/external/103/10305.pdf
//10305
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int res[101];

void khan(queue<int>&q, vector<int>&fathers, vector<vector<int>>&graph){

    int i, index = 0, node;

    while(!q.empty()){

        node = q.front();
        res[index++] = node+1;
        q.pop();
        
        for(i = 0; i<graph[node].size(); i++){

            fathers[graph[node][i]]--;
            if(!fathers[graph[node][i]]){
                q.push(graph[node][i]);
            }
        }
    }
}
int main(){

    int n, m, a, b, i;

    while(scanf("%i %i", &n, &m) && (n || m)){

        vector<vector<int>>graph(n);
        vector<int>fathers(n, 0);
        queue<int>q;

        for(i = 0; i<m; i++){
            scanf("%i %i", &a, &b);
            b-=1;
            graph[a-1].push_back(b);
            fathers[b]++;
        }

        for(i = 0; i<n; i++){
            if(!fathers[i]){
                q.push(i);
            }
        }

        khan(q, fathers, graph);
        printf("%i", res[0]);

        for(i = 1; i<n; i++){
            printf(" %i", res[i]);
        }
        printf("\n");
    }

    return 0;
}
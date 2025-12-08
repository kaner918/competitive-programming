#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>

using namespace std;

int dfs(int node, vector<int>&visits, vector<vector<int>>&graph){
    int i, count = 1;
    visits[node] = 1;
    for(i = 0; i<graph[node].size(); i++){
        if(!visits[graph[node][i]]){
            count+=dfs(graph[node][i], visits, graph);
        }
    }
    return count;
}

int main(){

    int i, j, n, m, node1, node2, weight, count, maxi;

    while(scanf("%i %i", &n, &m) && (n || m)){
        vector<vector<int>>graph(n+1);
        vector<vector<int>>marks(n+1, vector<int>(n+1, INT_MIN));
        vector<int>visits(n+1);
        vector<int>maxis(n+1, INT_MIN);
        maxi = INT_MIN;
        count = 0;
        for(i = 0; i<m; i++){
            scanf("%i %i %i", &node1, &node2, &weight);
            marks[node1][node2] = max(marks[node1][node2], weight);
            marks[node2][node1] = max(marks[node2][node1], weight);
            maxis[node1] = max(maxis[node1], weight);
            maxis[node2] = max(maxis[node2], weight);
            maxi = max(maxi, weight);
        }
        for(i = 1; i<=n; i++){
            for(j = i+1; j<=n; j++){
                if(marks[i][j] == maxi){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        for(i = 1; i<= n; i++){
            if(!visits[i] && maxis[i] == maxi){
                count = max(count, dfs(i, visits, graph));
            }
        }
        printf("%i\n", count);
    }

    return 0;
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>

using namespace std;

int dfs(int node, int maxi, vector<int>&visits, vector<map<int, int>>&graph){
    int i, count = 1;
    visits[node] = 1;
    for(auto it = graph[node].begin(); it!=graph[node].end(); it++){
        if(!visits[it->first] && it->second >= maxi){
            count+=dfs(it->first, maxi, visits, graph);
        }
    }
    return count;
}

int main(){

    int i, j, n, m, node1, node2, weight, count, maxi;

    while(scanf("%i %i", &n, &m) && (n || m)){
        vector<map<int, int>>graph(n+1);
        vector<int>visits(n+1);
        vector<int>maxis(n+1, INT_MIN);
        maxi = INT_MIN;
        count = 0;
        for(i = 0; i<m; i++){
            scanf("%i %i %i", &node1, &node2, &weight);
            if(graph[node1].find(node2) == graph[node1].end()){
                graph[node1][node2] = weight;
                graph[node2][node1] = weight;
            }
            else{
                graph[node1][node2] = max(graph[node1][node2], weight);
                graph[node2][node1] = max(graph[node2][node1], weight);
            }
            maxis[node1] = max(maxis[node1], weight);
            maxis[node2] = max(maxis[node2], weight);
            maxi = max(maxi, weight);
        }
        //cout<<maxi<<endl;
        for(i = 1; i<= n; i++){
            //cout<<"maxis: "<<maxis[i]<<endl;
            if(!visits[i] && maxis[i] == maxi){
                //cout<<"init: "<<i<<endl;
                count = max(count, dfs(i, maxi, visits, graph));
            }
        }
        cout<<count<<endl;
    }

    return 0;
}
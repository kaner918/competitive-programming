//https://onlinejudge.org/external/100/10099.pdf
//10099

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

int pre[101];

using namespace std;

void prim(vector<vector<pair<int, int>>>&graph, vector<int>&dist, int node){

    vector<int>visits(graph.size(), 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>>q;
    q.push(make_pair(0, node));
    pre[node] = -1;
    dist[node] = 0;
    int i, weight;

    while(!q.empty()){

        weight = q.top().first;
        node = q.top().second;
        q.pop();
        visits[node] = 1;

        if(dist[node] == weight){

            for(i = 0; i<graph[node].size(); i++){

                if(!visits[graph[node][i].first] && graph[node][i].second > dist[graph[node][i].first]){

                    pre[graph[node][i].first] = node;
                    dist[graph[node][i].first] = graph[node][i].second;
                    q.push(make_pair(graph[node][i].second, graph[node][i].first));
                }
            }
        }
    }
}
int main(){

    int size, conections, conection1, conection2, weight, aux, mini, counter = 1;

    while(scanf("%i %i", &size, &conections) && (size || conections)){

        vector<vector<pair<int, int>>>graph(size);
        vector<int>dist(size, 0);

        while(conections--){

            scanf("%i %i %i", &conection1, &conection2, &weight);

            graph[conection1-1].push_back(make_pair(conection2-1, weight));
            graph[conection2-1].push_back(make_pair(conection1-1, weight));
        }

        scanf("%i %i %i", &conection1, &conection2, &weight);

        prim(graph, dist, conection1-1);
        aux = conection2-1;
        mini = dist[conection2-1];

        while(pre[aux] != -1){

            mini = min(mini, dist[aux]);
            aux = pre[aux];
        }

        printf("Scenario #%i\n", counter);
        printf("Minimum Number of Trips = %i\n\n", weight/(mini-1) + (weight%(mini-1) != 0));

        counter++;
    }
    return 0;
}
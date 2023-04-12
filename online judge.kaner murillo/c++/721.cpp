//https://onlinejudge.org/external/7/721.pdf
//721

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>&graph, int size){

    vector<int>dist(size, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    int i, node, auxNode, weight, coste, total = 0;

    dist[0] = 0;
    q.push(make_pair(0, 0));

    while(!q.empty()){

        node = q.top().second;
        coste = q.top().first;

        q.pop();

        if(coste == dist[node]){

            for(i = 0; i<graph[node].size(); i++){

                auxNode = graph[node][i].first;
                weight = graph[node][i].second;

                if(coste + weight < dist[auxNode]){

                    dist[auxNode] = coste + weight;
                    q.push(make_pair(dist[auxNode], auxNode));
                }
            }
        }
    }

    for(i = 0; i<size; i++){

        total+=dist[i];
    }
    
    return total;
}

int main(){

    int cases, junctions, junction1, junction2, roads, weight;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &junctions, &roads);

        vector<vector<pair<int, int>>>graph(junctions);
        vector<vector<pair<int, int>>>graphIn(junctions);

        while(roads--){

            scanf("%i %i %i", &junction1, &junction2, &weight);

            graph[junction1-1].push_back(make_pair(junction2-1, weight));
            graphIn[junction2-1].push_back(make_pair(junction1-1, weight));
        }

        printf("%i\n", dijkstra(graph, junctions) + dijkstra(graphIn, junctions));
    }

    return 0;
}
//https://onlinejudge.org/external/109/10986.pdf
//10986

#include<vector>
#include<iostream>
#include<climits>
#include<queue>

using namespace std;

int points;
vector<int>cost(20000);

void init(int point){

    int i;

    for(i = 0; i<points; i++){

        cost[i] = INT_MAX;
    }

    cost[point] = 0;
}

void dijkstra(int point, vector<vector<pair<int, int>>>&graph){

    int auxCost, vertex, auxVertex, i, weight; 

    init(point);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>cola;
    cola.push(make_pair(point, 0));

    while(!cola.empty()){

        vertex = cola.top().first;
        auxCost = cola.top().second;

        cola.pop();

        if(auxCost == cost[vertex]){

            for(i = 0; i<graph[vertex].size(); i++){

                auxVertex = graph[vertex][i].first;
                weight = graph[vertex][i].second;

                if(cost[vertex] != INT_MAX && auxCost + weight < cost[auxVertex]){

                    cost[auxVertex] = auxCost + weight;
                    cola.push(make_pair(auxVertex, cost[auxVertex]));
                }
            }
        }
    }
}

int main(){

    int cases, i, n, a, b, auxA, auxB, weight, conections;

    scanf("%i", &cases);
    
    for(i = 1; i<=cases; i++){

        scanf("%i %i %i %i", &points, &conections, &a, &b);
        vector<vector<pair<int, int>>>graph(points);

        for(n = 0; n<conections; n++){
            
            scanf("%i %i %i", &auxA, &auxB, &weight);
            graph[auxA].push_back(make_pair(auxB, weight));
            graph[auxB].push_back(make_pair(auxA, weight));
        }

        dijkstra(a, graph);

        if(cost[b] == INT_MAX){

            printf("Case #%i: unreachable\n", i);
        }

        else{

            printf("Case #%i: %i\n", i, cost[b]);
        }
    }
    return 0;
}
//https://onlinejudge.org/external/118/11833.pdf
//11833

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

struct State{

    int coste, position;

    State(){}
    State(int coste, int position){

        this->coste = coste;
        this->position = position;
    }

    bool operator<(const State&other)const{

        return coste > other.coste;
    }
};

int dijkstra(vector<vector<pair<int, int>>>&graph, int init, int route){

    vector<int>dist(graph.size(), INT_MAX);
    priority_queue<State>q;

    dist[init] = 0;
    q.push(State(0, init));

    int i, auxNode, coste, weight;

    while(!q.empty()){

        init = q.top().position;
        coste = q.top().coste;

        q.pop();

        if(coste == dist[init]){

            for(i = 0; i<graph[init].size(); i++){

                auxNode = graph[init][i].first;
                weight = graph[init][i].second;

                if(init < route && auxNode == init + 1 && coste + weight < dist[auxNode]){

                    dist[auxNode] = coste + weight;
                    q.push(State(dist[auxNode], auxNode));
                }

                else if(init > route && coste + weight < dist[auxNode]){

                    dist[auxNode] = coste + weight;
                    q.push(State(dist[auxNode], auxNode));
                }
            }
        }
    }

    return dist[route];
}

int main(){ 

    int citys, roads, route, repair, city1, city2, weight;

    while(scanf("%i %i %i %i", &citys, &roads, &route, &repair) && (citys || roads || route || repair)){

        vector<vector<pair<int, int>>>graph(citys);

        while(roads--){

            scanf("%i %i %i", &city1, &city2, &weight);

            graph[city1].push_back(make_pair(city2, weight));
            graph[city2].push_back(make_pair(city1, weight));
        }

        printf("%i\n", dijkstra(graph, repair, route-1));
    }

    return 0;
}
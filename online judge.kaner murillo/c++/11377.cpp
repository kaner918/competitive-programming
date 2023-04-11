//https://onlinejudge.org/external/113/11377.pdf
//11377

#include<cstdio>
#include<iostream>
#include<climits>
#include<queue>
#include<vector>

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

int dijkstra(vector<vector<int>>&graph, vector<int>&airports, int init, int finish){

    int i, auxNode, weight, coste = 0;

    vector<int>dist(graph.size(), INT_MAX);
    priority_queue<State>q;
    dist[init] = 0;
    
    if(init == finish){
        return 0;
    }

    else if(!airports[init]){
        dist[init] = 1;
        coste = 1;
    }

    q.push(State(coste, init));
    
    while(!q.empty()){

        init = q.top().position;
        coste = q.top().coste;

        q.pop();

        if(coste == dist[init]){

            for(i = 0; i<graph[init].size(); i++){

                auxNode = graph[init][i];
                weight = 0;
                
                if(!airports[auxNode]){
                    weight = 1;
                }

                if(coste + weight < dist[auxNode]){

                    dist[auxNode] = coste + weight;
                    q.push(State(dist[auxNode], auxNode));
                }
            }
        }
    }

    if(dist[finish] == INT_MAX){
        return -1;
    }

    else{

        return dist[finish];
    }
}

int main(){

    int cases, i, citys, sizeAirports, conections, queries, airport, city1, city2;

    scanf("%i", &cases);

    for(i = 1; i<=cases; i++){

        scanf("%i %i %i", &citys, &conections, &sizeAirports);

        vector<vector<int>>graph(citys);
        vector<int>airports(citys, 0);

        while(sizeAirports--){

            scanf("%i", &airport);
            airports[airport-1] = 1;
        }

        while(conections--){

            scanf("%i %i", &city1, &city2);

            graph[city1-1].push_back(city2-1);
            graph[city2-1].push_back(city1-1);
        }   

        scanf("%i", &queries);
        printf("Case %i:\n", i);

        while(queries--){

            scanf("%i %i", &city1, &city2);
            printf("%i\n", dijkstra(graph, airports, city1-1, city2-1));
        }

        if(i<cases){
            cin.ignore();
        }

        printf("\n");
    }

    return 0;
}
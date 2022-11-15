//https://onlinejudge.org/external/128/12878.pdf
//12878

#include<climits>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int points;

vector<int>pre(10000);
vector<int>cost(10000);

void initialize(int init){

    int i;

    for(i = 0; i<points; i++){

        cost[i] = INT_MAX;
        pre[i] = -1;
    }

    cost[init] = 0;
}

void dijkstra(int init, vector<vector<pair<int, int>>>&graph){

    int weight, auxCost, vertex, vertexAd, i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>cola;
    initialize(init);
    cola.push(make_pair(init, 0));
    vector<int>res;

    while(!cola.empty()){

        vertex = cola.top().first;
        auxCost = cola.top().second;

        cola.pop();
        cout<<auxCost<<endl;

        if(auxCost == cost[vertex]){

            for(i = 0; i<graph[vertex].size(); i++){

                vertexAd = graph[vertex][i].first;
                weight = graph[vertex][i].second;
                
                if(auxCost != INT_MAX && auxCost + weight <= cost[vertexAd]){
                    
                    pre[vertexAd] = vertex;
                    cost[vertexAd] = auxCost + weight;
                    cola.push(make_pair(vertexAd, cost[vertexAd]));
                } 
            }
        }
    }
    
}

int main(){

    int trails, length, a, b, size;

    while(scanf("%i %i", &points, &trails) != EOF){

        vector<vector<pair<int, int>>>graph(points);

        while(trails--){

            scanf("%i %i %i", &a, &b, &size);
            graph[a].push_back(make_pair(b, size));
        }

        dijkstra(0, graph);
        //cout<<cost[points-1]<<endl;
    }

}
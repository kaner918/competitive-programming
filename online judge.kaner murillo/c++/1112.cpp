//https://onlinejudge.org/external/11/1112.pdf
//1112

#include<climits>
#include<queue>
#include<vector>
#include<iostream>

using namespace std;

int points;
vector<int>cost(100);

void init(int point){ //inicializamos los valores de la estructura auxiliar, donde guardamos el menor costo, para el nodo visitado

    int i;

    for(i = 0; i<points; i++){

        cost[i] = INT_MAX;
    }

    cost[point] = 0;//actualizamos el costo para el nodo incial, esto porque para llegar de x a x, tenemos un costo de 0
}

void dijkstra(int point, vector<vector<pair<int, int>>>&graph){

    int i, vertex, vertexAd, auxCost, weight;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>cola; //constructor para la cola de prioridad-> prioridad asiganda al menor valor de la cola.

    init(point);

    cola.push(make_pair(point, 0));

    while(!cola.empty()){

        vertex = cola.top().first;
        auxCost = cola.top().second;

        cola.pop();
    
        if(auxCost == cost[vertex]){

            for(i = 0; i<graph[vertex].size(); i++){

                vertexAd = graph[vertex][i].first;
                weight = graph[vertex][i].second;

                if(cost[vertex] != INT_MAX && auxCost + weight < cost[vertexAd]){

                    cost[vertexAd] = auxCost + weight;
                    cola.push(make_pair(vertexAd, cost[vertexAd]));
                }
            }
        }
    }
}

int main(){

    int cases, i, mouseA, mouseB, conections, finish, time, weight, counter; 

    scanf("%i", &cases);

    while(cases--){ 

        cin.ignore();

        scanf("%i %i %i %i", &points, &finish, &time, &conections);
        counter = 0;
        vector<vector<pair<int, int>>>graph(points);

        while(conections--){

            scanf("%i %i %i", &mouseA, &mouseB, &weight);
            graph[mouseA-1].push_back(make_pair(mouseB-1, weight));
        }

        for(i = 0; i<points; i++){

            dijkstra(i, graph);

            if(cost[finish-1] <= time){

                counter++;
            }
        }

        printf("%i\n", counter);

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}
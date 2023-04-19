//https://onlinejudge.org/external/131/13127.pdf
//13127

#include<climits>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>&graph, vector<int>&dist, int node){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    dist[node] = 0;

    q.push(make_pair(0, node));

    int i, auxNode, coste, weight;

    while(!q.empty()){

        coste = q.top().first;
        node = q.top().second;

        q.pop();

        if(coste == dist[node]){

            for(i = 0; i<graph[node].size(); i++){

                auxNode = graph[node][i].first;
                weight = graph[node][i].second;

                if(weight + coste < dist[auxNode]){

                    dist[auxNode] = weight + coste;
                    q.push(make_pair(dist[auxNode], auxNode));
                }
            }
        }
    }
}

int main(){

    int citys, roads, banks, stations, a, b, counter, weight, higer, i;

    while(scanf("%i %i %i %i", &citys, &roads, &banks, &stations) != EOF){

        vector<vector<pair<int, int>>>graph(citys); 
        vector<int>dist(citys, INT_MAX);
        vector<int>label(citys, 0); //0->normal, 1->bank
        higer = 0;
        counter = 0;

        while(roads--){

            scanf("%i %i %i", &a, &b, &weight);

            graph[a].push_back(make_pair(b, weight));
            graph[b].push_back(make_pair(a, weight));
        }

        while(banks--){

            scanf("%i", &a);
            label[a] = 1;
        }

        while(stations--){

            scanf("%i", &a);
            dijkstra(graph, dist, a);
        }

        for(i = 0; i<citys; i++){

            if(label[i]){
                
                if(dist[i] > higer){
                    counter = 1;
                    higer = dist[i];
                }

                else if(dist[i] == higer){

                    counter++;
                }
            }
        }

        if(higer == INT_MAX){

            printf("%i *\n", counter);
        }

        else{

            printf("%i %i\n", counter, higer);
        }

        counter = 0;

        for(i = 0; i<citys; i++){

            if(label[i] && dist[i] == higer){

                if(counter == 0){
                    printf("%i", i);
                    counter++;
                }

                else{
                    printf(" %i", i);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
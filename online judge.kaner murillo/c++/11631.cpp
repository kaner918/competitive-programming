//https://onlinejudge.org/external/116/11631.pdf
//11631

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

int prim(vector<vector<pair<int, int>>>&graph, vector<int>&dist){

    int i, coste = 0, city, auxCity, weight, auxWeight;
    dist[0] = 0;
    vector<int>visits(dist.size(), 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    q.push(make_pair(0, 0));

    while(!q.empty()){

        weight = q.top().first;
        city = q.top().second;

        visits[city] = 1;

        q.pop();

        if(weight == dist[city]){

            coste+=weight;

            for(i = 0; i<graph[city].size(); i++){

                auxCity = graph[city][i].first;
                auxWeight = graph[city][i].second;

                if(!visits[auxCity] && auxWeight < dist[auxCity]){

                    dist[auxCity] = auxWeight;
                    q.push(make_pair(auxWeight, auxCity));
                }
            }
        }
    }

    return coste;
}

int main(){
    
    int junctions, roads, x, y, z, init;

    while(scanf("%i %i", &junctions, &roads) && (junctions || roads)){

        vector<vector<pair<int, int>>>graph(junctions);
        vector<int>dist(junctions, INT_MAX);
        init = 0;

        while(roads--){

            scanf("%i %i %i", &x, &y, &z);

            init+=z;

            graph[x].push_back(make_pair(y, z));
            graph[y].push_back(make_pair(x, z));
        }

        printf("%i\n", init-prim(graph, dist));
    }

    return 0;
}
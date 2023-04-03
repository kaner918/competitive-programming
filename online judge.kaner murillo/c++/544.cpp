//https://onlinejudge.org/external/5/544.pdf
//544

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int father[201], visits[201];

void init(int size){

    int i;

    for(i = 0; i<size; i++){

        father[i]  = -1;
        visits[i] = 0;
    }
}

void prim(vector<vector<pair<int, int>>>&graph, vector<int>&dist, int city){

    int i, weight, auxWeight, destiny;

    priority_queue<pair<int, int>, vector<pair<int, int>>>q;

    init(dist.size());
    q.push(make_pair(10001, city));
    dist[city] = 10001;

    while(!q.empty()){

        weight = q.top().first;
        city = q.top().second;
        visits[city] = 1;

        q.pop();

        if(weight == dist[city]){

            for(i = 0; i<graph[city].size(); i++){

                destiny = graph[city][i].first;
                auxWeight = graph[city][i].second;

                if(!visits[destiny] && auxWeight > dist[destiny]){

                    father[destiny] = city;
                    dist[destiny] = auxWeight;
                    q.push(make_pair(auxWeight, destiny));
                }
            }
        }
    }
}

int main(){

    int size, roads, i, weight, index, counter = 1, mini, aux;
    string city1, city2;

    while(scanf("%i %i", &size, &roads) && (size || roads)){

        vector<vector<pair<int, int>>>graph(size);
        vector<int>dist(size, 0);
        map<string, int>mapping;
        index = 0;  
        mini = 10001;

        for(i = 0; i<roads; i++){

            cin>>city1>>city2>>weight;

            auto it = mapping.find(city1);
            if(it == mapping.end()){
                mapping[city1] = index;
                index++;
            }

            it = mapping.find(city2);

            if(it == mapping.end()){
                mapping[city2] = index;
                index++;
            }

            graph[mapping[city1]].push_back(make_pair(mapping[city2], weight));
            graph[mapping[city2]].push_back(make_pair(mapping[city1], weight));

        }

        cin>>city1>>city2;

        prim(graph, dist, mapping[city1]);

        aux = mapping[city2];

        while(father[aux] != -1){

            mini = min(mini, dist[aux]);
            aux = father[aux];
        }

        printf("Scenario #%i\n%i tons\n\n", counter, mini);
        counter++;
    }

    return 0;
}
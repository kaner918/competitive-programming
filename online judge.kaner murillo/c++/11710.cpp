//https://onlinejudge.org/external/117/11710.pdf
//11710

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<map>
#include<queue>
#include<string>

using namespace std;

bool prim(vector<vector<pair<int, int>>>&graph, vector<int>&dist, int&coste, int station){

    int i, auxStation, weight, auxWeight, size = dist.size(), sizeVisits = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<int>visits(size, 0);
    
    dist[station] = 0;
    q.push(make_pair(0, station));

    while(!q.empty()){

        weight = q.top().first;
        station = q.top().second;

        visits[station] = 1;

        q.pop();

        if(weight == dist[station]){

            coste+=weight;
            sizeVisits++;
            
            for(i = 0; i<graph[station].size(); i++){

                auxStation = graph[station][i].first;
                auxWeight = graph[station][i].second;

                if(!visits[auxStation] && auxWeight < dist[auxStation]){

                    dist[auxStation] = auxWeight;
                    q.push(make_pair(auxWeight, auxStation));
                } 
            }
        }
    }

    return sizeVisits == size;
}

int main(){

    int stations, conections, weight, i, coste;
    string station1, station2;

    while(scanf("%i %i", &stations, &conections) && (stations || conections)){

        map<string, int>mapping; 
        vector<vector<pair<int, int>>>graph(stations);
        vector<int>dist(stations, INT_MAX);
        coste = 0;

        for(i = 0; i<stations; i++){

            cin>>station1;
            mapping[station1] = i;
        }

        for(i = 0; i<conections; i++){

            cin>>station1>>station2>>weight;
            graph[mapping[station1]].push_back(make_pair(mapping[station2], weight));
            graph[mapping[station2]].push_back(make_pair(mapping[station1], weight));
        }   

        cin>>station1;

        if(prim(graph, dist, coste, mapping[station1])){
            printf("%i\n", coste);
        }

        else{
            printf("Impossible\n");
        }
    }

    return 0;
}
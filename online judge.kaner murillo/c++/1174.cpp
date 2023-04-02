//https://onlinejudge.org/external/11/1174.pdf
//1174

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<map>

using namespace std;

int prim(map<string, vector<pair<string, int>>>&graph, map<string, int>&dist, string&init){

    map<string, int>visits;
    dist[init] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>q;

    q.push(make_pair(0, init));

    int i, weight, auxWeight, coste = 0;
    string destiny;

    while(!q.empty()){

        weight = q.top().first;
        init = q.top().second;

        visits[init] = 1;

        q.pop();

        if(weight == dist[init]){

            coste+=weight;

            for(i = 0; i<graph[init].size(); i++){

                destiny = graph[init][i].first;
                auxWeight = graph[init][i].second;

                if(!visits[destiny] && auxWeight < dist[destiny]){

                    dist[destiny] = auxWeight;
                    q.push(make_pair(auxWeight, destiny));
                }
                
            }
        }
    }

    return coste;
}

int main(){

    int cases, cities, conections, coste;
    string citie1, citie2;

    scanf("%i", &cases);

    while(cases--){

        cin.ignore();

        scanf("%i", &cities);

        map<string, vector<pair<string, int>>>graph;
        map<string, int>dist;


        scanf("%i", &conections);

        while(conections--){

            cin>>citie1>>citie2>>coste;

            graph[citie1].push_back(make_pair(citie2, coste));
            graph[citie2].push_back(make_pair(citie1, coste));
            dist[citie1] = INT_MAX;
            dist[citie2] = INT_MAX;

        }   
        
        printf("%i\n", prim(graph, dist, citie1));

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}

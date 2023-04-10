//https://onlinejudge.org/external/100/10048.pdf
//10048

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

void prim(int node, vector<vector<pair<int, int>>>&graph, vector<pair<int, int>>&dist, vector<int>&pre, vector<int>&visits){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    dist[node].first = 0;
    dist[node].second = 0;

    q.push(make_pair(0, node));

    int i, auxNode, weight, auxWeight;

    while(!q.empty()){

        weight = q.top().first;
        node = q.top().second;
        visits[node] = 1;

        q.pop();

        if(weight == dist[node].first){

            for(i = 0; i<graph[node].size(); i++){

                auxNode = graph[node][i].first;
                auxWeight = graph[node][i].second;

                if(!visits[auxNode] && auxWeight < dist[auxNode].first){

                    pre[auxNode] = node;
                    dist[auxNode].first = auxWeight;
                    dist[auxNode].second = max(auxWeight, dist[node].second);
                    q.push(make_pair(auxWeight, auxNode));
                }
            }
        }
    }
}

int main(){

    int size, conections, queries, i, a, b, weight, counter = 1, mini, aux;

    while(scanf("%i %i %i", &size, &conections, &queries) && (size || conections || queries)){

        if(counter > 1){
            printf("\n");
        }

        vector<vector<pair<int, int>>>graph(size);
        
        for(i = 0; i<conections; i++){

            scanf("%i %i %i", &a, &b, &weight);

            graph[a-1].push_back(make_pair(b-1, weight));
            graph[b-1].push_back(make_pair(a-1, weight));
        }

        printf("Case #%i\n", counter);

        for(i = 0; i<queries; i++){

            scanf("%i %i", &a, &b);

            vector<pair<int, int>>dist(size, make_pair(INT_MAX, 0));
            vector<int>pre(size, -1);
            vector<int>visits(size, 0);

            prim(a-1, graph, dist, pre, visits);

            if(dist[b-1].first != INT_MAX){

                printf("%i\n", dist[b-1].second);
            }

            else{

                printf("no path\n");
            }
        }

        counter++;
    }
    return 0;
}
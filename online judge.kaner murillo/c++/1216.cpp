//https://onlinejudge.org/external/12/1216.pdf
//1216

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

int total;

void prim(vector<pair<int, int>>&graph, vector<int>&dist, vector<int>&pre){

    int i, node, weight, auxWeight;

    for(i = 0; i<dist.size(); i++){

        dist[i] = INT_MAX;

    }

    dist[0] = 0;
    vector<int>visits(graph.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    q.push(make_pair(0, 0));

    while(!q.empty()){

        weight = q.top().first;
        node = q.top().second;
        
        visits[node] = 1;

        q.pop();

        if(weight == dist[node]){
            
            total+= weight;

            for(i = 0; i<graph.size(); i++){

                if(i != node){

                    auxWeight = ceil(sqrt(pow(graph[i].first - graph[node].first, 2) + pow(graph[i].second - graph[node].second, 2)));

                    if(!visits[i] && auxWeight < dist[i]){

                        dist[i] = auxWeight;
                        pre[i] = node;
                        q.push(make_pair(auxWeight, i));
                    }
                }
            }
        }
    }
}

bool comp(int &a, int &b){

    return a > b;
}

int main(){

    int cases, receiver, x, y, i;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i", &receiver);
        vector<pair<int, int>>graph;
        total = 0;

        while(scanf("%i", &x) && x != -1){

            scanf("%i", &y);

            graph.push_back(make_pair(x, y));
        }

        vector<int>dist(graph.size());
        vector<int>pre(graph.size(), -1);

        prim(graph, dist, pre);

        sort(dist.begin(), dist.end(), comp);

        receiver--;
        
        printf("%i\n", dist[receiver]);

    }

    return 0;
}
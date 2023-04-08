//https://onlinejudge.org/external/103/10369.pdf
//10369

#include<cstdio>
#include<iostream>
#include<vector>
#include<cfloat>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

void prim(vector<pair<int, int>>&graph, vector<double>&dist){

    int i, node;
    double weight, auxWeight;

    dist[0] = 0.0;
    vector<int>visits(graph.size(), 0);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>q;

    q.push(make_pair(0, 0));

    while(!q.empty()){

        weight = q.top().first;
        node = q.top().second;
        
        visits[node] = 1;

        q.pop();

        if(weight == dist[node]){

            for(i = 0; i<graph.size(); i++){

                if(i != node){

                    auxWeight = sqrt(pow(graph[i].first - graph[node].first, 2) + pow(graph[i].second - graph[node].second, 2));

                    if(!visits[i] && auxWeight < dist[i]){

                        dist[i] = auxWeight;
                        q.push(make_pair(auxWeight, i));
                    }
                }
            }
        }
    }
}

bool comp(double &a, double &b){

    return a > b;
}

int main(){

    int cases, satellites, outposts, x, y;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &satellites, &outposts);
        vector<pair<int, int>>graph;
        vector<double>dist(outposts, DBL_MAX);

        while(outposts--){

            scanf("%i %i", &x, &y);
            graph.push_back(make_pair(x, y));
        }

        prim(graph, dist);

        sort(dist.begin(), dist.end(), comp);

        satellites--;

        printf("%.2lf\n", dist[satellites]);

    }

    return 0;
}
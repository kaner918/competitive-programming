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

void prim(vector<pair<int, int>>&graph, vector<pair<int, int>>&dist, vector<int>&pre){

    int i, node, weight, auxWeight;

    for(i = 0; i<dist.size(); i++){

        dist[i].first = i;
        dist[i].second = INT_MAX;
    }

    dist[0].second = 0;
    vector<int>visits(graph.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    q.push(make_pair(0, 0));

    while(!q.empty()){

        weight = q.top().first;
        node = q.top().second;
        
        visits[node] = 1;

        q.pop();

        if(weight == dist[node].second){
            
            total+= weight;

            for(i = 0; i<graph.size(); i++){

                if(i != node){

                    auxWeight = ceil(sqrt(pow(graph[i].first - graph[node].first, 2) + pow(graph[i].second - graph[node].second, 2)));

                    if(!visits[i] && auxWeight < dist[i].second){

                        dist[i].second = auxWeight;
                        pre[i] = node;
                        q.push(make_pair(auxWeight, i));
                    }
                }
            }
        }
    }
}

bool comp(pair<int, int>&a, pair<int, int>&b){

    return a.second > b.second;
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

        vector<pair<int, int>>dist(graph.size());
        vector<int>pre(graph.size(), -1);
        vector<int>receivers(graph.size(), 0);

        prim(graph, dist, pre);
        
        sort(dist.begin(), dist.end(), comp);

        /* cout<<"pre "<<total<<endl; */

        total = dist[0].second;

        for(i = 0; i<dist.size()-1 && receiver; i ++){

            if(!receivers[dist[i].first] && receiver){
                
                receivers[dist[i].first] = 1;
                receiver--;
            }

            if(receivers[dist[i].first]){

                if(receivers[pre[dist[i].first]]){

                    total = dist[i+1].second;
                }

                else if(!receivers[pre[dist[i].first]] && receiver){

                    total = dist[i+1].second;
                    receivers[pre[dist[i].first]] = 1;
                    receiver--;
                }
            }
        }

        printf("%i\n", total);

        /* for(i = 0; i<dist.size() && receiver; i ++){

            cout<<graph[dist[i].first].first<<","<<graph[dist[i].first].second<<" dist "<<dist[i].second<<" pre "<<graph[pre[dist[i].first]].first<<","<<graph[pre[dist[i].first]].second<<endl;
        } */
    }

    return 0;
}
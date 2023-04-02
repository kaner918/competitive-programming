//https://onlinejudge.org/external/118/11857.pdf
//11857

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

void prim(vector<vector<pair<int, int>>>&graph, vector<int>&dist, int&maxi, int&travels){

    int i, point, auxPoint, weight, auxWeight;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<int>visits(dist.size(), 0);
    
    dist[0] = 0;
    q.push(make_pair(0, 0));

    while(!q.empty()){

        weight = q.top().first;
        point = q.top().second;
        visits[point] = 1;
        
        q.pop();

        if(weight == dist[point]){

            maxi = max(maxi, weight);
            travels++;

            for(i = 0; i<graph[point].size(); i++){

                auxPoint = graph[point][i].first;
                auxWeight = graph[point][i].second;

                if(!visits[auxPoint] && auxWeight < dist[auxPoint]){

                    dist[auxPoint] = auxWeight;
                    q.push(make_pair(auxWeight, auxPoint));
                }
            }
        }
    }
}

int main(){

    int points, conections, i, point1, point2, weight, maxi, travels;

    while(scanf("%i %i", &points, &conections) && (points || conections)){

        vector<vector<pair<int, int>>>graph(points);
        vector<int>dist(points, INT_MAX);
        travels = 0;
        maxi = 0;

        for(i = 0; i<conections; i++){

            scanf("%i %i %i", &point1, &point2, &weight);
            graph[point1].push_back(make_pair(point2, weight));
            graph[point2].push_back(make_pair(point1, weight));
        }

        prim(graph, dist, maxi, travels);

        if(travels == points){
            printf("%i\n", maxi);
        }

        else{
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}
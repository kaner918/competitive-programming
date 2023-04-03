//https://onlinejudge.org/external/5/534.pdf
//534

#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cfloat>
#include<climits>

using namespace std;

int father[201];
double dist[201];

void init(int size){

    int i;

    for(i = 0; i<size; i++){
        dist[i] = DBL_MAX;
        father[i] = -1;
    }

    dist[0] = 0.0;
}

void prim(vector<pair<int, int>>&graph){

    int i, point, size = graph.size();

    double weight, auxWeight;

    init(size);
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>q;
    vector<int>visits(size, 0);

    q.push(make_pair(0.0, 0));

    while(!q.empty()){

        weight = q.top().first;
        point = q.top().second;
        
        visits[point] = 1;
        q.pop();

        if(weight == dist[point]){
            
            for(i = 0; i<size; i++){
                
                if(i != point){

                    auxWeight = sqrt(pow(graph[i].first - graph[point].first, 2) + pow(graph[i].second - graph[point].second, 2));

                    if(!visits[i] && auxWeight < dist[i]){

                        father[i] = point;
                        dist[i] = auxWeight;
                        q.push(make_pair(auxWeight, i));
                    }
                }
            }
        }
    }
}

int main(){

    int points, x, y, i, aux, counter = 1;
    double maxi;

    while(scanf("%i", &points) && points){

        vector<pair<int, int>>graph;
        maxi = 0.0;

        for(i = 0; i<points; i++){

            scanf("%i %i", &x, &y);
            graph.push_back(make_pair(x, y));
        }

        prim(graph);

        aux = 1;

        while(father[aux] != -1){

            maxi = max(maxi, dist[aux]);
            aux = father[aux];
        }

        printf("Scenario #%i\nFrog Distance = %.3lf\n\n", counter, maxi);
        counter++;
        cin.ignore();
    }

    return 0;   
}
//https://onlinejudge.org/external/100/10034.pdf
//10034

#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cmath>
#include<cfloat>

using namespace std;

double prim(vector<pair<double, double>>&graph){

    int size = graph.size(), node, i, auxNode;
    double auxWeight, weight, total;

    vector<double>dist(size, DBL_MAX);
    vector<int>visits(size, 0);

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>q;

    dist[0] = 0;
    q.push(make_pair(0, 0));
    total = 0.0;

    while(!q.empty()){

        weight = q.top().first;
        node = q.top().second;

        visits[node] = 1;

        q.pop();

        if(weight == dist[node]){

            total+=weight;

            for(i = 0; i<size; i++){

                if(i != node){

                    auxNode = i;
                    auxWeight = sqrt(pow(graph[node].first - graph[i].first, 2) + pow(graph[node].second - graph[i].second, 2));

                    if(!visits[i] && auxWeight < dist[i]){

                        /* cout<<graph[i].first<<" - "<<graph[i].second<<" - "<<auxWeight<<endl; */
                        dist[i] = auxWeight;
                        q.push(make_pair(auxWeight, i));
                    }
                }
            }
        }
    }

    /* for(i = 0; i<dist.size(); i++){

        cout<<dist[i]<<endl;
    }
 */

    return total;
}

int main(){

    int cases, points, i;
    double x, y, res;

    scanf("%i", &cases);
    cin.ignore();

    while(cases--){

        scanf("%i", &points);

        vector<pair<double, double>>graph; 

        while(points--){

            scanf("%lf %lf", &x, &y);
            graph.push_back(make_pair(x, y));
        }

        /* for(i = 0; i<graph.size(); i++){

            cout<<graph[i].first<<" - "<<graph[i].second<<endl;
        } */
        res = prim(graph); 

        printf("%.2lf\n", res);

        if(cases > 0) cin.ignore(), printf("\n");
    }

    return 0;
}
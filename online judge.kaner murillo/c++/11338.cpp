//https://onlinejudge.org/external/113/11338.pdf
//11338

#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<cfloat>
#include<string>
#include<sstream>

using namespace std;

bool dijkstra(vector<vector<pair<int, double>>>&graph, double maxDistance){

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>q;
    vector<double>dist(graph.size(), DBL_MAX);

    q.push(make_pair(0, 0));
    dist[0] = 0;

    int node, auxNode, i;
    double coste, weight;

    while(!q.empty()){

        coste = q.top().first;
        node = q.top().second;

        q.pop();
        
        if(node == 1){
            
            return 1;
        }

        for(i = 0; i<graph[node].size(); i++){

            auxNode = graph[node][i].first;
            weight = graph[node][i].second;

            if(coste + weight < dist[auxNode] && coste + weight <= maxDistance){

                dist[auxNode] = coste + weight;
                q.push(make_pair(coste + weight, auxNode));
            }
        }
    }

    return 0;
}

int main(){

    int w, h, i, n, points;
    double x, y, maxDistance;
    string line = "";

    while(getline(cin, line) && line != "*"){

        stringstream stk(line);
        stk>>w>>h;
        
        scanf("%i", &points);

        vector<pair<double, double>>savePoints = {{0, 0}, {w,h}};
        vector<vector<pair<int, double>>>graph(points+2);

        while(points--){

            cin>>x>>y;
            savePoints.push_back(make_pair(x, y));
        }
        
        for(i = 0; i<savePoints.size()-1; i++){

            for(n = i+1; n<savePoints.size(); n++){

                x = sqrt(pow(savePoints[i].first - savePoints[n].first, 2) + pow(savePoints[i].second - savePoints[n].second, 2));

                /* cout<<savePoints[i].first<<" "<<savePoints[i].second<<" "<<savePoints[n].first<<" "<<savePoints[n].second<<" "<<x<<endl; */

                if(x<=1.5){

                    graph[i].push_back(make_pair(n, x));
                    graph[n].push_back(make_pair(i, x));
                }
            }
        }

        cin>>maxDistance;

        if(dijkstra(graph, maxDistance)){

            printf("I am lucky!\n");
        }

        else{

            printf("Boom!\n");
        }

        cin.ignore();
    }
    return 0;
}
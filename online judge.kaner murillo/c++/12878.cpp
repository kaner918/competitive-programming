//https://onlinejudge.org/external/128/12878.pdf
//12878

#include<climits>
#include<vector>
#include<queue>
#include<tuple>
#include<iostream>
#include<algorithm>

using namespace std;

int points, res, re;
vector<int>pre(10000);
vector<int>cost(10000);

void initialize(int init){

    int i;

    for(i = 0; i<points; i++){

        cost[i] = INT_MAX;
        pre[i] = -1;
    }

    cost[init] = 0;
}

void dijkstra(int init, vector<vector<tuple<int, int, int>>>&graph){

    int weight, auxCost, vertex, vertexAd, i, recar;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>cola;

    initialize(init);
    cola.push(make_tuple(init, 0, 0));

    while(!cola.empty()){

        vertex = get<0>(cola.top());
        auxCost = get<1>(cola.top());
        recar = get<2>(cola.top());

        cola.pop();
        //cout<<vertex<<" "<<auxCost<<endl;
        
        if(vertex == points-1 && auxCost == cost[vertex]) res+=auxCost, re+=recar;
        
        else if(auxCost == cost[vertex]){

            for(i = 0; i<graph[vertex].size(); i++){

                vertexAd = get<0>(graph[vertex][i]);
                weight = get<1>(graph[vertex][i]);
                
                if(auxCost != INT_MAX && auxCost + weight < cost[vertexAd] && vertexAd != points-1){
                    
                    pre[vertexAd] = vertex;
                    cost[vertexAd] = auxCost + weight;
                    cola.push(make_tuple(vertexAd, cost[vertexAd], recar+get<2>(graph[vertex][i])));
                } 

                else if(auxCost != INT_MAX && auxCost + weight < cost[vertexAd] && vertexAd == points-1) cost[vertexAd] = auxCost + weight, res = auxCost + weight, re = recar+get<2>(graph[vertex][i]);

                else if(auxCost != INT_MAX && auxCost + weight == cost[vertexAd] && vertexAd == points-1) cola.push(make_tuple(vertexAd, cost[vertexAd], 0));
            }
        }
    }
    
}

int main(){

    int trails, length, a, b, size, counter = 1;

    while(scanf("%i %i", &points, &trails) != EOF){

        vector<vector<tuple<int, int, int>>>graph(points);
        vector<tuple<int, int, int>>::iterator it;
        vector<tuple<int, int, int>>::iterator it2;  
        
        res = 0;
        re = 0;
        while(trails--){

            scanf("%i %i %i", &a, &b, &size);

            for(it = graph[a].begin(); it != graph[a].end() && (get<0>(*it) != b || get<1>(*it) != size); it++);
            for(it2 = graph[b].begin(); it2 != graph[b].end() && (get<0>(*it2) != a || get<1>(*it2) != size); it2++);

            if(it != graph[a].end()) get<2>(*it)+=size, get<2>(*it2)+=size;

            else graph[a].push_back(make_tuple(b, size, 0)), graph[b].push_back(make_tuple(a, size, 0));

        }

        dijkstra(0, graph);
        cout<<(res+re)*2<<" "<<counter<<endl;
        counter++;
    }

}
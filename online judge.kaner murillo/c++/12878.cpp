//https://onlinejudge.org/external/128/12878.pdf
//12878

#include<climits>
#include<vector>
#include<queue>
#include<tuple>
#include<iostream>
#include<algorithm>

using namespace std;

int points, re;
vector<int>pre(10000);
vector<int>cost(10000);
vector<int>cost2(10000);

void initialize(int init){

    int i;

    for(i = 0; i<points; i++){

        cost[i] = INT_MAX;
        pre[i] = -1;
    }

    cost[init] = 0;
}

void dijkstra(int init, vector<vector<tuple<int, int, int>>>&graph, vector<int>&res){

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
    
        if(auxCost == cost[vertex]){

            for(i = 0; i<graph[vertex].size(); i++){

                vertexAd = get<0>(graph[vertex][i]);
                weight = get<1>(graph[vertex][i]);
                
                if(vertexAd == points-1){

                    if(auxCost + weight < cost[vertexAd]){
                        res = {vertex};
                        re = recar;
                    }

                    else if(auxCost + weight == cost[vertexAd]){
                        res.push_back(vertex);
                        re+=recar;
                    }

                }
                if(auxCost != INT_MAX && auxCost + weight < cost[vertexAd]){
                    
                    pre[vertexAd] = vertex;
                    cost[vertexAd] = auxCost + weight;
                    cola.push(make_tuple(vertexAd, cost[vertexAd], recar+get<2>(graph[vertex][i])));

                } 
            }
        }
    }
    
}

int main(){

    int trails, length, a, b, size, counter, i;

    while(scanf("%i %i", &points, &trails) != EOF){

        vector<vector<tuple<int, int, int>>>graph(points);
        vector<tuple<int, int, int>>::iterator it;
        vector<tuple<int, int, int>>::iterator it2;  
        vector<int>res;
        re = 0;
        counter = 0;

        while(trails--){

            scanf("%i %i %i", &a, &b, &size);
            
            for(it2 = graph[b].begin(); it2 != graph[b].end() && (get<0>(*it2) != a || get<1>(*it2) != size); it2++);
            for(it = graph[a].begin(); it != graph[a].end() && (get<0>(*it) != b || get<1>(*it) != size); it++);

            if(it != graph[a].end()) get<2>(*it)+=size, get<2>(*it2)+=size;

            else graph[a].push_back(make_tuple(b, size, 0)), graph[b].push_back(make_tuple(a, size, 0));

        }

        dijkstra(0, graph, res);

        for(i = 0; i<res.size(); i++){

            a = res[i]; 
            
            counter+= cost[points-1] - cost[a];

            while(pre[a] != -1){

                counter+= cost[a] - cost[pre[a]];
                a = pre[a];
            }
        }
        
        printf("%i\n", (counter + re) * 2);
    }

}
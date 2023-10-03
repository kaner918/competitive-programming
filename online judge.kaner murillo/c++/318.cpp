//https://onlinejudge.org/external/3/318.pdf
//318

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int maxi, counter, node1, node2;
double res;
vector<int>visits(501);
vector<int>visits2(501);
vector<int>fathers(501);

void dijkstra(vector<vector<pair<int, int>>>&graph){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    q.push({0, 0});
    visits[0] = 0;
    int i, node, coste;

    while(!q.empty()){

        coste = q.top().first;
        node = q.top().second;
        q.pop();

        if(coste == visits[node]){

            if(visits[node] >= maxi){
                maxi = visits[node];
                node1 = node;
            }

            for(i = 0; i<graph[node].size(); i++){
                
                if(coste + graph[node][i].second < visits[graph[node][i].first]){
                    q.push({coste + graph[node][i].second, graph[node][i].first});
                    visits[graph[node][i].first] = coste + graph[node][i].second;
                    fathers[graph[node][i].first] = node;
                }
            }
        }
    }
}

void bfs2(vector<vector<pair<int, int>>>&graph){

    queue<int>q;
    q.push(0);
    visits2[0] = 1;
    int i, node, flag = 1, aux = 0, dist = 0;
    double auxito = maxi ;

    while(!q.empty()){

        node = q.front();
        flag = 1;
        q.pop();

        for(i = 0; i<graph[node].size(); i++){
            
            if(!visits2[graph[node][i].first]){ 
                q.push(graph[node][i].first);
                visits2[graph[node][i].first] = 1;
                 
            }

            if(fathers[node]!=graph[node][i].first && fathers[graph[node][i].first]!= node && visits[graph[node][i].first] + graph[node][i].second > visits[node]){

                if(visits[node] + ((visits[graph[node][i].first] + graph[node][i].second-visits[node]) / 2.0) > auxito){

                    node1 = node;
                    node2 = graph[node][i].first;
                    auxito = visits[node] + (((visits[graph[node][i].first] + graph[node][i].second)-visits[node]) / 2.0);
                    counter = 2;
                }
                
                /* cout<<graph[node][i].first<<" "<<visits[graph[node][i].first]+ graph[node][i].second<<endl; */
            }
        }
    }

    res = auxito;
}

int main(){

    int nodes, conections, i, a, b, t, counter2 = 1;

    while(scanf("%i %i", &nodes, &conections) && (nodes || conections)){
        
        vector<vector<pair<int, int>>>graph(nodes);
        maxi = 0;
        counter = 1;
        for(i = 0; i<nodes; i++){
            visits[i] = INT_MAX;
            visits2[i] = 0;
            fathers[i] = -1;
        }

        for(i = 0; i<conections; i++){
            scanf("%i %i %i", &a, &b, &t);
            a--,b--;
            graph[a].push_back({b, t}); 
            graph[b].push_back({a, t});
        }
        dijkstra(graph);
        res = maxi;
        bfs2(graph);

        printf("System #%i\n", counter2++);
        
        if(counter == 1){
            printf("The last domino falls after %.1f seconds, at key domino %i.\n", res, node1+1);
        }

        else{
            printf("The last domino falls after %.1f seconds, between key dominoes %i and %i.\n", res, node1+1, node2+1);
        }

        printf("\n");
    }

    return 0;
}
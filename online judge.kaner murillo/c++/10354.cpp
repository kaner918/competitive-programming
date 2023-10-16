//https://onlinejudge.org/external/103/10354.pdf
//10354

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int lives_boss, office, lives_me, market;
vector<int>nones(101);

void dijkstra1(vector<vector<pair<int, int>>>&graph){

    int j, i, node, coste, mini = INT_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<int>dist(graph.size(), INT_MAX);
    vector<int>pre(101, -1);
    vector<int>flags(101, 0);
    dist[lives_boss] = 0;
    q.push({0, lives_boss});
    vector<vector<int>>not_nodes(graph.size());

    while(!q.empty()){

        coste = q.top().first;
        node = q.top().second;
        q.pop();

        if(coste == dist[node]){
            for(i = 0; i<graph[node].size(); i++){
                if(dist[graph[node][i].first] > coste + graph[node][i].second){
                    q.push({coste + graph[node][i].second, graph[node][i].first});
                    dist[graph[node][i].first] = coste + graph[node][i].second;
                    pre[graph[node][i].first] = node;
                    not_nodes[graph[node][i].first] = {node};
                }

                else if(dist[graph[node][i].first] == coste + graph[node][i].second){
                    not_nodes[graph[node][i].first].push_back(node);
                }
            }
        }
    }

    for(i = 0; i<graph.size(); i++){
        nones[i] = 0;
    }
    nones[office] = 1;
    queue<int>q1;
    q1.push(office);
    
    while(!q1.empty()){

        node = q1.front();
        nones[node] = 1;
        q1.pop();

        for(i = 0; i<not_nodes[node].size(); i++){
            q1.push(not_nodes[node][i]);
        }
    }
}

int dijkstra2(vector<vector<pair<int, int>>>&graph){

    int i, node, coste;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<int>dist(graph.size(), INT_MAX);
    dist[lives_me] = 0;
    q.push({0, lives_me});

    if(lives_me == market && nones[lives_me] || nones[lives_me]){
        return INT_MAX;
    }

    while(!q.empty()){

        coste = q.top().first;
        node = q.top().second;
        q.pop();

        if(coste == dist[node] && node != market){
            for(i = 0; i<graph[node].size(); i++){
                if(!nones[graph[node][i].first] && dist[graph[node][i].first] > coste + graph[node][i].second){
                    q.push({coste + graph[node][i].second, graph[node][i].first});
                    dist[graph[node][i].first] = coste + graph[node][i].second;
                }
            }
        }
    }

    return dist[market];
}

int main(){

    int size, conections, a, b, i, coste;

    while(scanf("%i %i %i %i %i %i", &size, &conections, &lives_boss, &office, &lives_me, &market) != EOF){
        
        lives_boss--, lives_me--, office--, market--;  
        vector<vector<pair<int, int>>>graph(size);

        for(i = 0; i<conections; i++){
            scanf("%i %i %i", &a, &b, &coste);
            a--, b--;
            graph[a].push_back({b, coste});
            graph[b].push_back({a, coste});
        }
        coste = INT_MAX;
        if(lives_me != lives_boss && lives_me != office && lives_boss != market && office != market){

            dijkstra1(graph);
            coste = dijkstra2(graph);
        }

        if(coste == INT_MAX){
            printf("MISSION IMPOSSIBLE.\n");
        }
        else{
            printf("%i\n", coste);
        }
    } 
    
    return 0;
}
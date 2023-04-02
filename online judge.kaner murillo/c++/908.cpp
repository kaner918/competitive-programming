//https://onlinejudge.org/external/9/908.pdf
//908

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<climits>

using namespace std;

int prim(vector<vector<pair<int, int>>>&graph, vector<int>&dist){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    dist[0] = 0;
    q.push(make_pair(0, 0));

    int i, size = dist.size(), node, weight, auxNode, auxWeight, coste = 0;

    vector<int>visits(size, 0);

    while(!q.empty()){

        weight = q.top().first;
        node = q.top().second;

        visits[node] = 1;

        q.pop();

        if(weight == dist[node]){

            coste+=weight;

            for(i = 0; i<graph[node].size(); i++){

                auxNode = graph[node][i].first;
                auxWeight = graph[node][i].second;

                if(!visits[auxNode] && auxWeight < dist[auxNode]){

                    dist[auxNode] = auxWeight;
                    q.push(make_pair(auxWeight, auxNode));
                }
            }
        }
    }
    
    return coste;

}

int main(){

    int size, node1, node2, coste, total;
    bool flag = true;
    string end;

    while(flag && scanf("%i", &size)){

        total = 0;

        vector<vector<pair<int, int>>>graph(size);
        vector<int>dist(size, INT_MAX);

        size--;

        while(size--){

            scanf("%i %i %i", &node1, &node2, &coste);
            total+=coste;
        }

        scanf("%i", &size);

        while(size--){

            scanf("%i %i %i", &node1, &node2, &coste);
            graph[node1-1].push_back(make_pair(node2-1, coste));
            graph[node2-1].push_back(make_pair(node1-1, coste));
        }

        scanf("%i", &size);

        while(size--){

            scanf("%i %i %i", &node1, &node2, &coste);
            graph[node1-1].push_back(make_pair(node2-1, coste));
            graph[node2-1].push_back(make_pair(node1-1, coste));
        }

        printf("%i\n", total);
        total = min(total, prim(graph, dist));
        printf("%i\n", total);

        cin.ignore();
        
        if(!getline(cin, end)){
            flag = false;
        }

        else{

            printf("\n");
        }
    }

    return 0;
}
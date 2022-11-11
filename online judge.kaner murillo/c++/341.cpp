//https://onlinejudge.org/external/3/341.pdf
//341

#include<cstdio>
#include<climits>
#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int size;
vector<int>d(10);
vector<int>p(10);

void init(int init){

    int i;

    for(i = 0; i<size; i++){

        d[i] = INT_MAX;
        p[i] = -1;
    }

    d[init] = 0;
}

void dijkstra(int s, vector<vector<pair<int, int>>>&graph){

    int i, j, k, u, v, peso, costo;

    init(s);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>cola;
    cola.push(make_pair(0, s));

    while(!cola.empty()){

        costo = cola.top().first;
        u = cola.top().second;
        cola.pop();

        if(costo == d[u]){

            for(j = 0; j<graph[u].size(); j++){

                v = graph[u][j].first;
                peso = graph[u][j].second;

                if(d[u] != INT_MAX && d[u] + peso < d[v]){

                    d[v] = d[u] + peso;
                    p[v] = u;
                    cola.push(make_pair(d[v], v));
                }  
            }
        }
    }
}

int main(){

    int i, n, a, coste, position, conections, counter = 1;

    while(scanf("%i", &size) && size != 0 ){ 

        vector<int>res;
        vector<vector<pair<int, int>>>graph(10);

        for(i = 0; i<size; i++){

            scanf("%i", &conections);

            for(n = 0; n<conections; n++){

                scanf("%i %i", &a, &coste);

                graph[i].push_back(make_pair(a-1, coste));

            }
        }

        scanf("%i %i", &a, &coste);
    
        coste--;
        position = coste;

        dijkstra(a-1, graph);

        while(p[coste] != -1){

            res.push_back(coste+1);
            coste = p[coste];
        }

        printf("Case %i: Path = %i", counter, a);

        for(i = res.size()-1; i>-1; i--){

            printf(" %i", res[i]);
        }

        printf("; %i second delay\n", d[position]);
        
        counter++;
        cin.ignore();

    }

    return 0;
}
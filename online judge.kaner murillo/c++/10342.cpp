//https://onlinejudge.org/external/103/10342.pdf
//10342

#include<queue>
#include<vector>
#include<iostream>
#include<climits>

using namespace std;

int size = 4;
vector<vector<int>>d(100);
vector<int>p(100);

void init(int s){

    int i;

    for(i = 0; i<size; i++){
        
        d[i].push_back(INT_MAX);
        p[i] = -1;
    }

    d[s][0] = 0; 
}

void dijkstra(int s, vector<vector<pair<int, int>>>&graph){

    int i, j, u, v, costo, peso;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>cola;
    init(s);

    cola.push(make_pair(0, s));

    while(!cola.empty()){

        costo = cola.top().first;
        u = cola.top().second;
        cola.pop();

        //if(costo == d[u][d[u].size()-1]){

            for(i = 0; i<graph[u].size(); i++){

                v = graph[u][i].first;
                peso = graph[u][i].second;

                if(d[u][d[u].size()-1] != INT_MAX && d[u][d[u].size()-1]  + peso < d[v][d[v].size()-1]){

                    cola.push(make_pair(d[v][d[v].size()-1], v));
                    d[v].push_back(d[u][d[u].size()-1]  + peso);
                    
                }
            }
        //}
    }
}


int main(){

    vector<vector<pair<int, int>>>graph(4);
    int i, n, a, b, size2;

    for(i = 0; i<3; i++){

        scanf("%i %i %i", &a, &b, &size2);
        graph[a].push_back(make_pair(b, size2));
        graph[b].push_back(make_pair(a, size2));

    }

    dijkstra(0, graph);

    for(i = 0; i<size; i++){

        cout<<"coste:";

        for(n = 0; n<d[i].size(); n++){

            cout<<d[i][n]<<" ";

        }

        cout<<endl;
    }
    


    return 0;
}
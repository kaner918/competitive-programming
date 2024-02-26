//https://onlinejudge.org/external/118/11813.pdf
//11813

#include<cstdio>
#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<map>

using namespace std;

int costes[12][12], stores[12], dist[100002], mem[12][4097], maxi, limit;

void dijkstra(int init, map<int, int>&index, vector<vector<pair<int, int>>>&graph){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    int auxNode, coste, weight, i, node;

    q.push({0, init});
    dist[init] = 0;

    while(!q.empty()){
        coste = q.top().first;
        node = q.top().second;
        q.pop();
        if(coste == dist[node]){
            for(i = 0; i<graph[node].size(); i++){
                auxNode = graph[node][i].first;
                weight = graph[node][i].second;

                if(weight + coste < dist[auxNode]){
                    dist[auxNode] = weight + coste;
                    q.push({dist[auxNode], auxNode});
                }
            }
        }
    }
    for(map<int, int>::iterator it = index.begin(); it != index.end(); it++){
        costes[index[init]][it->second] = dist[it->first];
    }
}

int travel(int store, int size, int mask){

    int ans = limit;
    cout<<mask<<endl;
    if(mask == ((1<<store) | 3)){
        ans = costes[1][store];
    }

    else if(mem[store][mask]){
        ans = mem[store][mask];
    }

    else{

        int i;

        for(i = 2; i<=size; i++){
            if((mask & (1<<i)) && store != i){
                ans = min(ans, travel(i, size, mask & (~(1<<store)))+costes[i][store]);
            }
        }
        mem[store][mask] = ans;
    }

    return ans;
}

int tps(int size){

    int ans  = limit, cal , i;

    for(i = 1; i<=size; i++){
        cal = travel(i, size, (1<<(size+1))-1)+costes[i][1];
        ans = min(ans, cal);
    }

    return ans;
}

int main(){

    int cases, i, j, k, n, m, a, b, coste, size_stores, counter;

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){
        
        for(j = 0; j<12; j++){
            for(k = 0; k<4096; k++){
                mem[j][k] = 0;
            }
        }

        scanf("%i %i", &n, &m);
        vector<vector<pair<int, int>>>graph(n+1);
        map<int, int>index;
        stores[0] = 1;
        index[1] = 1;
        maxi = 0;

        for(j = 0; j<m; j++){
            scanf("%i %i %i", &a, &b, &coste);
            a++, b++;
            maxi=max(maxi, coste);
            graph[a].push_back({b, coste});
            graph[b].push_back({a, coste});
        }        

        limit = n*maxi + 100;

        scanf("%i", &size_stores);

        for(j = 1; j<=size_stores; j++){
            scanf("%i", &a);
            a++;
            index[a] = j+1;
            stores[j] = a;
        }

        for(j = 0; j<=size_stores; j++){
            for(k = 0; k<=n; k++){
                dist[k] = INT_MAX;
            }
            dijkstra(stores[j], index, graph);
        }

        cout<<tps(size_stores+1)<<endl;
    }

    return 0;
}
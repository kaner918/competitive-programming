//https://onlinejudge.org/external/121/12144.pdf
//12144

#include<climits>
#include<vector>
#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;
int best;
int counter;

vector<int> dijkstra(vector<vector<pair<int, int>>>&graph, vector<int>&visits, vector<int>&visits2, vector<int>&pre, int init, int destiny, int p){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    q.push(make_pair(init, 0));
    visits[init] = 0;
    vector<int>res;

    int node, coste, auxNode, auxCoste, i;

    while(!q.empty()){

        node = q.top().first;
        coste = q.top().second;
        
        q.pop();

        if(coste == visits[node]){

            for(i = 0; i<graph[node].size(); i++){

                auxNode = graph[node][i].first;
                auxCoste = graph[node][i].second;

                if(auxNode == destiny){
                    

                    if(visits[auxNode] != INT_MAX && auxCoste + coste == visits[auxNode]){

                        res.push_back(node);
                    }

                    else if(auxCoste + coste < visits[auxNode] && ((p == 1 && node != init)  || (p == 0))){
                        
                        //cout<<node<<"-"<<auxCoste + coste<<endl;
                        res = {node};
                        visits[auxNode] = auxCoste + coste;
                        best = visits[auxNode];
                    }
                    
                }

                else{

                    if(auxCoste + coste < visits[auxNode] && visits2[auxNode] == -1){
                        
                        pre[auxNode] = node;
                        visits[auxNode] = auxCoste + coste;
                        q.push(make_pair(auxNode, visits[auxNode]));
                    }
                }
            }
        }
    }

    return res;
}

int main(){

    int nodes, conections, i, node, node2, weight, init, destiny, aux, p;

    while(scanf("%i %i", &nodes, &conections) && (nodes!= 0 || conections != 0)){

        counter = 0;
        p = 0;
        vector<vector<pair<int, int>>>graph(nodes);
        vector<int>visits(nodes, INT_MAX);
        vector<int>visits2(nodes, -1);
        vector<int>pre(nodes, -1);
        vector<int>none;

        scanf("%i %i", &init, &destiny);

        while(conections--){

            scanf("%i %i %i", &node, &node2, &weight);
            graph[node].push_back(make_pair(node2, weight));
        }

        none = dijkstra(graph, visits, visits2, pre, init, destiny, p);
        best = -1;

        for(i = 0; i<none.size(); i++){

            aux = none[i];
            //cout<<none[i]<<endl;

            if(aux == init){

                p = 1;

            }

            else{

                while(pre[aux] != -1){
                    
                    counter++;
                    visits2[aux] = 1;
                    aux = pre[aux];
                } 
            }
        }
        
        
        /* for(i = 0; i<visits2.size(); i++){

            cout<<i<<"-"<<visits2[i]<<endl;
        }  */

        vector<int>visits3(nodes, INT_MAX);
        none = dijkstra(graph, visits3, visits2, pre, init, destiny, p);

        printf("%i\n", best);
    }
    return 0;
}
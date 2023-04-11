//https://onlinejudge.org/external/113/11367.pdf
//11367

#include<cstdio>
#include<vector>
#include<iostream>
#include<climits>
#include<queue>
#include<set>
#include<tuple>

using namespace std;

struct State{

    int coste, tank, position;

    State(){}
    State(int coste, int tank, int position){

        this->coste = coste;
        this->tank = tank;
        this->position = position;
    }

    bool operator<(const State&other)const{

        if(coste == other.coste){

            return tank < other.tank;
        }

        return coste > other.coste;
    }
};

int dijkstra(vector<vector<pair<int, int>>>&graph, vector<int>&costes, int init, int finish, int capacity){

    set<tuple<int, int, int>>conj;
    vector<int>dist(graph.size(), INT_MAX);
    vector<int>ls(graph.size(), 0);
    priority_queue<State>q;
    tuple<int, int, int>aux = make_tuple(init, init, 0);

    q.push(State(0, 0, init));
    conj.insert(aux);

    int i, coste, tank, weight, auxCoste, auxNode;

    while(!q.empty()){


        init = q.top().position;
        coste = q.top().coste;
        tank = q.top().tank;
        
        q.pop();

        if(init == finish){

            return coste;
        }

        aux = make_tuple(init, init, tank+1);
        auto it = conj.find(aux);

        if(it == conj.end() && tank+1 <= capacity){

            conj.insert(aux);
            q.push(State(coste+costes[init], tank+1, init));
        }

        for(i = 0; i<graph[init].size(); i++){

            auxNode = graph[init][i].first;
            weight = graph[init][i].second;

            if(tank >= weight){

                aux = make_tuple(init, auxNode, tank-weight);

                auto it = conj.find(aux);

                if(it == conj.end() && (dist[auxNode] > coste || ls[auxNode] < tank-weight)){
                
                    if(dist[auxNode] > coste){
                        dist[auxNode] = coste;
                    }

                    if(ls[auxNode] < tank-weight){

                        ls[auxNode] = tank-weight;
                    }

                    conj.insert(aux);
                    q.push(State(coste, tank-weight, auxNode));
                }
            }
        }
    }

    return -1;
}

int main(){

    int citys, i, coste, weight, ans, queries, init, finish, capacity, conections;

    scanf("%i %i", &citys, &conections);
    vector<int>costes;
    vector<vector<pair<int, int>>>graph(citys);

    for(i = 0; i<citys; i++){

        scanf("%i", &coste);
        costes.push_back(coste);
    }

    while(conections--){

        scanf("%i %i %i", &init, &finish, &weight);
        graph[init].push_back(make_pair(finish, weight));
        graph[finish].push_back(make_pair(init, weight));
    }    

    scanf("%i", &queries);

    while(queries--){

        scanf("%i %i %i", &capacity, &init, &finish);

        ans = dijkstra(graph, costes, init, finish, capacity);

        if(ans != -1){

            printf("%i\n", ans);
        }

        else{
            printf("impossible\n");
        }
    }

    return 0;   
}
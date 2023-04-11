//https://onlinejudge.org/external/120/12047.pdf
//12047

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<tuple>

using namespace std;

struct State{

    int maxi, coste, position;

    State(){}
    State(int maxi, int coste, int position){

        this->maxi = maxi;
        this->coste = coste;
        this->position = position;
    }

    bool operator<(const State&other)const{
        
        return coste < other.coste;
    }
};

int dijkstra(vector<vector<pair<int, int>>>&graph, int init, int finish, int p){

    int i, auxNode, maxi, auxMaxi, weight, coste, higer = -1;

    priority_queue<State>q;
    set<tuple<int, int, int>>conj;
    tuple<int, int, int>aux = make_tuple(0, init, init);

    q.push(State(0, 0, init));
    conj.insert(aux);

    while(!q.empty()){

        init = q.top().position;
        coste = q.top().coste;
        maxi = q.top().maxi;

        q.pop();    

        if(init == finish){

            higer = max(higer, maxi);
        }

        for(i = 0; i<graph[init].size(); i++){

            auxNode = graph[init][i].first;
            weight = graph[init][i].second;
            auxMaxi = max(maxi, weight);

            if(coste + weight <= p){

                aux = make_tuple(auxMaxi, init, auxNode);
                auto it = conj.find(aux);

                if(it == conj.end()){

                    conj.insert(aux);
                    q.push(State(auxMaxi, coste+weight, auxNode));
                }
            }
        }
    }

    return higer;
}

int main(){ 

    int cases, junctions, roads, init, finish, p, junction1, junction2, weight;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i %i %i %i", &junctions, &roads, &init, &finish, &p);

        vector<vector<pair<int, int>>>graph(junctions);

        while(roads--){

            scanf("%i %i %i", &junction1, &junction2, &weight);
            graph[junction1-1].push_back(make_pair(junction2-1, weight));
        }

        printf("%i\n", dijkstra(graph, init-1, finish-1, p));
    }

    return 0;
}
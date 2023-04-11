//https://onlinejudge.org/external/103/10356.pdf
//10356

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<tuple>

using namespace std;

struct State{

    int coste, position;
    bool cycle;

    State(){}
    State(int coste, int position, bool cycle){

        this->coste = coste;
        this->position = position;
        this->cycle = cycle;
    }

    bool operator<(const State&other)const{

        return coste > other.coste;
    }

};

int dijkstra(vector<vector<pair<int, int>>>&graph, int size){

    int i, node, auxNode, weight, coste;
    bool cycle;

    priority_queue<State>q;
    set<tuple<int, int, bool>>conj;
    tuple<int, int, bool>aux = make_tuple(0, 0, true);

    conj.insert(aux);
    q.push(State(0, 0, true));

    while(!q.empty()){

        node = q.top().position;
        coste = q.top().coste;
        cycle = q.top().cycle;

        q.pop();

        if(node == size && cycle){

            return coste;
        }

        else{

            for(i = 0; i<graph[node].size()+; i++){

                auxNode = graph[node][i].first;
                weight = graph[node][i].second;

                aux = make_tuple(node, auxNode, !cycle);
                auto it = conj.find(aux);

                if(it == conj.end()){

                    conj.insert(aux);

                    q.push(State(coste + weight, auxNode, !cycle));
                }
            }
        }
    }

    return -1;
}

int main(){

    int junctions, roads, i, junctions1, junctions2, weight, ans, counter = 1;

    while(scanf("%i %i", &junctions, &roads) != EOF){

        vector<vector<pair<int, int>>>graph(junctions);

        while(roads--){

            scanf("%i %i %i", &junctions1, &junctions2, &weight);

            graph[junctions1].push_back(make_pair(junctions2, weight));
            graph[junctions2].push_back(make_pair(junctions1, weight));
        }

        printf("Set #%i\n", counter++);
        ans = dijkstra(graph, junctions-1);

        if(ans == -1){

            printf("?\n");
        }

        else{

            printf("%i\n", ans);
        }
    }    

    return 0;
}
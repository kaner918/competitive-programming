//https://onlinejudge.org/external/129/12950.pdf
//12950

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<set>
#include<tuple>

using namespace std;

struct State{

    int coste, position, size;

    State(){}
    State(int coste, int position, int size){

        this->coste = coste;
        this->position = position;
        this->size = size;
    }

    bool operator<(const State&other)const{

        return coste > other.coste;
    }
};

int dijkstra(vector<vector<pair<int, int>>>&graph){

    int finish = graph.size()-1;

    set<tuple<int, int, bool>>conj;
    tuple<int, int, bool>aux;
    priority_queue<State>q;

    q.push(State(0, 0, 0));
    conj.insert(make_tuple(0, 0, true));

    int i, node, size, auxNode, coste, weight;

    while(!q.empty()){

        coste = q.top().coste;
        node = q.top().position;
        size = q.top().size;

        /*cout<<"node "<<node+1<<" coste "<<coste<<" size "<<size<<endl;*/

        q.pop();

        if(node == finish && !(size%2)){

            /* cout<<coste<<endl; */
            return coste;
        }

        for(i = 0; i<graph[node].size(); i++){

            auxNode = graph[node][i].first;
            weight = graph[node][i].second;

            aux = make_tuple(node, auxNode, !((size+1)%2));

            auto it = conj.find(aux);

            if(it == conj.end()){

                conj.insert(aux);
                q.push(State(coste + weight, auxNode, size+1));
            }
        }
    }

    return -1;
}

int main(){

    int c, v, a, b, weight, i;

    while(scanf("%i %i", &c, &v) != EOF){

        vector<vector<pair<int, int>>>graph(c);

        while(v--){

            scanf("%i %i %i", &a, &b, &weight);
            graph[a-1].push_back(make_pair(b-1, weight));
            graph[b-1].push_back(make_pair(a-1, weight));
        }

        printf("%i\n", dijkstra(graph));
    }

    return 0;
}
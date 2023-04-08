//https://onlinejudge.org/external/104/10457.pdf
//10457

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<set>
#include<tuple>

using namespace std;

struct State{

    int pre, speed, position, maxi, mini, maxi2;

    State(){}
    State(int pre, int speed, int position, int maxi, int maxi2, int mini){

        this->pre = pre;
        this->speed = speed;
        this->position = position;
        this->maxi = maxi;
        this->mini = mini;
        this->maxi2 = maxi2;
    }

    bool operator<(const State&other)const{

        return maxi > other.maxi;
    }

};

int prim(vector<vector<pair<int, int>>>&graph, int speedInit, int speedFinish, int init, int finish){

    priority_queue<State>q;
    set<tuple<int,int>>conj;
    tuple<int,int>aux;

    int i, speed, maxi, position, auxMaxi, auxSpeed, pre, maxi2, mini, auxMaxi2, auxMini2;
    
    for(i = 0; i<graph[init].size(); i++){

        q.push(State(init, graph[init][i].first, graph[init][i].second, 0, graph[init][i].first, graph[init][i].first));
        conj.insert(make_tuple(graph[init][i].second, 0));
    }

    while(!q.empty()){

        pre = q.top().pre;
        speed = q.top().speed;
        maxi = q.top().maxi;
        maxi2 = q.top().maxi2;
        mini = q.top().mini;
        position = q.top().position;

        q.pop();

        if(position == finish){

            return maxi;
        }

        for(i = 0; i<graph[position].size(); i++){

            auxMaxi = maxi;
            auxMini2 = mini;
            auxMaxi2 = maxi2;

            if(graph[position][i].first < mini || graph[position][i].first > maxi2){

                auxMini2 = graph[position][i].first;
                auxMini2 = min(mini, graph[position][i].first);
                auxMaxi2 = max(maxi2, graph[position][i].first);
                auxMaxi = max(auxMaxi, abs(mini - graph[position][i].first));
                auxMaxi = max(auxMaxi, abs(maxi2 - graph[position][i].first));
            }

            aux = make_tuple(graph[position][i].second, auxMaxi);

            auto it = conj.find(aux);

            if(it == conj.end() && graph[position][i].second != pre){

                conj.insert(aux);
                q.push(State(position, graph[position][i].first, graph[position][i].second, auxMaxi, auxMaxi2, auxMini2));
            }
        }
    }

    return -1;
}

int main(){

    int junctions, conections, i, junction1, junction2, speed, speedInit, speedFinish, queries, init, finish, aux, mini;

    while(scanf("%i %i", &junctions, &conections) != EOF){

        vector<vector<pair<int, int>>>graph(junctions);

        for(i = 0; i<conections; i++){

            scanf("%i %i %i", &junction1, &junction2, &speed);

            graph[junction1-1].push_back(make_pair(speed, junction2-1));
            graph[junction2-1].push_back(make_pair(speed, junction1-1));
        }

        scanf("%i %i", &speedInit, &speedFinish);
        scanf("%i", &queries);

        while(queries--){

            scanf("%i %i", &init, &finish);

            mini = prim(graph, speedInit, speedFinish, init-1, finish-1);

            printf("%i\n", mini+speedInit+speedFinish);
            
        }
    }


    return 0;
}
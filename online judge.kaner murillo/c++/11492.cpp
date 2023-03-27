//https://onlinejudge.org/external/114/11492.pdf
//11492

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

struct State{

    int coste = 0;
    string language = "";
    char pre;
    
    State(){}
    State(int coste, string language, char pre){

        this->coste = coste;
        this->language = language;
        this->pre = pre;
    }

    bool operator < (const State &other) const{

        return coste > other.coste;
    }
};

int dijkstra(map<string, vector<pair<string, string>>>&graph, map<string, int>&visits, string init, string finish){

    priority_queue<State>q;
    q.push(State(0, init, '?'));
    set<tuple<string, string, string>>conj;
    tuple<string, string, string> aux;

    int i, coste;
    char pre;

    while(!q.empty()){

        coste = q.top().coste;
        init = q.top().language;
        pre = q.top().pre;

        q.pop();

        if(init == finish){

            return coste;
        }

        for(i = 0; i<graph[init].size(); i++){

            if(pre == '?' || graph[init][i].second[0] != pre){
                
                aux = make_tuple(init, graph[init][i].first, graph[init][i].second);

                auto it = conj.find(aux);

                if(it == conj.end()){
                    
                    conj.insert(aux);
                    q.push(State(coste + graph[init][i].second.length(), graph[init][i].first, graph[init][i].second[0]));

                }
            }
        }
    }

    return -1;
}

int main(){

    int size, i, ans;
    string l1, l2, p, init, finish;

    while(scanf("%i", &size) && size){

        map<string, vector<pair<string, string>>>graph;
        map<string, int>visits;
        ans = -1;
        cin>>init>>finish;

        for(i = 0; i<size; i++){

            cin>>l1>>l2>>p;
            graph[l1].push_back(make_pair(l2, p));
            graph[l2].push_back(make_pair(l1, p));

            visits[l1] = INT_MAX;
            visits[l2] = INT_MAX;
        }   

        if(init != finish) ans = dijkstra(graph, visits, init, finish);

        if(ans != -1){

            printf("%i\n", ans);
        }

        else{

            printf("impossivel\n");
        }
    }

    return 0;
}



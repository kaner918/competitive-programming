//https://onlinejudge.org/external/102/10280.pdf
//10280

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_set>

using namespace std;

struct State{

    int mini, maxi, wine;

    State(){}
    State(int mini, int maxi, int wine){

        this->mini = mini;
        this->maxi = maxi;
        this->wine = wine;
    }

    bool operator<(const State&other)const{

        return wine > other.wine;
    }
};

int dijkstra(vector<pair<int, int>>&graph, int wine){

    int mini, maxi, auxMini, auxMaxi, i, ans = INT_MAX;

    priority_queue<State>q;
    q.push(State(0, 0, wine));
    unordered_set<int>conj;

    while(!q.empty()){

        mini  = q.top().mini;
        maxi = q.top().maxi;
        wine = q.top().wine;
        ans = min(ans, wine);

        /* cout<<"mini "<<mini<<" maxi "<<maxi<<" wine "<<wine<<endl; */

        q.pop();

        /* if(wine - mini+1 >= 0 && mini+1<=maxi){

            q.push(State(mini+1, maxi, wine-mini+1));
        } */

        /* if(wine + mini <= maxi && wine > 0){

            q.push(State(wine + mini, maxi, wine + mini));
        } */

        if(!conj.count(wine)){

            conj.insert(wine);

            for(i = 0; i<graph.size(); i++){

                auxMini = graph[i].first;
                auxMaxi = graph[i].second;

                /* if(wine - auxMini>=0){

                    q.push(State(auxMini + wine-auxMini, auxMaxi, wine-auxMini));
                } */

                if(wine - auxMaxi>=0){

                    q.push(State(auxMaxi, auxMaxi, wine-auxMaxi));
                }
                
            }
        }
    }

    return ans;
}   

int main(){

    int cases, wine, bottles, i, mini, maxi;

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){

        cin.ignore();
        cin.ignore();

        scanf("%i %i", &wine, &bottles);

        vector<pair<int, int>>graph;

        while(bottles--){

            scanf("%i %i", &mini, &maxi);
            graph.push_back(make_pair(mini, maxi));
        }

        printf("%i\n", dijkstra(graph, wine*1000));

        if(i<cases-1){
            printf("\n");
        }
    }

    return 0;
}
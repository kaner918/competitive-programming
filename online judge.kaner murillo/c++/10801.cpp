//10801
//https://onlinejudge.org/external/108/10801.pdf

//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
#include<sstream>
#include<set>
#include<string>

using namespace std;

void dijkstra(vector<int>&visits, vector<vector<tuple<int, int, int>>>&graph, set<tuple<int, int, int>>&conj){

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>>q;
    set<tuple<int, int, int>>::iterator it;

    visits[0] = 0;

    q.push(make_tuple(0, 0, -1));
    int i, floor, weight, auxFloor, elevator, auxElevator, calculate;
    string line;

    while(!q.empty()){

        floor = get<0>(q.top());
        weight = get<1>(q.top());
        elevator = get<2>(q.top());

        //printf("%i-> peso: %i -> elevator: %i\n", floor, weight, elevator);

        q.pop();

        /* if(weight == visits[floor]){ */

            for(i = 0; i<graph[floor].size(); i++){

                auxFloor = get<0>(graph[floor][i]);
                auxElevator = get<2>(graph[floor][i]);
                calculate = weight + get<1>(graph[floor][i]);

                if(elevator != -1 && auxElevator != elevator) calculate+=60;

                //sprintf("%i-> destino: %i -> peso: %i -> elevator: %i-%i\n", floor, auxFloor, calculate, auxElevator, elevator);
                for(it = conj.begin(); it!=conj.end() && (auxFloor != get<0>(*it) || auxElevator != get<2>(*it)); it++);

                if(calculate <= visits[auxFloor]){

                    visits[auxFloor] = calculate;
                    q.push(make_tuple(auxFloor, calculate, auxElevator));
                    conj.insert(make_tuple(auxFloor, calculate, auxElevator));
                }

                else if(it == conj.end()){

                    q.push(make_tuple(auxFloor, calculate, auxElevator));
                    conj.insert(make_tuple(auxFloor, calculate, auxElevator));

                }
            }
        /* } */
    }
}

int main(){

    int elevators, destiny, speed, pre, pos, i;
    string line;

    while(scanf("%i %i", &elevators, &destiny) != EOF){

        vector<vector<tuple<int, int, int>>>graph(100);
        vector<int>speeds(elevators);
        vector<int>visits(100, INT_MAX);

        for(i = 0; i<elevators; i++){

            scanf("%i", &speed);
            speeds[i] = speed;
        }

        cin.ignore();

        for(i = 0; i<elevators; i++){

            getline(cin, line);

            stringstream stk(line);
            stk>>pre;

            while(stk>>pos){

                //cout<<(pos-pre)*speeds[i]<<" "<<pre<<" "<<pos<<endl;

                graph[pre].push_back(make_tuple(pos, (pos-pre)*speeds[i], i));
                graph[pos].push_back(make_tuple(pre, (pos-pre)*speeds[i], i));
                pre = pos;
            }
        }

        set<tuple<int, int, int>>conj;

        dijkstra(visits, graph, conj);

        if(visits[destiny] != INT_MAX) printf("%i\n", visits[destiny]);
        else printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
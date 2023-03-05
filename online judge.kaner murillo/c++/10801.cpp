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

void dijkstra(vector<int>&visits, vector<vector<tuple<int, int, int>>>&graph, set<tuple<int, int, int, int>>&conj, int destiny){

    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>>q;
    set<tuple<int, int, int, int>>::iterator it;

    visits[0] = 0;

    q.push(make_tuple(0, 0, -1, 0));
    int i, floor, weight, auxFloor, elevator, auxElevator, calculate, coste, auxCoste;
    string line;

    while(!q.empty()){

        floor = get<0>(q.top());
        weight = get<1>(q.top());
        elevator = get<2>(q.top());
        coste = get<3>(q.top());

        //printf("%i-> peso: %i -> elevator: %i -> coste: %i\n", floor, weight, elevator, coste);
        //printf("adyacensias:\n");

        q.pop();

        for(i = 0; i<graph[floor].size(); i++){

            auxFloor = get<0>(graph[floor][i]);
            calculate = get<1>(graph[floor][i]);
            auxElevator = get<2>(graph[floor][i]);
            auxCoste = coste;

            if(elevator != auxElevator && elevator != -1) auxCoste++;

            if(auxFloor == destiny){

                if(weight+calculate+60*auxCoste < visits[auxFloor]) visits[auxFloor] = weight+calculate+60*auxCoste;
                conj.insert(make_tuple(auxFloor, weight + calculate+60*auxCoste, auxElevator, floor));
            }

            else{

                for(it = conj.begin(); it != conj.end() && (get<0>(*it) != auxFloor || get<2>(*it) != auxElevator || get<3>(*it) != floor); it++);

                if(it == conj.end()){

                    if(weight + calculate < visits[auxFloor]) visits[auxFloor] = weight + calculate;

                    //printf("%i-> peso: %i -> elevator: %i -> coste: %i\n", auxFloor, weight + calculate, auxElevator, auxCoste);

                    q.push(make_tuple(auxFloor, weight + calculate, auxElevator, auxCoste));
                    conj.insert(make_tuple(auxFloor, weight + calculate, auxElevator, floor));
                }

            }
        }

        //printf("end.\n");
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

        set<tuple<int, int, int, int>>conj;

        dijkstra(visits, graph, conj, destiny);

        if(visits[destiny] != INT_MAX) printf("%i\n", visits[destiny]);
        else printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
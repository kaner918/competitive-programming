//https://onlinejudge.org/external/102/10278.pdf
//10278

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<string>
#include<sstream>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>&graph, vector<int>vecStations, vector<int>visits, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q, int newStation){

    int ans = 0, coste, intersection, i;
    vecStations[newStation] = 1;
    visits[newStation] = 0;
    q.push(make_pair(0, newStation));

    while(!q.empty()){

        coste = q.top().first;
        intersection = q.top().second;
        q.pop();

        if(coste == visits[intersection]){

            for(i = 0; i<graph[intersection].size(); i++){
                
                if(coste + graph[intersection][i].second < visits[graph[intersection][i].first] && !vecStations[graph[intersection][i].first]){

                    visits[graph[intersection][i].first] = coste + graph[intersection][i].second;
                    q.push(make_pair(visits[graph[intersection][i].first], graph[intersection][i].first));

                }
            }
            
        }
    }

    for(i = 0; i<visits.size(); i++){

        ans = max(ans, visits[i]);
    }

    return ans;
}

int main(){

    int cases, stations, stations2, intersections, station, id1, id2, distance, i, low, ans, flag;
    string line;
    scanf("%i", &cases);
    cin.ignore();

    while(cases--){

        scanf("%i %i", &stations, &intersections);
        stations2 = stations;
        ans = 0;
        vector<int>vecStations(intersections, 0);
        vector<int>visits(intersections, INT_MAX);
        vector<vector<pair<int, int>>>graph(intersections);

        while(stations2--){

            scanf("%i", &station);
            vecStations[station-1] = 1;
        }

        cin.ignore();

        while(getline(cin, line) && line != ""){

            stringstream stk(line);

            stk>>id1>>id2>>distance;

            graph[id1-1].push_back(make_pair(id2-1, distance));
            graph[id2-1].push_back(make_pair(id1-1, distance));
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

        for(i = 0; i<vecStations.size(); i++){
            
            if(vecStations[i]){

                q.push(make_pair(0, i));
                visits[i] = 0;
                flag = i;
            }
        }

        low = dijkstra(graph, vecStations, visits, q, flag);

        for(i = 0; i<vecStations.size(); i++){
            
            if(!vecStations[i]){

                distance = dijkstra(graph, vecStations, visits, q, i);

                if(distance < low){
                    low = distance;
                    ans = i;
                }
            }
        }

        printf("%i\n", ans+1);

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}
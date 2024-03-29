//https://onlinejudge.org/external/116/11635.pdf
//11635

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<set>
#include<algorithm>
#include<climits>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>&graph, vector<int>&hotels, int finish, vector<int>&visits){

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>q;
    set<tuple<int, int, int, int>>conj;

    q.push(make_tuple(0, 0, 0));
    conj.insert(make_tuple(0, 0, 0, 0));
    tuple<int, int, int, int>aux;
    tuple<int, int, int, int>aux2;

    int city, time, coste, i;

    while(!q.empty()){

        coste = get<0>(q.top());
        time = get<1>(q.top());
        city = get<2>(q.top());

        q.pop();

        if(city == finish){

            return coste;
        }

        for(i = 0; i<graph[city].size(); i++){

            if(hotels[city]){

                aux = make_tuple(city, graph[city][i].second, graph[city][i].first, 1);

                auto it = conj.find(aux);

                if(it == conj.end()){

                    conj.insert(aux);
                    q.push(make_tuple(coste + 1, graph[city][i].second, graph[city][i].first));
                }
            }

            if(time + graph[city][i].second<=600){

                aux2 = make_tuple(city, time + graph[city][i].second, graph[city][i].first, 0);

                auto it = conj.find(aux2);

                if(it == conj.end() && time + graph[city][i].second < visits[graph[city][i].first]){

                    conj.insert(aux2);
                    visits[graph[city][i].first] = time + graph[city][i].second;
                    q.push(make_tuple(coste, time + graph[city][i].second, graph[city][i].first));
                }
            }
        }
    }

    return -1;
}

int main(){

    int citys, hotels, hotel, conections, a, b, coste;

    while(scanf("%i", &citys) && citys){

        scanf("%i", &hotels);
        vector<int>hotelCity(citys, 0);
        vector<int>visits(citys, INT_MAX);

        vector<vector<pair<int, int>>>graph(citys, vector<pair<int, int>>());

        while(hotels--){

            scanf("%i", &hotel);
            hotelCity[hotel-1] = 1;
        }

        scanf("%i", &conections);

        while(conections--){

            scanf("%i %i %i", &a, &b, &coste);

            if(coste <= 600){

                graph[a-1].push_back(make_pair(b-1, coste));
                graph[b-1].push_back(make_pair(a-1, coste));
            }
        }

        printf("%i\n", dijkstra(graph, hotelCity, citys-1, visits));
    }

    return 0;
}
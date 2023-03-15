//https://onlinejudge.org/external/10/1048.pdf
//1048
//10369 arbol de recubrimiento minimo. ->kruskal-prin-10 dias

#include<vector>
#include<queue>
#include<iostream>
#include<cstdio>
#include<string>
#include<climits>
#include<tuple>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

void dijkstra(long long int city, long long int finish, int index, map<long long int, long long int>&visits, map<long long int, vector<tuple<long long int, int, int, bool>>>&graph, vector<long long int>&order, set<tuple<int, long long int, int>>&conj, vector<long long int>&res){
    
    priority_queue<tuple<int, long long int, int, vector<long long int>, int>, vector<tuple<int, long long int, int, vector<long long int>, int>>, greater<tuple<int, long long int, int, vector<long long int>, int>>>q;
    q.push(make_tuple(0, city, -1, vector<long long int>(), 1));
    vector<long long int>aux;
    vector<long long int>aux2;
    tuple<int, long long int, int>auxTuple;

    int i, coste, auxCoste, tique, auxTique, auxIndex;
    long long int auxCity;
    bool flag, fini = true;

    while(!q.empty()){

        coste = get<0>(q.top());
        city = get<1>(q.top());
        tique = get<2>(q.top());
        aux = get<3>(q.top());
        index = get<4>(q.top());

        //cout<<"city: "<<city<<" tique "<< tique<<" coste "<<coste<<" index "<<index<<endl;

        q.pop();   
        
        if(city == finish && coste < visits[finish] && order[index-1] == city && index == order.size()) visits[finish] = coste, res = aux, fini = false;
        
        //else{

            //cout<<"gou"<<endl<<endl;

            for(i = 0; i<graph[city].size(); i++){

                auxTique = get<2>(graph[city][i]);

                if((get<3>(graph[city][i])) || (tique == auxTique && !get<3>(graph[city][i]))){

                    auxCity = get<0>(graph[city][i]);
                    auxCoste = coste;
                    aux2 = aux;
                    auxIndex = index;
                    flag = false;

                    if(tique != auxTique) auxCoste+= get<1>(graph[city][i]), aux2.push_back(auxTique+1);
                    if(order[index] == auxCity) auxIndex++;

                    //if((auxCoste < visits[auxCity]) || !order[auxCity]){

                    auxTuple = make_tuple(auxIndex, auxCity, auxTique);

                    auto it = conj.find(auxTuple);
                    //for(it = conj.begin(); it!= conj.end() && (get<0>(*it) != auxIndex || get<1>(*it) != auxCity || get<2>(*it) != tique || get<3>(*it) != auxTique); it++); // implementar el estado del tiquete anterior

                    if(it == conj.end()){

                        //cout<<"aux_city: "<<auxCity<<" tique "<< auxTique<<" coste "<<auxCoste<<" index "<<auxIndex-1<<endl;

                        q.push(make_tuple(auxCoste, auxCity, auxTique, aux2, auxIndex));
                        conj.insert(auxTuple);
                        
                    }
                }
            }
            //}

            //cout<<endl<<endl;

        //}
    }
    
}


int main(){

    int offers, coste, sizeOffers, cases, offer, i, counter = 0, counter2, index;
    long long int city, pre, pos, first;

    while(scanf("%i", &offers) && offers){

        counter++;
        counter2 = 1;
        map<long long int, vector<tuple<long long int, int, int, bool>>> graph; 

        for(i = 0; i<offers; i++){

            scanf("%i %i %lld", &coste, &sizeOffers, &pre);
            sizeOffers--;
            bool flag = true;
            
            while(sizeOffers--){

                scanf("%lld", &pos);
                
                graph[pre].push_back(make_tuple(pos, coste, i, flag));
                pre = pos;
                flag = false;
            }
        }

        scanf("%i", &cases);

        while(cases--){

            map<long long int, long long int>visits;
            index = 0;
            vector<long long int>order;
            set<tuple<int, long long int, int>>conj;
            scanf("%i", &sizeOffers);
            scanf("%lld", &city);
            first = city;
            order.push_back(city);
            visits[city] = INT_MAX;
            sizeOffers--;

            while(sizeOffers--){

                scanf("%lld", &city);
                order.push_back(city);
                visits[city] = INT_MAX;
            }

            vector<long long int>res;
            dijkstra(first, city, 0, visits, graph, order, conj, res);
            printf("Case %i, Trip %i: Cost = %lld\n  Tickets used:", counter, counter2, visits[city]);
            
            for(i = 0; i<res.size(); i++){

                printf(" %lld", res[i]);
            }

            printf("\n");

            counter2++;
        }
    }

    return 0;
}
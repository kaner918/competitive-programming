//https://onlinejudge.org/external/10/1048.pdf
//1048

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

void dijkstra(int city, int finish, int index, map<int, int>&visits, map<int, vector<tuple<int, int, int, bool>>>&graph, vector<int>&order, set<tuple<int, int, int, int>>&conj, vector<int>&res){
    
    if(city != finish) visits[city] = 0;
    priority_queue<tuple<int, int, int, vector<int>, int>, vector<tuple<int, int, int, vector<int>, int>>, greater<tuple<int, int, int, vector<int>, int>>>q;
    q.push(make_tuple(0, city, -1, vector<int>(), 1));
    vector<int>aux;
    vector<int>aux2;
    tuple<int, int, int, int>auxTuple;

    int i, coste, auxCity, auxCoste, tique, auxTique, auxIndex;
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

                if((tique == -1 && get<3>(graph[city][i])) || (tique != -1)){

                    auxCity = get<0>(graph[city][i]);
                    auxCoste = coste;
                    auxTique = get<2>(graph[city][i]);
                    aux2 = aux;
                    auxIndex = index;
                    flag = false;

                    if(tique != auxTique) auxCoste+= get<1>(graph[city][i]), aux2.push_back(auxTique+1);
                    if(order[index] == auxCity) auxIndex++;

                    //if((auxCoste < visits[auxCity]) || !order[auxCity]){

                    auxTuple = make_tuple(auxIndex, city, tique, auxTique);

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

    int offers, coste, sizeOffers, cases, first, offer, city, i, pre, pos, counter = 0, counter2, index;

    while(scanf("%i", &offers) && offers){

        counter++;
        counter2 = 1;
        map<int, vector<tuple<int, int, int, bool>>> graph; 

        for(i = 0; i<offers; i++){

            scanf("%i %i %i", &coste, &sizeOffers, &pre);
            sizeOffers--;
            bool flag = true;
            
            while(sizeOffers--){

                scanf("%i", &pos);
                
                graph[pre].push_back(make_tuple(pos, coste, i, flag));
                pre = pos;
                flag = false;
            }
        }

        scanf("%i", &cases);

        while(cases--){

            map<int, int>visits;
            index = 0;
            vector<int>order;
            set<tuple<int, int, int, int>>conj;
            scanf("%i", &sizeOffers);
            scanf("%i", &city);
            first = city;
            order.push_back(city);
            visits[city] = INT_MAX;
            sizeOffers--;

            while(sizeOffers--){

                scanf("%i", &city);
                order.push_back(city);
                visits[city] = INT_MAX;
            }

            vector<int>res;
            dijkstra(first, city, 0, visits, graph, order, conj, res);
            printf("Case %i, Trip %i: Cost = %i\n  Tickets used:", counter, counter2, visits[city]);
            
            for(i = 0; i<res.size(); i++){

                printf(" %i", res[i]);
            }

            printf("\n");

            counter2++;
        }
    }

    return 0;
}
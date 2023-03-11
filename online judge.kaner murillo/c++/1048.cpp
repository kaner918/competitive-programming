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

using namespace std;

void dijkstra(int city, int finish, int index, vector<int>&visits, vector<vector<tuple<int, int, int>>>&graph, map<int, int>&order, set<tuple<int, int, int, int>>&conj, vector<int>&res){

    visits[city] = 0;
    priority_queue<tuple<int, int, int, vector<int>, int>, vector<tuple<int, int, int, vector<int>, int>>, greater<tuple<int, int, int, vector<int>, int>>>q;
    q.push(make_tuple(0, city, -1, vector<int>(), 1));
    vector<int>aux;
    vector<int>aux2;
    set<tuple<int, int, int, int>>::iterator it;

    int i, coste, auxCity, auxCoste, tique, auxTique, auxIndex;
    bool flag;

    while(!q.empty()){

        coste = get<0>(q.top());
        city = get<1>(q.top());
        tique = get<2>(q.top());
        aux = get<3>(q.top());
        index = get<4>(q.top());

        //cout<<"city: "<<city<<" tique "<< tique<<" coste "<<coste<<" index "<<index<<endl;

        q.pop();   

        if(city == finish && coste < visits[finish] && index-1 == order[city]) visits[finish] = coste, res = aux;

        //cout<<"gou"<<endl<<endl;

        for(i = 0; i<graph[city].size(); i++){

            auxCity = get<0>(graph[city][i]);
            auxCoste = coste;
            auxTique = get<2>(graph[city][i]);
            aux2 = aux;
            auxIndex = index;
            flag = false;

            if(tique != auxTique) auxCoste+= get<1>(graph[city][i]), flag = true;
            if(order[auxCity] == index) auxIndex++;

            for(it = conj.begin(); it!= conj.end() && (get<0>(*it) != city || get<1>(*it) != auxCity || get<2>(*it) != tique || get<3>(*it) != auxTique); it++); // implementar el estado del tiquete anterior

            if(it == conj.end()){
                
                if(flag){

                    aux2.push_back(auxTique+1);
                }   

                //cout<<"aux_city: "<<auxCity<<" tique "<< auxTique<<" coste "<<auxCoste<<" index "<<auxIndex<<endl;

                q.push(make_tuple(auxCoste, auxCity, auxTique, aux2, auxIndex));
                conj.insert(make_tuple(city, auxCity, tique, auxTique));
                
            }

        }

        //cout<<endl<<endl;
    }
    
}


int main(){

    int offers, coste, sizeOffers, cases, first, offer, city, i, pre, pos, counter = 0, counter2, index;

    while(scanf("%i", &offers) && offers){

        counter++;
        counter2 = 1;
        vector<vector<tuple<int, int, int>>> graph(10, vector<tuple<int, int, int>>());
        vector<int>visits(10, INT_MAX);  
        
        for(i = 0; i<offers; i++){

            scanf("%i %i %i", &coste, &sizeOffers, &pre);
            sizeOffers--;

            while(sizeOffers--){

                scanf("%i", &pos);
                
                graph[pre].push_back(make_tuple(pos, coste, i));
                pre = pos;
            }
        }

        scanf("%i", &cases);

        while(cases--){

            index = 0;
            map<int, int>order;
            set<tuple<int, int, int, int>>conj;
            scanf("%i", &sizeOffers);
            scanf("%i", &city);
            first = city;
            order[city] = index++;
            sizeOffers--;

            while(sizeOffers--){
                
                scanf("%i", &city);
                order[city] = index++;
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
//https://onlinejudge.org/external/101/10187.pdf
//10187

#include<map>
#include<queue>
#include<vector>
#include<set>
#include<cstdio>
#include<iostream>
#include<string>
#include<climits>
#include<tuple>
#include<algorithm>

using namespace std;

void dijkstra(map<string, vector<tuple<string, int, int>>>&graph, map<string, int>&visits, set<tuple<string, string, int, int, int>>&conj, string init, string finish){

    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<tuple<int, int, string>>>q;

    q.push(make_tuple(0, 18, init));
    int blood, auxBlood, time, i, auxTime1, auxTime2;
    string auxCity;
    tuple<string, string, int, int, int>auxTuple;
    bool coste, flag = false;

    while(!q.empty() && !flag){

        blood = get<0>(q.top());
        time = get<1>(q.top());    
        init = get<2>(q.top());

        //cout<<init<<" citys ad:"<<endl;

        q.pop();

        if(init == finish && blood != -1 && blood < visits[finish]) visits[finish] = blood, flag = true;

        if(!flag){

            for(i = 0; i<graph[init].size(); i++){

                auxCity = get<0>(graph[init][i]);
                auxTime1 = get<1>(graph[init][i]);
                auxTime2 = get<2>(graph[init][i]);
                auxBlood = blood;

                if((time<=24 && time>=18) && (auxTime1<=24 && auxTime1 >= 18) && time>auxTime1) auxBlood++, coste = true;

                else if((time<=6 && time>=1) && (auxTime1<=6 && auxTime1 >= 1) && time>auxTime1) auxBlood++, coste = true;

                else if((time<=6 && time>=1) && (auxTime1<=24 && auxTime1 >= 18)) auxBlood++, coste = true;

                //else if((time<=24 && time>=18) && (auxTime1<=6 && auxTime1 >= 1)) auxBlood++;

                auxTuple = make_tuple(auxCity, init, time, auxTime1, auxTime2);
                
                auto it = conj.find(auxTuple);

                if(it == conj.end()){

                    //cout<<auxCity<<" init "<<time<<" finish "<<auxTime2<<" coste "<<coste<<endl;

                    q.push(make_tuple(auxBlood, auxTime2, auxCity));
                    conj.insert(auxTuple);
                }
            }

            //cout<<endl<<endl;
        }
    }
}


int main(){

    int cases, i, travels, time1, time2, time3;
    string city1, city2;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){
        
        scanf("%i", &travels);
        map<string, vector<tuple<string, int, int>>>graph;
        map<string, int>visits;

        while(travels--){

            cin>>city1>>city2>>time1>>time2;
            
            visits[city1] = INT_MAX;
            visits[city2] = INT_MAX;

            time3 = time1 + time2;

            if(time3>24) time3-=24; //actualizamos la hora cuando sea un nuevo dia

            if((time1>17 || time1 < 6) && (time3>17 || time3<7) && time2<=12){

                graph[city1].push_back(make_tuple(city2, time1, time3));
            
            }
        }

        cin>>city1>>city2;
        
        visits[city1] = INT_MAX;
        visits[city2] = INT_MAX;

        set<tuple<string, string, int, int, int>>conj;

        //cout<<endl;
        dijkstra(graph, visits, conj, city1, city2);

        printf("Test Case %i.\n", i);

        if(visits[city2] == INT_MAX) printf("There is no route Vladimir can take.\n");
        else printf("Vladimir needs %i litre(s) of blood.\n", visits[city2]);
    }

    return 0;
}
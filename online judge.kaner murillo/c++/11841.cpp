//https://onlinejudge.org/external/118/11841.pdf
//11841

#include<cstdio>
#include<iostream>
#include<map>
#include<tuple>
#include<vector>

using namespace std;

void dfs(tuple<int, int, int>node, map<tuple<int, int, int>, int>&graph){

    map<tuple<int, int, int>, int>::iterator it;
    graph[node] = 0; 

    tuple<int, int, int> aux1 = make_tuple(get<0>(node)+1, get<1>(node), get<2>(node)-1);
    tuple<int, int, int> aux2 = make_tuple(get<0>(node), get<1>(node)+1, get<2>(node)-1);

    if(get<2>(node) > 0){

        for(it = graph.begin(); it!=graph.end() && (get<0>(it->first) != get<0>(aux1) || get<1>(it->first) != get<1>(aux1) || get<2>(it->first) != get<2>(aux1)); it++);

        if(it==graph.end()){

            dfs(aux1, graph);
        }

        for(it = graph.begin(); it!=graph.end() && (get<0>(it->first) != get<0>(aux2) || get<1>(it->first) != get<1>(aux2) || get<2>(it->first) != get<2>(aux2)); it++);

        if(it==graph.end()){

            dfs(aux2, graph);
        }
    }
}

int main(){

    int size, consults, n, m, x, y, z;
    tuple<int, int, int> auxTuple = make_tuple(0, 0, 0);
    tuple<int, int, int> auxTuple2;
    tuple<int, int, int> auxTuple3;
    bool ans;

    while(scanf("%i %i", &size, &consults) && (size != 0 || consults != 0)){

        map<tuple<int, int, int>, int>graph;
        vector<tuple<int, int, int>>vecConsult;

        dfs(make_tuple(0, 0, size), graph);
        ans = false;
        map<tuple<int, int, int>, int>::iterator it;

        for(n = 0; n<consults; n++){

            scanf("%i %i %i", &x, &y, &z);

            get<0>(auxTuple) = x;
            get<1>(auxTuple) = y;
            get<2>(auxTuple) = z;

            vecConsult.push_back(auxTuple);
            graph[auxTuple] = 1;

        }

        /* for(it = graph.begin(); it!=graph.end(); it++){

            cout<<get<0>(it->first)<<" "<<get<1>(it->first)<<" "<<get<2>(it->first)<<" "<<graph[it->first]<<endl;
        } */

        for(n = 0; n<vecConsult.size() && ans == false; n++){
            
            auxTuple = make_tuple(get<0>(vecConsult[n])-1, get<1>(vecConsult[n]), get<2>(vecConsult[n])+1); 
            auxTuple2 = make_tuple(get<0>(vecConsult[n]), get<1>(vecConsult[n])-1, get<2>(vecConsult[n])+1); 
            auxTuple3 = make_tuple(get<0>(vecConsult[n]), get<1>(vecConsult[n])+1, get<2>(vecConsult[n])-1); 

            if((get<0>(auxTuple) > -1 && graph[auxTuple] == 1) && (get<1>(auxTuple2) > -1 && graph[auxTuple2] == 1) && (get<2>(auxTuple3) > -1 && graph[auxTuple3] == 1)){

                ans = true;
            }
        }

        if(ans){

            printf("Benny\n");
        }

        else{

            printf("Willy\n");
        }
    }

    return 0;
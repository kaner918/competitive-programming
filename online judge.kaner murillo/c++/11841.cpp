//https://onlinejudge.org/external/118/11841.pdf
//11841

#include<cstdio>
#include<iostream>
#include<set>
#include<tuple>
#include<vector>

using namespace std;

bool ans1, ans2, ans3;

bool compare(tuple<int, int, int>node, set<tuple<int, int, int>>&graph, set<tuple<int, int, int>>&visits){//verifico si ya visite el nodo, y si se encuentra dentro de los movimientos del color negro

    set<tuple<int, int, int>>::iterator it;

    for(it = visits.begin(); it!=visits.end() && (get<0>(*it) != get<0>(node) || get<1>(*it)  != get<1>(node) || get<2>(*it) != get<2>(node)); it++);

        if(it==visits.end()){

            for(it = graph.begin(); it!=graph.end() && (get<0>(*it)  != get<0>(node) || get<1>(*it)  != get<1>(node) || get<2>(*it)  != get<2>(node)); it++);

            if(it != graph.end()){

                return true;

            }
        }

    return false;
}

//separador
void dfs(tuple<int, int, int>node, set<tuple<int, int, int>>&graph, set<tuple<int, int, int>>&visits, int size){

    
    visits.insert(node);

    if(get<0>(node) == 0){

        ans1 = true;
    }

    if(get<1>(node) == 0){

        ans2 = true;
    }

    if(get<2>(node) == 0){

        ans3 = true;
    }
    
    tuple<int, int, int> aux1 = make_tuple(get<0>(node)+1, get<1>(node), get<2>(node)-1);//abajo izquierda
    tuple<int, int, int> aux2 = make_tuple(get<0>(node), get<1>(node)+1, get<2>(node)-1);//abajo izquierda
    tuple<int, int, int> aux3 = make_tuple(get<0>(node)-1, get<1>(node), get<2>(node)+1);//arriba izquierda
    tuple<int, int, int> aux4 = make_tuple(get<0>(node), get<1>(node)-1, get<2>(node)+1);//arriba derecha
    tuple<int, int, int> aux5 = make_tuple(get<0>(node)-1, get<1>(node)+1, get<2>(node));//mismo level
    tuple<int, int, int> aux6 = make_tuple(get<0>(node)+1, get<1>(node)-1, get<2>(node));//mismo level

    if(get<0>(node)>=0 && get<1>(node)>=0 && get<2>(node)>=0 && (get<0>(node) + get<1>(node) + get<2>(node)) == size){

        if(compare(aux1, graph, visits) && (!ans1 || !ans2 || !ans3)){

            dfs(aux1, graph, visits, size);
        }

        if(compare(aux2, graph, visits)&& (!ans1 || !ans2 || !ans3)){

            dfs(aux2, graph, visits, size);
        }

        if(compare(aux3, graph, visits)&& (!ans1 || !ans2 || !ans3)){

            dfs(aux3, graph, visits, size);
        }

        if(compare(aux4, graph, visits)&& (!ans1 || !ans2 || !ans3)){

            dfs(aux4, graph, visits, size);
        }

        if(compare(aux5, graph, visits)&& (!ans1 || !ans2 || !ans3)){

            dfs(aux5, graph, visits, size);
        }

        if(compare(aux6, graph, visits)&& (!ans1 || !ans2 || !ans3)){

            dfs(aux6, graph, visits, size);
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

        set<tuple<int, int, int>>graph;
        vector<tuple<int, int, int>>vecConsult;
        ans = false;
        set<tuple<int, int, int>>::iterator it;

        for(n = 0; n<consults; n++){

            scanf("%i %i %i", &x, &y, &z);

            get<0>(auxTuple) = x;
            get<1>(auxTuple) = y;
            get<2>(auxTuple) = z;

            vecConsult.push_back(auxTuple);
            graph.insert(auxTuple);

        }

        for(n = 0; n<vecConsult.size() && ans == false; n++){
            
            ans1 = false;
            ans2 = false;
            ans3 = false;
            set<tuple<int, int, int>>visits;

            dfs(vecConsult[n], graph, visits, size);

            if(ans1 && ans2 && ans3){

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
}
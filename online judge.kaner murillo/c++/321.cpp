//https://onlinejudge.org/external/3/321.pdf
//321

#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<tuple>

using namespace std;

struct Lights{

    vector<int>lights;
    vector<int>conections;
    int counter = 0;

};

int bfs(int init, vector<Lights>&graph, set<tuple<int, vector<int>>>&visits){

    queue<tuple<int, vector<int>>>q;
    set<tuple<int, vector<int>>>::iterator it;
    int i, n;
    vector<int>auxVec(graph.size(), -1);
    vector<int>auxVecFinish(graph.size(), -1);
    tuple<int, vector<int>>auxTuple = make_tuple(init, auxVec);
    auxVec[0] = 1;
    auxVecFinish[graph.size()-1] = 1;
    q.push(auxTuple);
    visits.insert(auxTuple);
    
    while(!q.empty()){

        auxTuple = q.front();
        cout<<get<0>(auxTuple)<<":"<<endl;

        for(n = 0; n)

        if(get<0>(auxTuple) == graph.size()-1 && get<1>(auxTuple) == auxVecFinish){

            return 1;
        }

        q.pop();

        for(n = 0; n<graph[get<0>(auxTuple)].lights.size(); n++){

            auxVec = get<1>(auxTuple);
            auxVec[graph[get<0>(auxTuple)].lights[n]]*=-1;

            for(it = visits.begin(); it!=visits.end() && (get<0>(*it) != get<0>(auxTuple) || (get<1>(*it) != auxVec)); it++);

            if(it==visits.end()){

                q.push(make_tuple(get<0>(auxTuple), auxVec));
                visits.insert(make_tuple(get<0>(auxTuple), auxVec));
            }
        }

        for(n = 0; n<graph[get<0>(auxTuple)].conections.size(); n++){

            for(it = visits.begin(); it!=visits.end() && (get<0>(*it) != graph[get<0>(auxTuple)].conections[n] || (get<1>(*it) != get<1>(auxTuple))); it++);
            
            if(it==visits.end() && get<1>(auxTuple)[graph[get<0>(auxTuple)].conections[n]] == 1){

                q.push(make_tuple(graph[get<0>(auxTuple)].conections[n], get<1>(auxTuple)));
                visits.insert(make_tuple(graph[get<0>(auxTuple)].conections[n], get<1>(auxTuple)));
            }
        }
    }

    return -1;

}

int main(){

    int doors, paths, light, dor1, dor2, i, n;

    while(scanf("%i %i %i", &doors, &paths, &light) && (doors != 0 || paths != 0 || light != 0)){

        vector<Lights>graph(doors);
        set<tuple<int, vector<int>>>visits;

        for(i = 0; i<paths; i++){

            scanf("%i %i", &dor1, &dor2);

            graph[dor1-1].conections.push_back(dor2-1);
            graph[dor2-1].conections.push_back(dor1-1);

        }

        for(i = 0; i<light; i++){

            scanf("%i %i", &dor1, &dor2);

            graph[dor1-1].lights.push_back(dor2-1);
        }

        bfs(0, graph, visits);

       /*  for(i = 0; i<graph.size(); i++){

            printf("%i conection: ", i+1);

            for(n = 0; n<graph[i].conections.size(); n++){

                printf("%i ", graph[i].conections[n]+1);
            }

            printf("\n");

            printf("%i lights: ", i+1);

            for(n = 0; n<graph[i].lights.size(); n++){

                printf("%i ", graph[i].lights[n]+1);
            }

            printf("\n");
        } */
        cin.ignore();
    }

    return 0;
}
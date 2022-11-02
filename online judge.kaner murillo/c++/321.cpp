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
    tuple<int, vector<int>>auxTuple = make_tuple(init, auxVec);
    auxVec[0] = 1;
    q.push(auxTuple);
    visits.insert(auxTuple);
    
    while(!q.empty()){

        auxTuple = q.front();
        cout<<get<0>(auxTuple)<<endl;
        auxVec = get<1>(auxTuple);
        
        q.pop();

        for(n = 0; n<graph[get<0>(auxTuple)].lights.size(); n++){

            auxVec[graph[get<0>(auxTuple)].lights[n]]*=-1;

            for(i = 0; i<graph[get<0>(auxTuple)].conections.size(); i++){
                
                for(it = visits.begin(); it!=visits.end() && (graph[get<0>(auxTuple)].conections[i] != get<0>(*it) || auxVec != get<1>(*it)); it++);
                if(it == visits.end() && auxVec[graph[get<0>(auxTuple)].conections[i]] == 1){

                    q.push(make_tuple(graph[get<0>(auxTuple)].conections[i], auxVec));
                    visits.insert(make_tuple(graph[get<0>(auxTuple)].conections[i], auxVec));
                }
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
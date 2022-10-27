//https://onlinejudge.org/external/3/321.pdf
//321

#include<cstdio>
#include<iostream>
#include<vector>
#include<set>

using namespace std;
struct Lights{

    vector<int>lights;
    vector<int>conections;
};

int main(){

    int doors, paths, light, dor1, dor2, i, n;

    while(scanf("%i %i %i", &doors, &paths, &light) && (doors != 0 || paths != 0 || light != 0)){

        vector<Lights>graph(doors);

        for(i = 0; i<paths; i++){

            scanf("%i %i", &dor1, &dor2);

            graph[dor1-1].conections.push_back(dor2-1);
            graph[dor2-1].conections.push_back(dor1-1);

        }

        for(i = 0; i<light; i++){

            scanf("%i %i", &dor1, &dor2);

            graph[dor1-1].lights.push_back(dor2-1);
        }

        for(i = 0; i<graph.size(); i++){

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
        }
        cin.ignore();
    }

    return 0;
}
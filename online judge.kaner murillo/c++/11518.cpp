//https://onlinejudge.org/external/115/11518.pdf
//11518

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void dfs(int v, vector<vector<int>>&grafo, vector<bool>&visits){

    visits[v] = true;

    for(int u = 0; u<grafo[v].size(); u++){

        if(visits[grafo[v][u]] == false){

            dfs(grafo[v][u], grafo, visits);
        }
    }
}

int main(){

    int cases, nodes, conections, consults, consult, counter, x, y, i;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i %i", &nodes, &conections, &consults);
        vector<vector<int>>grafo(nodes);
        vector<bool>visits;
        counter = 0;

        for(i = 0; i<nodes; i++){

            visits.push_back(false);
        }
            
        while(conections--){

            scanf("%i %i", &x, &y);
            grafo[x-1].push_back(y-1);
        }

        while(consults--){

            scanf("%i", &consult);
            
            dfs(consult-1, grafo, visits);
        }
        
        for(i = 0; i<visits.size(); i++){

            if(visits[i] == true){
                counter++;
            }
        }
        printf("%i\n", counter);
    }

    return 0;

}
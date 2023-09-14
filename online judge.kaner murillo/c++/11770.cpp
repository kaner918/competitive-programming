//https://onlinejudge.org/external/117/11770.pdf
//11770

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int indexC, indexTps;
vector<int>visits(10001);
vector<int>indexComponent(10001);
vector<int>tps(10001);

int main(){

    int cases, i, j, counter = 1, nodes, conections, a, b;

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){

        scanf("%i %i", &nodes, &conections);
        vector<vector<int>>graph(nodes);
        vector<vector<int>>graphT(nodes);

        for(j = 0; j<nodes; j++){
            visits[j] = 0;
            indexComponent[j] = -1;
            tps[j] = 0;
        }

        for(j = 0; j<conections; j++){
            scanf("%i %i", &a, &b);
            a--, b--;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        printf("%i\n", counter++);
    }
    
    return 0;
}
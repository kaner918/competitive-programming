//https://onlinejudge.org/external/2/208.pdf
//208

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int counter2;
//vector<vector<int>>res;

void solved(map<int, vector<int>>&graph, map<int, int>&visits, int index, int find, vector<int>&combi){

    combi.push_back(index);

    if(index == find){

        counter2++;
        int i, aux = index;
        printf("%i", combi[combi.size()-1]);
        for(i = combi.size()-2; i>-1; i--){
            printf(" %i", combi[i]);
        }
        printf("\n");
    }

    else{

        int i;

        for(i = 0; i<graph[index].size(); i++){
            if(!visits[graph[index][i]]){
                visits[graph[index][i]] = 1;
                solved(graph, visits, graph[index][i], find, combi);
                visits[graph[index][i]] = 0;
            }
        }
    }

    combi.pop_back();
}


int main(){

    int counter = 1, streetCorner, a, b, i, n;

    while(scanf("%i", &streetCorner) != EOF){

        map<int, vector<int>>graph;
        map<int, int>visits;
        vector<pair<int, int>>conections;
        vector<int>combi;
        //res.clear();
        counter2 = 0;

        while(scanf("%i %i", &a, &b) && (a || b)){
            visits[a] = 0;
            visits[b] = 0;
            conections.push_back({min(a, b), max(a, b)});
        }        

        sort(conections.begin(), conections.end());
        for(i = 0; i<conections.size(); i++){
            graph[conections[i].first].push_back(conections[i].second);
            graph[conections[i].second].push_back(conections[i].first);
        }

        visits[streetCorner] = 1;
        printf("CASE %i:\n", counter++);
        solved(graph, visits, streetCorner, 1, combi);
        //sort(res.begin(), res.end());

        /* for(i = 0; i<res.size(); i++){

            for(n = 0; n<res[i].size()-1; n++){

                printf("%i ", res[i][n]);
            }

            printf("%i\n", streetCorner);
        } */

        printf("There are %i routes from the firestation to streetcorner %i.\n", counter2, streetCorner);
    }   
    return 0;
}
//https://onlinejudge.org/external/2/208.pdf
//208

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int counter2;
vector<vector<int>>res;

void solved(map<int, vector<int>>&graph, map<int, int>&visits, int index, int find){


    if(index == find){

        counter2++;
        int aux = index;
        vector<int>cad;

        while(aux != -1){

            cad.push_back(aux);
            aux = visits[aux];
        }

        res.push_back(cad);
    }

    else{

        int i;

        for(i = 0; i<graph[index].size(); i++){

            if(!visits[graph[index][i]]){

                visits[graph[index][i]] = index;
                solved(graph, visits, graph[index][i], find);
                visits[graph[index][i]] = 0;
            }
        }
    }

}


int main(){

    int counter = 1, streetCorner, a, b, i, n;

    while(scanf("%i", &streetCorner) != EOF){

        map<int, vector<int>>graph;
        map<int, int>visits;
        res.clear();
        counter2 = 0;

        while(scanf("%i %i", &a, &b) && (a || b)){

            visits[a] = 0;
            visits[b] = 0;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }        

        visits[streetCorner] = -1;
        printf("CASE %i:\n", counter++);
        solved(graph, visits, streetCorner, 1);
        sort(res.begin(), res.end());

        for(i = 0; i<res.size(); i++){

            for(n = 0; n<res[i].size()-1; n++){

                printf("%i ", res[i][n]);
            }

            printf("%i\n", streetCorner);
        }

        printf("There are %i routes from the firestation to streetcorner %i.\n", counter2, streetCorner);
    }   
    return 0;
}
//https://onlinejudge.org/external/2/208.pdf
//208

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<deque>

using namespace std;
int counter2;
vector<deque<int>>res;

void solved(map<int, vector<int>>&graph, map<int, int>&visits, int index, int find, deque<int>&combi){

    if(index == find){
        counter2++;
        res.push_back(combi);
    }

    else{

        int i;

        for(i = 0; i<graph[index].size(); i++){
            if(!visits[graph[index][i]]){
                visits[graph[index][i]] = 1;
                combi.push_front(graph[index][i]);
                solved(graph, visits, graph[index][i], find, combi);
                visits[graph[index][i]] = 0;
                combi.pop_front();
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
        deque<int>combi = {streetCorner}; 
        counter2 = 0;

        while(scanf("%i %i", &a, &b) && (a || b)){

            visits[a] = 0;
            visits[b] = 0;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }        

        visits[streetCorner] = 1;
        printf("CASE %i:\n", counter++);
        solved(graph, visits, streetCorner, 1, combi);

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
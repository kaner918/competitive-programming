//https://onlinejudge.org/external/124/12442.pdf
//12442

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int counter;

void dfs(int v, vector<vector<int>>&grafo, vector<bool>&visits, vector<bool>visits2){

    visits[v] = true;
    visits2[v] = true;

    counter++;  

    for(int u = 0; u<grafo[v].size(); u++){

        if(visits2[grafo[v][u]] == false){

            dfs(grafo[v][u], grafo, visits, visits2); 
        }
    }
}

int main(){

    int cases, martians, higer, martian, i, n, m, u, v;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i", &martians);
        vector<vector<int>> grafo(martians);
        vector<bool>visits;
        vector<bool>visits2;

        higer = 0;
        martian = 0;

        for(n = 0; n<martians; n++){

            scanf("%i %i", &u, &v);
            grafo[u-1].push_back(v-1);
            visits.push_back(false);
            visits2.push_back(false);
        }

        for(n = 0; n<martians; n++){
            
            if(visits[n] == false){

                counter = 0;
                
                dfs(n, grafo, visits, visits2);

                if(counter > higer){

                    higer = counter;
                    martian = n;
                }

                else if(counter == higer && n<martian){

                    martian  = n;
                }

            }
        }

        printf("Case %i: %i\n", i, martian+1);
    }

    return 0;
}
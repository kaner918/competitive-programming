//https://onlinejudge.org/external/3/336.pdf
//336

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;
int counter2 = 0;

void dfs(int v, map<int, vector<int>>&grafo, map<int, bool>&visits, int ttl){

    if(ttl == 0){

        visits[v] = true;
    }

    else{

        int i;
        ttl-=1;
        visits[v] = true;
        //cout<<v<<endl;
        
        for(i = 0; i<grafo[v].size(); i++){

            if (!visits[grafo[v][i]]){
                
                dfs(grafo[v][i], grafo, visits, ttl);

            }
        }
    }
}

int main(){

    int size, nodoA, nodoB, i, count;

    while(scanf("%i", &size) && size != 0){

        map<int, vector<int>> grafo;
        map<int, bool> visits;
        map<int, bool>::iterator it;

        for(i = 0; i<size; i++){

            scanf("%i %i", &nodoA, &nodoB);

            grafo[nodoA].push_back(nodoB);
            grafo[nodoB].push_back(nodoA);

            visits[nodoA] = false;
            visits[nodoB] = false;

            /*

            map<int, vector<int>>::iterator it;

            for(it = grafo.begin(); it != grafo.end() && it->first != nodoA; it++){}

            if(it != grafo.end()){

                grafo[nodoA].push_back(nodoB);

            }

            else{

                vector<int> vec1 = {nodoB};

                grafo[nodoA] = vec1;

            }

            */

        }
        
        while(scanf("%i %i", &nodoA, &nodoB) && (nodoA != 0 || nodoB != 0)){

            count = 0;
            counter2++;
            dfs(nodoA, grafo, visits, nodoB);

            for(it = visits.begin(); it != visits.end(); it++){
                
                //cout<<it->second<<" ";

                if(it->second == false){

                    count++;
                }

                else{

                    visits[it->first] = false;

                }

            }

            printf("Case %i: %i nodes not reachable from node %i with TTL = %i.\n", counter2, count, nodoA, nodoB);

        }
    }

    return 0;
}
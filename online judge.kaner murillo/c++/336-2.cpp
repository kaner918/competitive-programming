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

void bfs(int v, map<int, vector<int>>&grafo, map<int, bool>&visits, int ttl, int& cnt){

    queue<int>q;
    q.push(v);
    q.push(-1);

    visits[v] = true;

    while( q.size() > 0 && ttl>0){

        v = q.front();
        q.pop();

        if(v < 0){

            //cout<<"level: "<<ttl<<endl;
            q.push(-1);
            ttl -= 1;
        }

        else{

            //cout<<v<<endl;

            for(int x: grafo[v]){

                if(!visits[x]){

                    visits[x] = true;
                    cnt++;
                    q.push(x);
                }

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

            count = 1;
            counter2++;
            visits = map<int, bool>();
            visits[nodoA] = true;
            bfs(nodoA, grafo, visits, nodoB, count);

            /*
            for(it = visits.begin(); it != visits.end(); it++){
                
                //cout<<it->second<<" ";

                if(it->second == false){

                    count++;
                }

                else{

                    visits[it->first] = false;

                }

            }
            */

            printf("Case %i: %i nodes not reachable from node %i with TTL = %i.\n", counter2, grafo.size()-count, nodoA, nodoB);

        }
    }

    return 0;
}

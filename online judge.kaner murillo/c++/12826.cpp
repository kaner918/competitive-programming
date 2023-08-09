//https://onlinejudge.org/external/128/12826.pdf
//12826


#include<cstdio>
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>

using namespace std;

int a1, a2, b1, b2, c1, c2, arrRow[8] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int bfs(){

    int coste, i, auxA1, auxA2;
    queue<tuple<int, int, int>>q;
    q.push(make_tuple(a1, a2, 0));
    vector<vector<int>>visits(9, vector<int>(9, 0));
    visits[a1][a2] = 1;

    while(!q.empty()){

        a1 = get<0>(q.front());
        a2 = get<1>(q.front());
        coste = get<2>(q.front());
        q.pop();
        
        if(a1 == b1 && a2 == b2){
            return coste;
        }

        else if(a1!=c1 || a2 != c2){

            for(i = 0; i<8; i++){
                
                auxA1 = a1 + arrRow[i];
                auxA2 = a2 + arrColum[i];

                if(auxA1 < 9 && auxA2 < 9 && auxA1 && auxA2 && !visits[auxA1][auxA2]){
                    q.push(make_tuple(auxA1, auxA2, coste+1));
                    visits[auxA1][auxA2] = 1;
                }
            }
        }
    }
}

int main(){

    int counter = 1;

    while(scanf("%i %i %i %i %i %i", &a1, &a2, &b1, &b2, &c1, &c2) != EOF){

        printf("Case %i: %i\n", counter++, bfs());
    }

    return 0;
}
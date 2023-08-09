//https://onlinejudge.org/external/115/11573.pdf
//11573

#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<climits>
#include<algorithm>
#include<tuple>

using namespace std;

int a1, a2, b1, b2, row, colum, arrRow[] = {-1, -1, 0, 1, 1, 1, 0, -1}, arrColum[] = {0, 1, 1, 1, 0, -1, -1, -1} , graph[1001][1001], visits[1001][1001], pre[1001][1001];

int dijkstra(int index){

    a1--, a2--, b1--, b2--;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>q;
    int auxA1, auxA2, i, j, auxCoste;

    q.push(make_tuple(0, a1, a2));
    pre[a1][a2] = index;
    visits[a1][a2] = 0;
    
    while(!q.empty()){

        auxCoste = get<0>(q.top());
        a1 = get<1>(q.top()); 
        a2 = get<2>(q.top());

        q.pop();

        if((a1 != b1 || a2 != b2) && auxCoste == visits[a1][a2]){

            for(i = 0; i<8; i++){

                auxA1 = a1 + arrRow[i];
                auxA2 = a2 + arrColum[i];

                if(auxA1<row && auxA2 < colum && auxA1 > -1 && auxA2 >-1 && (auxCoste + (i != graph[a1][a2]) < visits[auxA1][auxA2] || pre[auxA1][auxA2] != index)){

                    pre[auxA1][auxA2] = index;
                    visits[auxA1][auxA2] = auxCoste + (i != graph[a1][a2]);
                    q.push(make_tuple(visits[auxA1][auxA2], auxA1, auxA2));
                }
            }
        }
    }

    return visits[b1][b2];
}

int main(){

    int i, j, travels;
    char number;

    scanf("%i %i", &row, &colum);

    for(i = 0; i<row; i++){
        cin.ignore();

        for(j = 0; j<colum; j++){
            scanf("%c", &number);
            graph[i][j] = number-48;
            visits[i][j] = INT_MAX;
            pre[i][j] = -1;
        }
    }

    cin>>travels;

    for(i = 0; i<travels; i++){

        cin>>a1>>a2>>b1>>b2;
        printf("%i\n", dijkstra(i));
    }
    
    return 0;
}
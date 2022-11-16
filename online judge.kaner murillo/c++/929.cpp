//https://onlinejudge.org/external/9/929.pdf
//929

#include<cstdio>
#include<iostream>
#include<climits>
#include<queue>
#include<tuple>

using namespace std;

int sizeRow, sizeColum, cost[1000][1000], graph[1000][1000], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

void dijkstra(){

    int i, row=0, colum=0, auxRow, auxColum, auxCost;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>cola;

    cola.push(make_tuple(graph[0][0], 0, 0));

    while(!cola.empty()){

        row = get<1>(cola.top());
        colum = get<2>(cola.top());
        auxCost = get<0>(cola.top());
        cola.pop();

        if(auxCost == cost[row][colum]){

            for(i = 0; i<4; i++){

                auxRow = row + arrRow[i];
                auxColum = colum + arrColum[i];

                if((auxRow > -1 && auxColum >-1) && (auxRow < sizeRow && auxColum < sizeColum) && cost[row][colum] != INT_MAX && auxCost + graph[auxRow][auxColum] < cost[auxRow][auxColum]){

                    cost[auxRow][auxColum] = cost[row][colum] + graph[auxRow][auxColum];
                    cola.push(make_tuple(cost[auxRow][auxColum], auxRow, auxColum));
                }
            }
        }
    }
}

int main(){ 

    int cases, i, n, m;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &sizeRow, &sizeColum);

        for(n = 0; n<sizeRow; n++){

            for(m = 0; m<sizeColum; m++){

                scanf("%i", &graph[n][m]);
                cost[n][m] = INT_MAX;
            }
        }
        
        cost[0][0] = graph[0][0];
        dijkstra();
        printf("%i\n", cost[sizeRow-1][sizeColum-1]);
    }

    return 0;
}
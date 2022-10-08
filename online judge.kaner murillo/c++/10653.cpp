#include<cstdio>
#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int arrRow[] = {0, -1, 0, 1}, arrColum[] = {-1, 0, 1, 0};

int bfs(int row, int colum, int sizeRow, int sizeColum, int rowFinish, int columFinish, int iGraph[][1000], int visits[][1000]){

    pair<int, int>pair1(row, colum);
    queue<pair<int, int>>q;

    int auxRow, auxColum, i;

    if(iGraph[row][colum] != 1){
        q.push(pair1);
        visits[row][colum] = 0;
    }
    
    while(!q.empty()){

        pair1 = q.front();
        q.pop();

        if(pair1.first == rowFinish && pair1.second == columFinish){

            return visits[pair1.first][pair1.second];
        }

        for(i = 0; i<4; i++){

            auxRow = pair1.first + arrRow[i];
            auxColum = pair1.second + arrColum[i];

            if((auxRow > -1 && auxColum > -1) && (auxRow < sizeRow && auxColum < sizeColum) && iGraph[auxRow][auxColum] != 1 && visits[auxRow][auxColum] == -1){

                visits[auxRow][auxColum] = visits[pair1.first][pair1.second] + 1;
                q.push(make_pair(auxRow, auxColum));
            }
        }

    }

    return 0;
}

int main(){

    int row, colum, rowFinish, columFinish, bombs, auxRow, auxColum, size, i, n, iGraph[1000][1000], visits[1000][1000];

    while(scanf("%i %i", &row, &colum) && (row != 0 || colum != 0)){

        for(i = 0; i<row; i++){

            for(n = 0; n<colum; n++){

                iGraph[i][n] = 0; 
                visits[i][n] = -1;
            }
        }
        
        scanf("%i", &bombs);

        while(bombs--){

            scanf("%i %i", &auxRow, &size);
            
            while(size--){

                scanf("%i", &auxColum);
                iGraph[auxRow][auxColum] = 1;
            }
        }

        scanf("%i %i\n%i %i", &auxRow, &auxColum, &rowFinish, &columFinish);

        cout<<bfs(auxRow, auxColum, row, colum, rowFinish, columFinish, iGraph, visits)<<endl;
    }

    return 0;   
}
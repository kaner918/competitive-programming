#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int arrRow[] = {0, -1, -1, 1, 0}, arrColum[] = {-1, -1, 0, 1, 1};
int movement, f, c;

void dfs(int row, int colum, int rowFinish, int columFinish, vector<vector<int>>&iGrafo, vector<vector<int>>&visits, int movements, int toy){

    visits[row][colum] = 1;
    int i, auxRow, auxColum;
    
    if(row == rowFinish && colum == columFinish && movements < movement){

        movement = movements;
        f = row;
        c = colum;
    }

    for(i = 0; i<5; i++){

        auxRow = row + arrRow[i];
        auxColum = colum = arrColum[i];

        if((auxRow > -1 && auxColum >-1) && (auxRow < iGrafo.size() && auxColum < iGrafo[0].size()) && iGrafo[auxRow][auxColum] != toy && visits[auxRow][auxColum] == 0){

            if(iGrafo[auxRow][auxColum] == 0){
                movements+=1;
            }

            dfs(auxRow, auxColum, rowFinish, columFinish, iGrafo, visits, movements);
        }
    }
}

int main(){

    int row, colums, positionRow, positionColums, auxRow, auxColums, counter;

    while(scanf("%i %i", &row, &colums) != EOF){

        vector<vector<int>>iGrafo(row, vector<int>(colums, 0));
        vector<vector<int>>iGrafo(row, vector<int>(colums, 0));

        counter = 0;
        movement = 1000000000;
        scanf("%i %i", &positionRow, &positionColums);
        iGrafo[positionRow-1][positionColums-1] = 1;
        auxRow = positionRow;

        while(scanf("%i %i", &positionRow, &positionColums) && positionRow != auxRow){

            iGrafo[positionRow-1][positionColums-1] = 1;
            counter+=1;
        }

        iGrafo[positionRow-1][positionColums-1] = 1;

        while(counter--){

            scanf("%i %i", &positionRow, &positionColums);
            iGrafo[positionRow-1][positionColums-1] = 2;
        }

        scanf("%i %i", &auxRow, &auxColums);

        dfs(auxRow, auxColums);
    }

    return 0;
}
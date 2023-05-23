//https://onlinejudge.org/external/8/868.pdf
//868

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int finishColum, arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

void solved(vector<vector<int>>&maze, int sizeRow, int sizeColum, int row, int colum, int acu, int find){

    int i, auxRow, auxColum, flag = 1;
    
    if(row == sizeRow-1){
        finishColum = min(finishColum, colum);
        flag = 0;
    }

    if(flag){

        if(maze[row][colum] == find){
            find++;
            acu = 1;
        }

        for(i = 0; i<4; i++){
            auxRow = row + arrRow[i];
            auxColum = colum + arrColum[i];

            if(auxRow>-1 && auxColum > -1 && auxRow < sizeRow && auxColum < sizeColum && maze[auxRow][auxColum] == acu){

                solved(maze, sizeRow, sizeColum, auxRow, auxColum, acu+1, find);
            }
        }
    }
    
}

int main(){

    int cases, number, row, colum, n, m, initRow, initColum;

    scanf("%i", &cases);

    while(cases--){

        cin.ignore();

        scanf("%i %i", &row, &colum);
        
        vector<vector<int>>maze(row);
        finishColum = colum;

        for(n = 0; n<row; n++){

            for(m = 0; m<colum; m++){

                scanf("%i", &number);
                maze[n].push_back(number);
            }
        }

        cin.ignore();

        for(m = 0; m<colum && colum == finishColum; m++){
            if(maze[0][m] == 1){
                solved(maze, row, colum, 0, m, 1, 1);
            }
        }

        printf("1 %i\n%i %i\n", m, row, finishColum+1);

        if(cases>0){
            printf("\n");
        }
    }
    return 0;
}
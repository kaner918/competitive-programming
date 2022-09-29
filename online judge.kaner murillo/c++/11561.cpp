//https://onlinejudge.org/external/115/11561.pdf
//11561

#include<cstdio>
#include<iostream>

using namespace std;

int gold, arrRow[] = {0,-1, 0, 1}, arrColum[] = {-1, 0, 1, 0};

void dfs(int row, int colum, int sizeRow, int sizeColum, char iGrafo[][50], int visits[][50]){

    visits[row][colum] = 1;

    if(iGrafo[row][colum] == 'G'){
        gold+=1;
    }

    int i, auxRow, auxColum;

    if((iGrafo[row+arrRow[0]][colum+arrColum[0]] != 'T') && (iGrafo[row+arrRow[1]][colum+arrColum[1]] != 'T') && (iGrafo[row+arrRow[2]][colum+arrColum[2]] != 'T') && (iGrafo[row+arrRow[3]][colum+arrColum[3]] != 'T')){

        for(i = 0; i<4; i++){

            auxRow = row + arrRow[i];
            auxColum = colum + arrColum[i];

            if((auxRow>-1 && auxColum >-1) && (auxRow<sizeRow && auxColum<sizeColum) && visits[auxRow][auxColum] == 0 && iGrafo[auxRow][auxColum] != '#'){

                dfs(auxRow, auxColum, sizeRow, sizeColum, iGrafo, visits);
            }
        }
    }
}

int main(){

    int row, colum, i, n, positionX, positionY, visits[50][50];
    char iGrafo[50][50];

    while(scanf("%i %i", &colum, &row)!= EOF){

        gold = 0;

        for(i = 0; i<row; i++){

            cin.ignore();
            for(n = 0; n<colum; n++){

                scanf("%c", &iGrafo[i][n]);
                visits[i][n] = 0;

                if(iGrafo[i][n] == 'P'){

                    positionX = i;
                    positionY = n;
                    
                }
            }
        }

        dfs(positionX, positionY, row, colum, iGrafo, visits);
        cout<<gold<<endl;

    }

    return 0;
}
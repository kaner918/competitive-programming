//https://onlinejudge.org/external/5/572.pdf
//572

#include<cstdio>
#include<iostream>

using namespace std;

char graph[100][100];
int visits[100][100], arrRow[] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[] = {0, -1, -1, -1, 0, 1, 1, 1};

void dfs(int row, int colum, int sizeRow, int sizeColum){

    visits[row][colum] = 1;
    
    int i, auxRow, auxColum;

    for(i = 0; i<8; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 and auxColum > -1 ) && (auxRow < sizeRow && auxColum < sizeColum) && visits[auxRow][auxColum] == 0 && graph[auxRow][auxColum] == '@'){

            dfs(auxRow, auxColum, sizeRow, sizeColum);
        }
    }
}

int main(){

    int row, colum, i, n, counter;

    while(scanf("%i %i", &row, &colum) && (row != 0 || colum != 0)){

        for(i = 0; i<row; i++){

            cin.ignore();
            for(n = 0; n<colum; n++){

                scanf("%c", &graph[i][n]);
                visits[i][n] = 0;
            }
        }
        
        counter = 0;

        for(i = 0; i<row; i++){

            for(n = 0; n<colum; n++){

                if(visits[i][n] == 0 && graph[i][n] == '@'){

                    counter++;
                    dfs(i, n, row, colum);
                }
            }
        }

        printf("%i\n", counter);

    }
    return 0;
}
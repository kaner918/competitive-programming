//https://onlinejudge.org/external/112/11244.pdf
//11244

#include<cstdio>
#include<iostream>

using namespace std;

char graph[100][100];
int visits[100][100], arrRow[] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[] = {0, -1, -1, -1, 0, 1, 1, 1};
bool ans;

void dfs(int row, int colum, int sizeRow, int sizeColum){

    visits[row][colum] = 1;

    int i, auxRow, auxColum;

    for(i = 0; i<8; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum > -1) && (auxRow < sizeRow && auxColum < sizeColum) && graph[auxRow][auxColum] == '*' && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, sizeRow, sizeColum);
            ans = false;
        }
    }
}

int main(){

    int row, colum, n, m, counter;

    while(scanf("%i %i", &row, &colum) && (row!= 0 || colum !=0)){

        for(n = 0; n<row; n++){

            cin.ignore();

            for(m = 0; m<colum; m++){

                scanf("%c", &graph[n][m]);
                visits[n][m] = 0;
            }
        }

        counter = 0;

        for(n = 0; n<row; n++){

            for(m = 0; m<colum; m++){
                
                ans = true;

                if(visits[n][m] == 0 && graph[n][m] == '*'){

                    dfs(n, m, row, colum);
                    
                    if(graph[n][m] == '*' && ans == true){

                        counter++;
                    }
                }
            }
        }

        printf("%i\n", counter);
    }

    return 0;
}
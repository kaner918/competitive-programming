//https://onlinejudge.org/external/119/11953.pdf
//11953

#include<cstdio>
#include<iostream>

using namespace std;

char graph[100][100];
int visits[100][100], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1}; 

void dfs(int row, int colum, int size){

    visits[row][colum] = 1;

    int i, auxRow, auxColum;

    for(i = 0; i<4; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum > -1) && (auxRow < size && auxColum < size) && graph[auxRow][auxColum] != '.' && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, size);
        }
    }
}

int main(){

    int cases, size, i, counter, n, m;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i", &size);

        for(n = 0; n<size; n++){

            cin.ignore();

            for(m = 0; m<size; m++){

                scanf("%c", &graph[n][m]);
                visits[n][m] = 0;
            }
        }

        counter = 0;

        for(n = 0; n<size; n++){

            for(m = 0; m<size; m++){

                if(visits[n][m] == 0 && graph[n][m] == 'x'){

                    dfs(n, m, size);
                    counter++;
                }
            }
        }
        printf("Case %i: %i\n", i, counter);
    }

    return 0;
}
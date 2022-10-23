//https://onlinejudge.org/external/114/11470.pdf
//11470

#include<cstdio>
#include<iostream>

using namespace std;

int graph[10][10], visits[10][10], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1}, res[6], sum, minRow, minColum, maxRow, maxColum, pos;

void dfs(int row, int colum){

    visits[row][colum] = 1;
    sum+=graph[row][colum];

    if(row == minRow && colum == maxColum-1){

        pos = 0;
    }

    else if(row == maxRow-1 && colum == maxColum-1){

        pos = 1;
    }

    else if(row == maxRow-1 && colum == minColum){

        pos = 2;
    }

    int auxRow, auxColum;

    auxRow = row + arrRow[pos];
    auxColum = colum + arrColum[pos];

    if((auxRow > -1 && auxColum > -1) && (auxRow < maxRow && auxColum < maxColum) && visits[auxRow][auxColum] == 0){

        dfs(auxRow, auxColum);
    }

}

int main(){

    int size, counter = 1, counter2, n, m;

    while(scanf("%i", &size) && size != 0){

        for(n = 0; n<size; n++){

            for(m = 0; m<size; m++){

                scanf("%i", &graph[n][m]);
                visits[n][m] = 0;
            }
        }

        counter2 = 0;
        maxRow = size;
        maxColum = size;
        minRow = 0;
        minColum = 0;

        for(n = 0; n<size; n++){
            
            for(m = 0; m<size; m++){

                if(visits[n][m] == 0){

                    sum = 0;
                    pos = 3;
                    dfs(n, m);
                    res[m] = sum;
                    counter2++;
                }
            }

            maxRow-=1;
            maxColum-=1;
            minRow++;
            minColum++;
        }

        printf("Case %i:", counter);

        for(n = 0; n<counter2; n++){

            printf(" %i", res[n]);
        }

        printf("\n");

        counter++;
    }
    return 0;   
}
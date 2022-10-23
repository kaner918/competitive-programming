//https://onlinejudge.org/external/3/352.pdf
//352

#include<cstdio>
#include<iostream>

using namespace std;

char graph[25][25];
int visits[25][25], arrRow[] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[] = {0, -1, -1, -1, 0, 1, 1, 1};

void dfs(int row, int colum, int size){

    visits[row][colum] = 1;

    int i, auxRow, auxColum;

    for(i = 0; i<8; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum > -1) && (auxRow < size && auxColum < size) && graph[auxRow][auxColum] == '1' && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, size);
        }
    }
}

int main(){ 

    int size, n, m, counter, counter2 = 1;

    while(scanf("%i", &size) != EOF){

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

                if(visits[n][m] == 0 && graph[n][m] == '1'){

                    dfs(n, m, size);
                    counter++;
                }
            }
        }

        printf("Image number %i contains %i war eagles.\n", counter2, counter);

        counter2++;
    }

    return 0;
}
//https://onlinejudge.org/external/8/871.pdf
//871

#include<cstdio>
#include<iostream>

using namespace std;

char graph[25][25];
int visits[25][25], arrRow[] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[] = {0, -1, -1, -1, 0, 1, 1, 1}, counter;

void dfs(int row, int colum, int sizeRow, int sizeColum){

    visits[row][colum] = 1;
    counter++;

    int i, auxRow, auxColum;

    for(i = 0; i<8; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum > -1) && (auxRow < sizeRow && auxColum < sizeColum) && graph[auxRow][auxColum] == '1' && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, sizeRow, sizeColum);
        }
    }
}

int main(){

    int cases, n, m, higer, sizeRow, sizeColum;
    string cad;

    scanf("%i\n", &cases);
    
    while(cases--){

        n = 0;
        
        while(getline(cin, cad) && cad != ""){

            for(m = 0; m<cad.length(); m++){
                
                sizeColum = cad.length();
                graph[n][m] = cad[m];
                visits[n][m] = 0;
            }
            n++;
        }

        sizeRow = n;

        /* for(n = 0; n<sizeRow; n++){

            for(m = 0; m<sizeColum; m++){

                cout<<graph[n][m];
            }

            printf("\n");
        } */

        higer = 0;

        for(n = 0; n<sizeRow; n++){

            for(m = 0; m<sizeColum; m++){

                if(visits[n][m] == 0 && graph[n][m] == '1'){

                    counter = 0;
                    dfs(n, m, sizeRow, sizeColum);

                    if(counter>higer){

                        higer = counter;
                    }
                }
            }
        }

        printf("%i\n", higer);

        if(cases>0){
            printf("\n");
        }
    }
    
    return 0;
}

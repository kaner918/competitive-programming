//https://onlinejudge.org/external/7/784.pdf
//784

#include<cstdio>
#include<iostream>
#include<string>

char graph[30][82];
int visits[30][82], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

void dfs(int row, int colum, int sizeRow){

    visits[row][colum] = 1;
    graph[row][colum] = '#';

    int i, auxRow, auxColum;

    for(i = 0; i<4; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum >-1) && (auxRow < sizeRow && auxColum < visits[auxRow][81]) && graph[auxRow][auxColum] == ' ' && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, sizeRow);

        }
    }
}

using namespace std;    

int main(){

    int cases, i, n = 0, m, x, positionRow, positionColum, position;
    char letter;
    string separator;

    scanf("%i", &cases);
    cin.ignore();
    
    for(i = 0; i<cases; i++){

        m = 0;
        position = 0;
        separator = "_";
        positionRow = 0;
        positionColum = 0;

        while(scanf("%c", &letter) && letter !='_'){

            n = 1;
            graph[m][0] = letter;   
            visits[m][0] = 0;
            
            if(graph[m][0] == '*'){

                positionRow = m;
                positionColum = 0;
            }

            while(scanf("%c", &letter) && letter !='\n'){
                
                graph[m][n] = letter;
                visits[m][n] = 0;

                if(graph[m][n] == '*'){

                    positionRow = m;
                    positionColum = n;
                }

                n+=1;
            }

            visits[position][81] = n;
            m+=1;
            position+=1;
        }

        while(scanf("%c", &letter) && letter != '\n'){

            separator+="_";
        }

        dfs(positionRow, positionColum, m);

        for(n = 0; n<m; n++){

            for(x = 0; x<visits[n][81]; x++){

                printf("%c", graph[n][x]);

            }

            printf("\n");
        } 

        cout<<separator<<endl;
    }
    
    return 0;
}
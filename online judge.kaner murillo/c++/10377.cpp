//https://onlinejudge.org/external/103/10377.pdf
//10377

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

char maze[61][61];

char arrOrientation[] = {'S', 'W', 'N', 'E'};
int arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1}, resRow, resColum, resOrientation;

void dfs(int row, int colum, int sizeRow, int sizeColum, int sizeMovent, int movement, int orientation, string&instructions){

    /* cout<<row<<" "<<colum<<" "<<instructions[movement]<<endl; */

    resRow = row;
    resColum = colum;
    resOrientation = orientation;

    if(instructions[movement] == 'F'){

        row+=arrRow[orientation];
        colum+=arrColum[orientation];
    }

    else if(instructions[movement] == 'R'){
        orientation+=1;
        if(orientation>3){
            orientation = 0;
        }
    }

    else{
        orientation-=1;
        if(orientation<0){
            orientation = 3;
        }
    }

    if(movement < sizeMovent){

        if(row > -1 && colum > -1 && row < sizeRow && colum < sizeColum && maze[row][colum]!='*'){

            dfs(row, colum, sizeRow, sizeColum, sizeMovent, movement+1, orientation, instructions);
        }

        else{

            dfs(row-arrRow[orientation], colum-arrColum[orientation], sizeRow, sizeColum, sizeMovent, movement+1, orientation, instructions);
        }
    }
}

int main(){

    int row, colum, rowInit, columInit, i, n, cases;
    string cad;
    char letter;

    scanf("%i", &cases);

    while(cases--){

        cin.ignore();
        scanf("%i %i", &row, &colum);
        cad = "";

        for(i = 0; i<row; i++){

            cin.ignore();

            for(n = 0; n<colum; n++){

                scanf("%c", &maze[i][n]);
            }
        } 

        scanf("%i %i\n", &rowInit, &columInit);

        while(scanf("%c", &letter) && letter != 'Q'){

            if(letter != '\n' && letter != ' '){
                cad+=letter;
            }
        }

        dfs(rowInit-1, columInit-1, row, colum, cad.length(), 0, 2, cad);

        printf("%i %i %c\n", resRow+1, resColum+1, arrOrientation[resOrientation]);

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}
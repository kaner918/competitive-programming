//https://onlinejudge.org/external/118/11831.pdf
//11835

#include<cstdio>
#include<iostream>

using namespace std;

char maze[110][110], instructions[50100];
int arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

int dfs(int row, int colum, int sizeRow, int sizeColum, int sizeMovent, int sizeSum, int movement, int orientation, int acum){

    int counter = 0;

    /* cout<<row<<" "<<colum<<" "<<instructions[movement]<<endl; */

    if(maze[row][colum] == '*'){
        
        counter++;
        acum++;

        if(acum == sizeSum){

            return counter;
        }

        maze[row][colum] = '.';
    }

    if(instructions[movement] == 'F'){

        row+=arrRow[orientation];
        colum+=arrColum[orientation];
    }

    else if(instructions[movement] == 'D'){
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

        if(row > -1 && colum > -1 && row < sizeRow && colum < sizeColum && maze[row][colum]!='#'){

            counter+=dfs(row, colum, sizeRow, sizeColum, sizeMovent, sizeSum, movement+1, orientation, acum);
        }

        else{

            counter+=dfs(row-arrRow[orientation], colum-arrColum[orientation], sizeRow, sizeColum, sizeMovent, sizeSum, movement+1, orientation, acum);
        }
    }

    return counter;
}

int main(){

    int row, colum, s, i, n, rowInit, columInit, orientation, sums;

    while(scanf("%i %i %i", &row, &colum, &s) && (row || colum || s)){

        sums = 0;
        
        for(i = 0; i<row; i++){
            
            cin.ignore();

            for(n = 0; n<colum; n++){

                scanf("%c", &maze[i][n]);

                if(maze[i][n] == 'O'){

                    rowInit = i;
                    columInit = n;
                    orientation = 1;
                }

                else if(maze[i][n] == 'N'){

                    rowInit = i;
                    columInit = n;
                    orientation = 2;
                }

                else if(maze[i][n] == 'S'){

                    rowInit = i;
                    columInit = n;
                    orientation = 0;
                }

                else if(maze[i][n] == 'L'){

                    rowInit = i;
                    columInit = n;
                    orientation = 3;
                }

                else if(maze[i][n] == '*'){

                    sums+=1;
                }
            }
        }

        cin.ignore();

        for(i = 0; i<s; i++){
            scanf("%c", &instructions[i]);
        }

        printf("%i\n", dfs(rowInit, columInit, row, colum, s, sums, 0, orientation, 0));
    }

    return 0;
}
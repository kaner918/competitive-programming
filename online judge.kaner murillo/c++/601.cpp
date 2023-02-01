//https://onlinejudge.org/external/6/601.pdf
//601

#include<cstdio>
#include<iostream>

using namespace std;

char graph[82][82];
int visits[82][82], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};
bool flag, flag2, flag3, flag4;

void dfs(int row, int colum, char letter, int size, bool sign){

    //cout<<row<<" "<<colum<<" "<<letter<<endl;

    if(visits[row][colum] != 'U' && sign == false){

        visits[row][colum] = 1;

    }

    else if(visits[row][colum] != 'U' && sign == true){

        visits[row][colum] = 2;

    }
    
    if(letter == 'W' && colum == size-1 && sign == true){

        flag2 = true;

    }

    else if(letter == 'B' && row == size-1 && sign == true){

        flag4 = true;

    }
    
    else if(letter == 'W' && colum == size-1 && sign == false){

        flag = true;

    }
    

    else if(letter == 'B' && row == size-1 && sign == false){

        flag3 = true;

    }

    if(!flag2 && !flag4){

        int i, auxRow, auxColum;

        for(i = 0; i<4; i++){

            auxRow = row + arrRow[i];
            auxColum = colum + arrColum[i];

            if((auxRow > -1 && auxColum > -1) && (auxRow < size && auxColum < size) && visits[auxRow][auxColum] == 0 && graph[auxRow][auxColum] == letter){

                dfs(auxRow, auxColum, letter, size, sign);
            }

            else if((auxRow > -1 && auxColum > -1) && (auxRow < size && auxColum < size) && visits[auxRow][auxColum] == 1 && graph[auxRow][auxColum] == letter && sign == true){

                dfs(auxRow, auxColum, letter, size, sign);
            }

            else if((auxRow > -1 && auxColum >-1) && (auxRow < size && auxColum < size) && graph[auxRow][auxColum] == 'U' && sign == true){

                dfs(auxRow, auxColum, letter, size, false);
            }

            else if((auxRow >-1 && auxColum >-1) && (auxRow < size && auxColum < size) && visits[auxRow][auxColum] == 0 && graph[row][colum] == 'U' && graph[auxRow][auxColum] == letter){

                dfs(auxRow, auxColum, letter, size, false);
            }
        }
    }
}

int main(){

    int size, i, n;

    while(scanf("%i", &size) && size != 0){

        cin.ignore();

        for(i = 0; i<size; i++){

            cin.ignore();

            for(n = 0; n<size; n++){

                scanf("%c", &graph[i][n]);
                visits[i][n] = 0;
            }
        }

        cin.ignore();
        cin.ignore();

        flag = false;
        flag2 = false;
        flag3 = false;
        flag4 = false;

        for(i = 0; i<size && !flag2 && !flag4; i++){

            if(graph[0][i] == 'U'){

                dfs(0, i, 'B', size, false);
            }

            else if(graph[0][i] == 'B'){

                dfs(0, i, graph[0][i], size, true);
            }
        }
        
        for(i = 0; i<size && !flag2 && !flag4; i++){

            if(graph[i][0] == 'U'){

                dfs(i, 0, 'W', size, false);
            }

            else if(graph[i][0] == 'W'){

                dfs(i, 0, graph[i][0], size, true);
            }
        }

        if(flag2){

            printf("White has a winning path.\n");
        }

        else if(flag4){

            printf("Black has a winning path.\n");
        }

        else if(flag){

            printf("White can win in one move.\n");
        }

        else if(flag3){

            printf("Black can win in one move.\n");
        }

        else{

            printf("There is no winning path.\n");            
        }
    }

    return 0;
}
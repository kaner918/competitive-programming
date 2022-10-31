//https://onlinejudge.org/external/101/10116.pdf
//10116

#include<cstdio>
#include<iostream>

using namespace std;

char graph[10][10];
int visits[10][10], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1}, counter, calculation, init;

int move(int row, int colum){

    if(graph[row][colum] == 'W'){

        return 1;
    }

    else if(graph[row][colum] == 'S'){

        return 0;
    }

    else if(graph[row][colum] == 'N'){

        return 2;
    }

    return 3;
}

void dfs(int row, int colum, int sizeRow, int sizeColum){

    //cout<<graph[row][colum]<<endl;

    visits[row][colum] = counter;
    counter++;

    int i, auxRow, auxColum, move1 = move(row, colum);

    auxRow = row + arrRow[move1];
    auxColum = colum + arrColum[move1];

    if((auxRow > -1 && auxColum > -1) && (auxRow < sizeRow && auxColum < sizeColum)){

        if(visits[auxRow][auxColum] == -1){

            dfs(auxRow, auxColum, sizeRow, sizeColum);
        }
        
        else{

            calculation = (visits[row][colum] - visits[auxRow][auxColum]) + 1;
            init = visits[auxRow][auxColum];
        }
    }    
}

int main(){

    int row, colum, position, n, m, ans;

    while(scanf("%i %i %i", &row, &colum, &position) && (row != 0 || colum  != 0 || position != 0)){

        counter = 0;
        calculation = -1;

        for(n = 0; n<row; n++){

            cin.ignore();

            for(m = 0; m<colum; m++){

                scanf("%c", &graph[n][m]);
                visits[n][m] = -1;
            }
        }

        dfs(0, position-1, row, colum);

        if(calculation != -1){

            printf("%i step(s) before a loop of %i step(s)\n", init, calculation);
        }

        else{

            printf("%i step(s) to exit\n", counter);
        }

    }

    return 0;
}
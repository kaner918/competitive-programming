//https://onlinejudge.org/external/6/614.pdf
//614

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int index, arrRow[] = {0, -1, 0, 1}, arrColum[] = {-1, 0, 1, 0}, cases = 1;
bool ans;

void dfs(int row, int colum, int rowFinish, int columFinish, int sizeRow, int sizeColum, int iGraph[][12], int visits[][12]){

    visits[row][colum] = index;
    index+=1;

    int auxRow, auxColum, i;


    if(row == rowFinish && colum == columFinish){

        ans = true;
    }
    
    else{

        for(i = 0; i<4; i++){

            auxRow = row + arrRow[i];
            auxColum = colum + arrColum[i];

            if(ans == false && (auxRow>-1 && auxColum>-1) && (auxRow<sizeRow && auxColum<sizeColum) && visits[auxRow][auxColum] == -1 && ((i == 0 && iGraph[auxRow][auxColum] != 1 && iGraph[auxRow][auxColum] != 3) || (i == 1 && iGraph[auxRow][auxColum]!=2 && iGraph[auxRow][auxColum] != 3)||(i==2 && iGraph[row][colum] != 1 && iGraph[row][colum]!=3)||(i == 3 && iGraph[row][colum]!=2 && iGraph[row][colum]!=3))){

                dfs(auxRow, auxColum, rowFinish, columFinish, sizeRow, sizeColum, iGraph, visits);

            }
        }

        if(ans == false){

            visits[row][colum] = -2;
            index-=1;
        }
    }
}

int main(){

    int row, colum, initRow, initColum, finishRow, finishColum, i, n, iGraph[12][12], visits[12][12];
    string cad, line;
    bool flag;

    //poner mas bonito la condicion de parada.
    while(scanf("%i %i %i %i %i %i", &row, &colum, &initRow, &initColum, &finishRow, &finishColum) && (row!= 0 || colum != 0 || initRow!= 0 || initColum!= 0 || finishRow != 0 || finishColum != 0)){

        index = 1;
        ans = false;
        flag = true;
        cad = "+";
        for(i = 0; i<row; i++){

            for(n = 0; n<colum; n++){

                scanf("%i", &iGraph[i][n]);
                visits[i][n] = -1;

                if(flag){

                    cad+="---+";
                }
            }

            flag = false;
        }

        dfs(initRow-1, initColum-1, finishRow-1, finishColum-1, row, colum, iGraph, visits);

        printf("Maze %i\n\n", cases);

        printf("%s\n", cad.c_str());

        for(i = 0; i<row; i++){

            printf("|");
            line = "+";
            for(n = 0; n<colum; n++){

                if(visits[i][n] == -1){

                    printf("   ");
                }

                else if(visits[i][n] == -2){

                    printf("???");
                }

                else{

                    printf("%3i", visits[i][n]);
                }

                if(iGraph[i][n] == 1){

                    if(n<colum-1){

                        printf("|");

                          
                    }   
                    line+="   +";               
                }
                
                else if(iGraph[i][n] == 3){

                    if(n<colum-1){

                        printf("|");

                    }   
                    line+="---+";                 
                }

                else if(iGraph[i][n] == 2){
                    
                    if(n<colum-1){

                        printf(" ");
                        
                    }
                    line+="---+";
                }

                else{
                    
                    if(n<colum-1){

                        printf(" ");
                         
                    }

                    line+="   +";
                }
            }

            printf("|\n");

            if(i<row-1){

                printf("%s\n", line.c_str());
            }
        }
        
        printf("%s\n\n\n", cad.c_str());

        cases+=1;
        cin.ignore();
    } 

    return 0;
}
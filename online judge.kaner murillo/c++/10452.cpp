//https://onlinejudge.org/external/104/10452.pdf
//10452

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

char maze[9][9], combi[8] = {'I', 'E', 'H', 'O', 'V', 'A', '#'}, ouput[3][6] = {{'f', 'o', 'r', 't', 'h'}, {'l', 'e', 'f', 't'}, {'r', 'i', 'g', 'h', 't'}};

int arrRow[] = {-1, 0, 0}, arrColum[] = {0, -1, 1}, flag;
string res;

void solved(int row, int colum, int sizeRow, int sizeColum, int index, string cad){

    if(flag){
            
        if(index == 7){
            res = cad;
            flag = 0;
        }

        else{

            int i, auxRow, auxColum;
            string aux;
            
            for(i = 0; i<3; i++){
                
                aux = "";
                aux+=(i+48);
                auxRow = row + arrRow[i];
                auxColum = colum + arrColum[i];

                if(auxRow > -1 && auxColum > -1 && auxRow < sizeRow && auxColum < sizeColum && maze[auxRow][auxColum] == combi[index]){

                    solved(auxRow, auxColum, sizeRow, sizeColum, index+1, cad + aux);
                }
            }
        }
    }
}

int main(){

    int cases, row, colum, i, n, rowInit, columInit;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &row, &colum);
        res = "";
        flag = 1;

        for(i = 0; i<row; i++){

            cin.ignore();

            for(n = 0; n<colum; n++){

                scanf("%c", &maze[i][n]);
                if(maze[i][n] == '@'){
                    rowInit = i;
                    columInit = n;
                }
            }
        }
        
        solved(rowInit, columInit, row, colum, 0, "");

        for(i = 0; i<res.length()-1; i++){

            cout<<ouput[res[i]-48]<<" ";
        }

        cout<<ouput[res[res.length()-1]-48]<<endl;
    }

    return 0;
}
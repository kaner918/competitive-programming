//https://onlinejudge.org/external/1/116.pdf
//116

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int memo[101][101], pre[101][101], matrix[101][101];

int dp(int row, int colum, int sizeRow, int sizeColum){

    if(colum == sizeColum){
        return 0;
    }

    else if(memo[row][colum] != -1){
        return memo[row][colum];
    }

    else{
        
        int auxRow1, auxRow2, a, b, c, auxPre, mini = INT_MAX;

        auxRow1 = row-1;
        auxRow2 = row+1;

        if(auxRow1==-1){
            auxRow1 = sizeRow-1;
        }

        if(auxRow2==sizeRow){
            auxRow2 = 0;
        }

        a = dp(row, colum+1, sizeRow, sizeColum);
        b = dp(auxRow1, colum+1, sizeRow, sizeColum);
        c = dp(auxRow2, colum+1, sizeRow, sizeColum);


        if(b<mini){
            mini = b;
            auxPre = auxRow1;
        }

        if(a<mini || (a==mini && row<auxPre)){
            mini = a;
            auxPre = row; 
        }

        if(c<mini || (c==mini && auxRow2<auxPre)){
            mini = c;
            auxPre = auxRow2;
        }

        pre[row][colum] = auxPre+1;
        memo[row][colum] = matrix[row][colum] + mini;
        return memo[row][colum];
    }
}   

int main(){

    int row, colum, num, i, j, aux, mini;

    while(scanf("%i %i", &row, &colum) != EOF){

        mini = INT_MAX;

        for(i = 0; i<row; i++){
            for(j = 0; j<colum; j++){
                scanf("%i", &matrix[i][j]);
                memo[i][j] = -1;
            }
        }

        for(i = 0; i<row; i++){

            aux = dp(i, 0, row, colum);

            if(aux < mini){
                mini = aux;
                num = i;
            }
        }
        
        if(colum!=1){

            printf("%i ", num+1);

            for(i = 0; i<colum-2; i++){
                
                printf("%i ", pre[num][i]);
                num = pre[num][i]-1;
            }
            printf("%i\n%i\n", pre[num][i], mini);
        }

        else{
            printf("%i\n%i\n", num+1, mini);
        }

    }

    return 0;
}
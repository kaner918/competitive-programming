//https://onlinejudge.org/external/113/11352.pdf
//11352

#include<cstdio>
#include<iostream>
#include<queue>
#include<tuple>

int a1, a2, b1, b2, sizeRow, sizeColum, horseRow[] = {2, 1, -1, -2, -2, -1, 1, 2}, horseColum[] = {-1, -2, -2, -1, 1, 2, 2, 1}, arrRow[] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[] = {0, -1, -1, -1, 0, 1, 1, 1}, visits[101][101];
char board[101][101];

using namespace std;

int check(int row, int colum){

    if(board[row][colum] == 'Z'){
        return 0;
    }

    int i, auxRow, auxColum;

    for(i = 0; i<8; i++){

        auxRow = row + horseRow[i];
        auxColum = colum + horseColum[i];

        if(auxRow>-1 && auxColum > -1 && auxRow<sizeRow && auxColum < sizeColum && board[auxRow][auxColum] == 'Z'){
            return 0;
        }
    }

    return 1;
}

int bfs(){

    queue<tuple<int, int, int>>q;
    visits[a1][a2] = 0;
    q.push(make_tuple(a1, a2, 0));

    int auxRow, auxColum, i, coste;    

    while(!q.empty()){

        a1 = get<0>(q.front());
        a2 = get<1>(q.front());
        coste = get<2>(q.front());
        q.pop();

        if(a1 == b1 && a2 == b2){
            return visits[a1][a2];
        }

        for(i = 0; i<8; i++){

            auxRow = a1 + arrRow[i];
            auxColum = a2 + arrColum[i];

            if(auxRow>-1 && auxColum > -1 && auxRow<sizeRow && auxColum < sizeColum && visits[auxRow][auxColum] == -1 && (board[auxRow][auxColum] == 'B' || check(auxRow, auxColum))){
                visits[auxRow][auxColum] = coste + 1;
                q.push(make_tuple(auxRow, auxColum, coste+1));
            }   
        }
    }

    return -1;
}

int main(){

    int cases, i, j;    

    scanf("%i", &cases);
    
    while(cases--){
        
        scanf("%i %i", &sizeRow, &sizeColum);

        for(i = 0; i<sizeRow; i++){
            cin.ignore();
            for(j = 0; j<sizeColum; j++){
                scanf("%c", &board[i][j]);
                visits[i][j] = -1;

                if(board[i][j] == 'A'){
                    a1 = i;
                    a2 = j;
                }

                else if(board[i][j] == 'B'){
                    b1 = i;
                    b2 = j;
                }
            }
        }

        if(bfs()!=-1){
            printf("Minimal possible length of a trip is %i\n", visits[b1][b2]);
        }

        else{

            printf("King Peter, you can't go now!\n");
        }

    }

    return 0;
}
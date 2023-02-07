//https://onlinejudge.org/external/107/10707.pdf
//10707
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

void dfs(int row, int colum, vector<vector<int>>&board, int &size){

    size++;
    //cout<<row<<" "<<colum<<endl;
    board[row][colum] = -2;
    int i, auxRow, auxColum;

    for(i = 0; i<4; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum >-1) && (auxRow<board.size() && auxColum<board[0].size()) && (board[auxRow][auxColum] == -1)) dfs(auxRow, auxColum, board, size);
    }
}


int main(){

    int cases, i, n, row, colum, x, y, points, size1, size2, counter1, counter2;

    scanf("%i", &cases);

    while(cases--){


        counter1 = 0;
        counter2 = 0;

        scanf("%i %i %i", &row, &colum, &points);

        vector<vector<int>>board1(row, vector<int>(colum, 1));
        vector<vector<int>>board2(row, vector<int>(colum, 1));
        set<int>conj;

        for(i = 0; i<points*2; i++){

            scanf("%i %i", &x, &y);

            if(i<points) board1[x][y] = -1;
            else board2[x][y] = -1;

        }

        for(i = 0;i<row;i++){
            
            for(n = 0; n<colum; n++){

                size1 = 0;
                if(board1[i][n] == -1) dfs(i, n, board1, size1), conj.insert(size1), counter1++;
            }
        }

        x = conj.size();
        
        for(i = 0;i<row;i++){
            
            for(n = 0; n<colum; n++){

                size2 = 0;
                if(board2[i][n] == -1) dfs(i, n, board2, size2), conj.insert(size2), counter2++;
            }
        } 

        if(counter1 == counter2 && x == conj.size()) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}
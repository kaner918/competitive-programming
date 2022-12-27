#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arrRow[] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[] = {0, -1, -1, -1, 0, 1, 1, 1};

int bfs(int x1, int y1, int x2, int y2, vector<vector<int>>&visits){

    queue<pair<int, int>>q;
    q.push(make_pair(x1, y1));
    visits[x1][y1] = 0;
    int auxX, auxY, i, n, auxRow, auxColum;

    while(!q.empty()){

        auxX = q.front().first;
        auxY = q.front().second;

        q.pop();

        if(auxX == x2 && auxY == y2){

            return visits[x2][y2]; 
        }

        else{

            for(i = 0; i<8; i++){

                for(n = 7; n>0; n--){

                    auxRow = auxX + arrRow[i] * n;
                    auxColum = auxY + arrColum[i] * n;

                    if((auxRow < 8 && auxColum < 8) && (auxRow > -1 && auxColum > -1) && visits[auxRow][auxColum] == -1){
                        
                        visits[auxRow][auxColum] = visits[auxX][auxY] + 1; 
                        q.push(make_pair(auxRow, auxColum));
                    }    
                }
            }
        }
    }

    return -1;
}

int main(){

    int x1, y1, x2, y2;

    while(scanf("%i %i %i %i", &x1, &y1, &x2, &y2) && (x1 != 0 || x2 != 0 || y1 != 0 || y2 != 0)){

        vector<vector<int>>visits(8, vector<int>(8, -1));
        printf("%i\n", bfs(x1-1, y1-1, x2-1, y2-1, visits));
    }
}
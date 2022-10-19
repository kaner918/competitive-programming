//https://onlinejudge.org/external/9/928.pdf
//928

#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

char graph[300][300];
int visits[300][300][3], arrRow[] = {-1, 1, 0, 0}, arrColum[] = {0, 0, -1, 1};


struct State{

    int row;
    int colum;
    int state;

    State(){}
    State(int row2, int colum2, int state2){

        row = row2;
        colum = colum2;
        state = state2;
    }
};

int bfs(State stateInit, State stateFinish, int sizeRow, int sizeColum){

    State auxState;
    int i, move, auxRow, auxColum;
    queue<State>q;
    q.push(stateInit);
    bool ans;

    visits[stateInit.row][stateInit.colum][stateInit.state-1] = 0;

    while(!q.empty()){

        auxState = q.front();

        q.pop();

        if(auxState.row == stateFinish.row && auxState.colum == stateFinish.colum){

            return visits[auxState.row][auxState.colum][auxState.state-1];
        }

        if(auxState.state == 1){

            move = 2;
        }

        else if(auxState.state == 2){

            move = 3;
        }

        else{

            move = 1;
        }

        for(i = 0; i<4; i++){

            ans = false;
            auxRow = auxState.row + (arrRow[i] * auxState.state);
            auxColum = auxState.colum + (arrColum[i] * auxState.state);

            if((auxRow > -1 && auxColum > -1) && (auxRow < sizeRow && auxColum < sizeColum) && graph[auxRow][auxColum] != '#' && visits[auxRow][auxColum][move-1] == -1){
                
                if(auxState.state == 3 && (graph[auxState.row + arrRow[i]][auxState.colum + arrColum[i]] != '#') && ((graph[auxState.row + arrRow[i] * 2][auxState.colum + arrColum[i] * 2] != '#'))){

                    ans = true;

                }

                else if(auxState.state == 2 && graph[auxState.row + arrRow[i]][auxState.colum + arrColum[i]] != '#'){

                    ans = true;

                }

                else if(auxState.state == 1){

                    ans = true;
                }

                if(ans == true){

                    q.push(State(auxRow, auxColum, move));
                    visits[auxRow][auxColum][move-1] = visits[auxState.row][auxState.colum][auxState.state-1] + 1;

                }
            }

        }
    }
    
    return -1;
}

int main(){

    int cases, row, colum, i, n, rowInit, columInit, rowFinish, columFinish, ans;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &row, &colum);

        for(i = 0; i<row; i++){

            cin.ignore();

            for(n = 0; n<colum; n++){

                scanf("%c", &graph[i][n]);
                visits[i][n][0] = -1;
                visits[i][n][1] = -1;
                visits[i][n][2] = -1;

                if(graph[i][n] == 'S'){

                    rowInit = i;
                    columInit = n;
                }

                else if(graph[i][n] == 'E'){

                    rowFinish = i;
                    columFinish = n;
                }
            }
        }
        
        ans = bfs(State(rowInit, columInit, 1), State(rowFinish, columFinish, 1), row, colum);

        if(ans != -1){

            printf("%i\n", ans);
        }

        else{

            printf("NO\n");
        }

    }

    return 0;
}
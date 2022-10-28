//https://onlinejudge.org/external/116/11624.pdf
//11624

#include<cstdio>
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>

using namespace std;

char graph[1000][1000];
int visits[1000][1000], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

int bfs(int rowJoe, int columJoe, vector<tuple<int, int, int>>&fires, int sizeRow, int sizeColum){

    int i, auxRow, auxColum;

    tuple<int, int, int>tuple1 = make_tuple(rowJoe, columJoe, 1);
    visits[rowJoe][columJoe] = 0;
    queue<tuple<int, int, int>>q;

    for(i = 0; i<fires.size(); i++){

        q.push(fires[i]);
    }
    
    q.push(tuple1);

    while(!q.empty()){

        tuple1 = q.front();
        q.pop();

        if(get<2>(tuple1) == 0){

            for(i = 0; i<4; i++){

                auxRow = get<0>(tuple1) + arrRow[i];
                auxColum = get<1>(tuple1) + arrColum[i];

                if((auxRow > -1 && auxColum >-1) && (auxRow<sizeRow && auxColum < sizeColum) && visits[auxRow][auxColum] == -1 && graph[auxRow][auxColum] != '#'){

                    visits[auxRow][auxColum] = -2;
                    q.push(make_tuple(auxRow, auxColum, 0));
                }
            }
        }

        else{

            if(get<0>(tuple1) == 0 || get<0>(tuple1) == sizeRow-1 || get<1>(tuple1) == 0 || get<1>(tuple1) == sizeColum -1){

                return visits[get<0>(tuple1)][get<1>(tuple1)] + 1;
            }

            for(i = 0; i<4; i++){

                auxRow = get<0>(tuple1) + arrRow[i];
                auxColum = get<1>(tuple1) + arrColum[i];

                if((auxRow > -1 && auxColum >-1) && (auxRow<sizeRow && auxColum < sizeColum) && visits[auxRow][auxColum] == -1 && graph[auxRow][auxColum] == '.'){

                    visits[auxRow][auxColum] = visits[get<0>(tuple1)][get<1>(tuple1)] + 1;
                    q.push(make_tuple(auxRow, auxColum, 1));
                }
            }   
        }
    }

    return -1;
}
int main(){

    int cases, row, colum,n, m, rowFire, columFire, rowJoe, columJoe, ans;

    scanf("%i", &cases);

    while(cases--){
        
        scanf("%i %i", &row, &colum);
        vector<tuple<int, int, int>>fires;

        for(n = 0; n<row; n++){

            cin.ignore();

            for(m = 0; m<colum; m++){
                
                scanf("%c", &graph[n][m]);
                visits[n][m] = -1;

                if(graph[n][m] == 'J'){

                    rowJoe = n;
                    columJoe = m;
                }

                if(graph[n][m] == 'F'){

                    fires.push_back(make_tuple(n, m, 0));
                }
            }
        }

        ans = bfs(rowJoe, columJoe, fires, row, colum);

        if(ans != -1){

            printf("%i\n", ans);
        }

        else{

            printf("IMPOSSIBLE\n");
        }
        
    }
    return 0;
}
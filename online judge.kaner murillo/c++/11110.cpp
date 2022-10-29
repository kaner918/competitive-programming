//https://onlinejudge.org/external/111/11110.pdf
//11110

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int graph[100][100], visits[100][100], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

void dfs(int row, int colum, int size){

    visits[row][colum] = 1;

    int i, auxRow, auxColum;

    for(i = 0; i<4; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum > -1) && (auxRow < size && auxColum < size) && graph[row][colum] == graph[auxRow][auxColum] && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, size);
        }
    }

}

int main(){

    int size, n, m, i, x;
    bool ans;

    while(scanf("%i", &size) && size !=  0){

        ans = true;
        map<int, bool>comp;

        for(n = 0; n<size; n++){

            comp[n+1] = false;

            for(m = 0; m<size; m++){

                graph[n][m] = size;
                visits[n][m] = 0;
            }
        }

        for(i = 1; i<size; i++){

            for(x = 0; x<size; x++){
                
                scanf("%i %i", &n, &m);
                graph[n-1][m-1] = i;

            }
        }

        for(n = 0; n<size && ans; n++){

            for(m = 0; m<size && ans; m++){

                if(visits[n][m] == 0){
                    
                    if(comp[graph[n][m]] == false){

                        dfs(n, m, size);
                        comp[graph[n][m]] = true;
                    } 

                    else{

                        ans = false;
                    }
                }
            }
        }

        if(ans){

            printf("good\n");
        }

        else{

            printf("wrong\n");
        }
    }

    return 0;
}

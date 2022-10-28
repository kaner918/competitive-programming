//https://onlinejudge.org/external/109/10946.pdf
//10946

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char graph[50][50];
int visits[50][50], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

bool compare(pair<char, int>&tuple1, pair<char, int>&tuple2){

    if(tuple1.second == tuple2.second){

        return tuple1.first < tuple2.first;
    }

    return tuple1.second > tuple2.second;

}

void dfs (int row, int colum, int sizeRow,  int sizeColum, pair<char, int>&tuple1){

    int i, auxRow, auxColum;
    visits[row][colum] = 1;
    tuple1.second+=1;

    for(i = 0; i<4; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum >-1) && (auxRow < sizeRow && auxColum < sizeColum) && graph[auxRow][auxColum] == tuple1.first && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, sizeRow, sizeColum, tuple1);

        }
    }
}

int main(){

    int row, colum, n, m, counter = 1;
    pair<char, int>tuple1;

    while(scanf("%i %i", &row, &colum) && (row != 0 || colum != 0)){

        vector<pair<char, int>>res;

        for(n = 0; n<row; n++){

            cin.ignore();

            for(m = 0; m<colum; m++){

                scanf("%c", &graph[n][m]);
                visits[n][m] = 0;

            }
        }  

        for(n = 0; n<row; n++){

            for(m = 0; m<colum; m++){

                if(graph[n][m] != '.' && visits[n][m] == 0){

                    tuple1 = make_pair(graph[n][m], 0);
                    dfs(n, m, row, colum, tuple1);

                    res.push_back(tuple1);
                }
            }
        }

        sort(res.begin(), res.end(), compare);
        printf("Problem %i:\n", counter);
        counter+=1;

        for(n = 0; n<res.size(); n++){

            printf("%c %i\n", res[n].first, res[n].second);

        }
    }

    return 0;
}
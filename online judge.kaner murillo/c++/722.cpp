//https://onlinejudge.org/external/7/722.pdf
//722

#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int counter;
int arrRow[] = {0, -1, 0, 1}, arrColum[] = {-1, 0, 1, 0};

void dfs(int row, int colum, vector<string>&iGrafo, vector<vector<int>>&visits){

    visits[row][colum] = 1;

    int i, auxRow, auxColum;

    for(i = 0; i<4; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum > -1) && (auxRow < iGrafo.size() && auxColum < iGrafo[0].size()) && iGrafo[auxRow][auxColum] == '0' && visits[auxRow][auxColum] == 0){

            counter+=1;
            dfs(auxRow, auxColum, iGrafo, visits);
        }
    }
}

int main(){

    int cases, i, n, row, colum;
    string cad;

    scanf("%i\n", &cases);

    while(cases--){

        getline(cin, cad);
        stringstream stk(cad);

        stk>>row;
        stk>>colum;

        vector<string>iGrafo;
        vector<vector<int>>visits;

        while(getline(cin, cad) && cad != ""){

            iGrafo.push_back(cad);
            visits.push_back(vector<int>(cad.length(), 0));
        }

        counter = 1;
        dfs(row-1, colum-1, iGrafo, visits);

        printf("%i\n", counter);

        if(cases>0){

            printf("\n");
        }
    }   

    return 0;
}
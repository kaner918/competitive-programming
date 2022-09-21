//https://onlinejudge.org/external/4/469.pdf
//469

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
//#include<queue>

using namespace std;

//movements
int arrRow[] = {-1, -1, -1, 0, 1, 1, 1, 0}, arrColum[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int counter, cases2 = 0;

void dfs(int row, int colum, vector<string>&iGrafo, vector<vector<int>>&visits){

    visits[row][colum] = 1;
    int i, auxRow, auxColum;

    for(i = 0; i<8; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow >-1 && auxColum >-1) && (auxRow < iGrafo.size() && auxColum < iGrafo[0].length()) && iGrafo[auxRow][auxColum] == 'W' && visits[auxRow][auxColum] == 0){

            counter+=1;

            dfs(auxRow, auxColum, iGrafo, visits);
        }
    }
}

int main(){

    int cases, row, colum, i, n;
    string cad;

    scanf("%i\n", &cases);
  
    for(i = 1; i<cases+1; i++){

        vector<string>iGrafo;
        vector<vector<int>>visits;

        while(getline(cin, cad) && (cad[0] == 'L' || cad[0] == 'W')){

            iGrafo.push_back(cad);

            visits.push_back(vector<int>(cad.length(), 0));
        }

        stringstream stk(cad);
        counter = 1;
        stk>>row;
        stk>>colum;

        dfs(row-1, colum-1, iGrafo, visits);
        printf("%i\n", counter);

        while(getline(cin, cad) && cad != ""){
            
            vector<vector<int>>visits;

            for(n = 0; n<iGrafo.size(); n++){

                visits.push_back(vector<int>(iGrafo[0].length(), 0));
            }

            stringstream stk(cad);
            counter = 1;
            stk>>row;
            stk>>colum;

            dfs(row-1, colum-1, iGrafo, visits);

            printf("%i\n", counter);

        }

        if(i<cases){
            printf("\n");
        }
    }

    return 0;
}
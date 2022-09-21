//https://onlinejudge.org/external/2/260.pdf
//260

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int arrRow[] = {-1, -1, 0, 0, 1, 1}, arrColum[] = {-1, 0, -1, 1, 0, 1};
bool flag;

void dfs(int row, int colum, vector<string>&iGrafo, vector<vector<int>>&visits){

    visits[row][colum] = 1;

    if(row == iGrafo.size()-1){

        flag = true;
    }

    else{

        int i, auxRow, auxColum;

        for(i = 0; i<6;  i++){

            auxRow = row + arrRow[i];
            auxColum = colum + arrColum[i];

            if((auxRow > -1 && auxColum > -1) && (auxRow<iGrafo.size() && auxColum<iGrafo.size()) && iGrafo[auxRow][auxColum] == 'b' && visits[auxRow][auxColum] == 0){

                dfs(auxRow, auxColum, iGrafo, visits);
            }
        }   
    }
}

int main(){

    int cases = 1, size, i, n, ans; 
    string cad;

    while(scanf("%i", &size) && size != 0){

        vector<string>iGrafo;
        flag = false;
        cin.ignore();

        for(i = 0; i<size; i++){

            getline(cin, cad);
            iGrafo.push_back(cad);
        }

        i = 0;

        while(flag == false && i<size){

            vector<vector<int>>visits;

            for(n = 0; n<size; n++){

                visits.push_back(vector<int>(size, 0));
            }

            if(iGrafo[0][i] == 'b'){

                dfs(0, i, iGrafo, visits);
            }

            i+=1;
        }

        if(flag){

            printf("%i B\n", cases);

        }

        else{

            printf("%i W\n", cases);
        }

        cases+=1;
    }
    
    return 0;
}
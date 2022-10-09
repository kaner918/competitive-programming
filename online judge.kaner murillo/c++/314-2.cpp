//https://onlinejudge.org/external/3/314.pdf
//314

#include<vector>
#include<cstdio>
#include<iostream>
#include<set>
#include<tuple>
#include<queue>
#include<algorithm>

using namespace std;

int arrRow[] = {-1, 1, 0, 0}, arrColum[] = {0, 0, -1, 1},
matrixSums[4][4] = {{0,2, 3, 1}, {1, 2, 3, 0}, {2, 0, 1, 3}, {3, 0, 1, 2}};

int bfs(int row, int colum, int orientation, int rowFinish, int columFinish, vector<vector<int>>&iGrafo, vector<vector<vector<int>>>&visits){

    tuple<int, int, int>tuple1 = make_tuple(row, colum, orientation);
    queue<tuple<int, int, int>>q;

    q.push(tuple1);
    visits[row][colum][0] = 0;
    visits[row][colum][1] = 0;
    visits[row][colum][2] = 0;
    visits[row][colum][3] = 0;

    int auxRow, auxColum, i, n;

    while(!q.empty()){

        tuple1 = q.front();
        cout<< get<0>(tuple1)<<" "<<get<1>(tuple1)<<endl;
        q.pop();

        for(i = 0; i<4; i++){

            if(get<2>(tuple1) == matrixSums[get<2>(tuple1)][i]){

                for(n = 1; n<4; n++){

                    auxRow = get<0>(tuple1) + (arrRow[i] * n);
                    auxColum = get<1>(tuple1) + (arrColum[i] * n);

                    if((auxRow>-1 && auxColum>-1) && (auxRow<iGrafo.size()-1 && auxColum<iGrafo[0].size()-1) && (iGrafo[auxRow][auxColum] != 1 && iGrafo[auxRow+1][auxColum]!= 1 && iGrafo[auxRow][auxColum+1]!=1 && iGrafo[auxRow+1][auxColum+1]!=1) && visits[auxRow][auxColum][i] == -1){

                        q.push(make_tuple(auxRow, auxColum,  matrixSums[get<2>(tuple1)][i]));
                        visits[auxRow][auxColum][i] = visits[get<0>(tuple1)][get<1>(tuple1)][i]+1;
                        cout<<"yes"<<endl;

                    }
                }
            }
            
            else if(get<2>(tuple1) != matrixSums[get<2>(tuple1)][i] && (auxRow>-1 && auxColum>-1) && (auxRow<iGrafo.size()-1 && auxColum<iGrafo[0].size()-1) && (iGrafo[auxRow][auxColum] != 1 && iGrafo[auxRow+1][auxColum]!= 1 && iGrafo[auxRow][auxColum+1]!=1 && iGrafo[auxRow+1][auxColum+1]!=1) && visits[auxRow][auxColum][i] == -1){

                    q.push(make_tuple(get<0>(tuple1), get<1>(tuple1), matrixSums[get<2>(tuple1)][i]));
                    //visits[get<0>(tuple1)][get<1>(tuple1)][i] = visits[get<0>(tuple1)][get<1>(tuple1)][i]+1;
            }
        }
    }

    return -1;
}

int main(){

    int row, colum, i, n, number, rowIni, columIni, rowFinish, columFinish, orientation;
    string cadOrientation;

    while(scanf("%i %i", &row, &colum) && (row!= 0 || colum != 0)){

        vector<vector<int>>iGrafo;
        vector<vector<vector<int>>>visits;

        for(i = 0; i<row; i++){

            vector<int>vec;
            vector<vector<int>>vec1;

            for(n = 0; n<colum; n++){
                
                scanf("%i", &number);

                vec.push_back(number);
                vec1.push_back(vector<int>(4, -1));
            }

            iGrafo.push_back(vec);
            visits.push_back(vec1);
        }

        cin>>rowIni>>columIni>>rowFinish>>columFinish>>cadOrientation;
        
        if(cadOrientation == "south"){
            orientation = 1;           
    
        }

        else if(cadOrientation == "north"){

            orientation = 0;
        }

        else if(cadOrientation == "east"){

            orientation = 2;
        }

        else{

            orientation = 3;
        }

        bfs(rowIni-1, columIni-1, orientation, rowFinish-1, columFinish-1, iGrafo, visits);

        for(i = 0; i<iGrafo.size(); i++){

            for(n = 0; n<iGrafo[0].size(); n++){
                
                cout<<iGrafo[i][n]<<" ";
            }

            cout<<endl;
        }
    }

    return 0;
}
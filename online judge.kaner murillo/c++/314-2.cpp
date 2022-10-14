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

int arrRow[] = {-1, 1, 0, 0}, arrColum[] = {0, 0, -1, 1}, arrRotation[] = {1, -1};

int bfs(int row, int colum, int orientation, int rowFinish, int columFinish, vector<vector<int>>&iGrafo, vector<vector<vector<int>>>&visits){

    tuple<int, int, int>tuple1 = make_tuple(row, colum, orientation);
    queue<tuple<int, int, int>>q;

    q.push(tuple1);

    int auxRow, auxColum, i, n, auxRotation1, auxRotation2;

    while(!q.empty()){

        tuple1 = q.front();
        //cout<< get<0>(tuple1)<<" "<<get<1>(tuple1)<<endl;
        cout<<get<2>(tuple1)<<endl;
        q.pop();

        auxRow = get<0>(tuple1) + (arrRow[get<2>(tuple1)]);
        auxColum = get<1>(tuple1) + (arrColum[get<2>(tuple1)]);

        if((auxRow>-1 && auxColum>-1) && (auxRow<iGrafo.size()-1 && auxColum<iGrafo[0].size()-1) && (iGrafo[auxRow][auxColum] != 1 && iGrafo[auxRow+1][auxColum]!= 1 && iGrafo[auxRow][auxColum+1]!=1 && iGrafo[auxRow+1][auxColum+1]!=1) && visits[auxRow][auxColum][get<2>(tuple1)] == -1){

            q.push(make_tuple(auxRow, auxColum, get<2>(tuple1)));++

            visits[auxRow][auxColum][get<2>(tuple1)] = visits[get<0>(tuple1)][get<1>(tuple1)][get<2>(tuple1)]+1;

        }

        auxRotation1 = get<2>(tuple1) + 1;
        auxRotation2 = get<2>(tuple1) - 1;

        if(auxRotation1>3){

            auxRotation1 = 0;
        } 

        if(auxRotation2<0){

            auxRotation2 = 3;
        }

        if(visits[get<0>(tuple1)][get<1>(tuple1)][auxRotation1] == -1){

            q.push(make_tuple(get<0>(tuple1), get<1>(tuple1), auxRotation1));
            //visits[get<0>(tuple1)][get<1>(tuple1)][auxRotation1] == 1;

        }

        if(visits[get<0>(tuple1)][get<1>(tuple1)][auxRotation2] == -1){

            q.push(make_tuple(get<0>(tuple1), get<1>(tuple1), auxRotation2));
            //visits[get<0>(tuple1)][get<1>(tuple1)][auxRotation2] == 1;

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
            visits[rowIni-1][columIni-1][1] = 0;
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
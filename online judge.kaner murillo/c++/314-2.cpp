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

int arrRow[] = {-1, 0, 1, 0}, arrColum[] = {0, 1, 0, -1}, arrRotation[] = {0, 1, -1};

int bfs(int row, int colum, int orientation, int rowFinish, int columFinish, vector<vector<int>>&iGrafo, vector<vector<vector<int>>>&visits){

    tuple<int, int, int>tuple1 = make_tuple(row, colum, orientation);
    queue<tuple<int, int, int>>q;
    bool ans;

    visits[row][colum][orientation] = 0;

    q.push(tuple1);

    int auxRow, auxColum, i, n, auxRotation, can;

    while(!q.empty()){

        tuple1 = q.front();
        
        if(get<0>(tuple1) == rowFinish && get<1>(tuple1) == columFinish){

            return visits[get<0>(tuple1)][get<1>(tuple1)][get<2>(tuple1)];
        }

        q.pop();

        for(i = 0; i<3; i++){
                    
            auxRotation = get<2>(tuple1) + arrRotation[i];
            
            if(auxRotation==4){

                auxRotation = 0;
            }    

            else if(auxRotation==-1){

                auxRotation = 3;
            }

            can = 0;

            for(n = 1; n<4; n++){

                auxRow = get<0>(tuple1) + (arrRow[auxRotation] * n);
                auxColum = get<1>(tuple1) + (arrColum[auxRotation] * n);
                
                ans = false;

                if(n == 3 && auxRow<iGrafo.size()-1 && auxColum<iGrafo[0].size()-1 && (iGrafo[auxRow][auxColum] != 1 && iGrafo[auxRow+1][auxColum]!= 1 && iGrafo[auxRow][auxColum+1]!=1 && iGrafo[auxRow+1][auxColum+1]!=1) && can==2){

                    ans = true;

                }

                else if(n < 3 && auxRow<iGrafo.size()-1 && auxColum<iGrafo[0].size()-1 && (iGrafo[auxRow][auxColum] != 1 && iGrafo[auxRow+1][auxColum]!= 1 && iGrafo[auxRow][auxColum+1]!=1 && iGrafo[auxRow+1][auxColum+1]!=1)){

                    can+=1;
                    ans = true;
                    
                }

                if(i == 0 && (auxRow>-1 && auxColum>-1) && (ans) && visits[auxRow][auxColum][auxRotation] == -1){
                    
                        q.push(make_tuple(auxRow, auxColum, auxRotation));
                        visits[auxRow][auxColum][auxRotation] = visits[get<0>(tuple1)][get<1>(tuple1)][get<2>(tuple1)] + 1;

                }

                else if(visits[get<0>(tuple1)][get<1>(tuple1)][auxRotation] == -1){

                    q.push(make_tuple(get<0>(tuple1), get<1>(tuple1), auxRotation));
                    visits[get<0>(tuple1)][get<1>(tuple1)][auxRotation] = visits[get<0>(tuple1)][get<1>(tuple1)][get<2>(tuple1)] + 1;
                }
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
            orientation = 2;           
            visits[rowIni-1][columIni-1][2] = 0;
        }

        else if(cadOrientation == "north"){


            orientation = 0;
            visits[rowIni-1][columIni-1][0] = 0;
        }

        else if(cadOrientation == "east"){

            orientation = 1;
            visits[rowIni-1][columIni-1][1] = 0;
        }

        else{

            orientation = 3;
            visits[rowIni-1][columIni-1][3] = 0;
        }

        cout<<bfs(rowIni-1, columIni-1, orientation, rowFinish-1, columFinish-1, iGrafo, visits)<<endl;
    }

    return 0;
}
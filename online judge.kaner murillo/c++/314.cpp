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

int matrixMovements[4][24] = {{-1, 0, -2, 0, -3, 0, 0, 1, 0, 2, 0, 3, 0, -1, 0, -2, 0, -3, 1, 0, 2, 0, 3, 0}, {1, 0, 2, 0, 3, 0, 0, 1, 0, 2, 0, 3, 0, -1, 0, -2, 0, -3, -1, 0, -2, 0, -3, 0}, {0, 1, 0, 2, 0, 3, -1, 0, -2, 0, -3, 0, 1, 0, 2, 0, 3, 0, 0, -1, 0, -2, 0, -1}, {0, -1, 0, -2, 0, -3, -1, 0, -2, 0, -3, 0, 1, 0, 2, 0, 3, 0, 0, 1, 0, 2, 0, 1}}, 
matrixSums[4][8] = {{0, 1, 2, 2, 3, 2, 1, 3}, {1, 1, 2, 2, 3, 2, 0,3}, {2, 1, 0, 2, 1, 2, 3, 3}, {3, 1, 0, 2, 1, 2, 2, 3}};

struct Node{

    int movement1 = -1;
    int movement2 = -1;
    int movement3 = -1;
};

int bfs(int row, int colum, int orientation, int rowFinish, int columFinish, vector<vector<int>>&iGrafo, vector<vector<Node>>&visits){

    queue<tuple<int, int, int, int>>q;
    bool ans;
    int i, n, auxRow, auxColum, move;
    tuple<int, int, int, int>tuple1 = make_tuple(row, colum, orientation, 0);

    q.push(tuple1);
    visits[row][colum].movement1 = 1;
    visits[row][colum].movement2 = 1;
    visits[row][colum].movement3 = 1;
    
    while(!q.empty()){

        tuple1 = q.front();
        //cout<< get<0>(tuple1)<<" "<<get<1>(tuple1)<<endl;
        q.pop();

        if((get<0>(tuple1) == rowFinish && get<1>(tuple1) == columFinish) /* || (get<0>(tuple1)+1 == rowFinish && get<1>(tuple1) == columFinish) || (get<0>(tuple1) == rowFinish && get<1>(tuple1)+1 == columFinish) || (get<0>(tuple1)+1 == rowFinish && get<1>(tuple1)+1 == columFinish) */){

            return get<3>(tuple1);
        }

        else{

            n = 1;
            move = 1;

            for(i = 1; i<25; i+=2){

                auxRow = get<0>(tuple1) + matrixMovements[get<2>(tuple1)][i-1];
                auxColum = get<1>(tuple1) + matrixMovements[get<2>(tuple1)][i];

                //cout<<move<<" "<<n<<endl;

                if((auxRow>-1 && auxColum>-1) && (auxRow<iGrafo.size()-1 && auxColum<iGrafo[0].size()-1) && (iGrafo[auxRow][auxColum] != 1 && iGrafo[auxRow+1][auxColum]!= 1 && iGrafo[auxRow][auxColum+1]!=1 && iGrafo[auxRow+1][auxColum+1]!=1)){

                    if (move == 1 && visits[auxRow][auxColum].movement1 == -1){
                        
                        q.push(make_tuple(auxRow, auxColum, matrixSums[get<2>(tuple1)][n-1], get<3>(tuple1)+matrixSums[get<2>(tuple1)][n]));
                        visits[auxRow][auxColum].movement1 = 1;
                        //iGrafo[auxRow][auxColum] = 2;

                    }
                    
                    else if (move == 2 && visits[auxRow][auxColum].movement2 == -1){

                        q.push(make_tuple(auxRow, auxColum, matrixSums[get<2>(tuple1)][n-1], get<3>(tuple1)+matrixSums[get<2>(tuple1)][n]));
                        visits[auxRow][auxColum].movement2 = 1;
                        //iGrafo[auxRow][auxColum] = 2;
                    }
                    
                    else if (move == 3 && visits[auxRow][auxColum].movement3 == -1){

                        q.push(make_tuple(auxRow, auxColum, matrixSums[get<2>(tuple1)][n-1], get<3>(tuple1)+matrixSums[get<2>(tuple1)][n]));
                        visits[auxRow][auxColum].movement3 = 1;
                        //iGrafo[auxRow][auxColum] = 3;

                    }
                }     

                if(move == 3){

                    move = 0;
                    n+=2;
                }     

                move+=1;
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
        vector<vector<Node>>visits;

        for(i = 0; i<row; i++){

            vector<int>vec;
            vector<Node>vec1;

            for(n = 0; n<colum; n++){
                
                scanf("%i", &number);

                vec.push_back(number);
                vec1.push_back(Node());
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

        cout<<bfs(rowIni-1, columIni-1, orientation, rowFinish-1, columFinish-1, iGrafo, visits)<<endl;

        for(i = 0; i<iGrafo.size(); i++){

            for(n = 0; n<iGrafo[0].size(); n++){
                
                cout<<iGrafo[i][n]<<" ";
            }

            cout<<endl;
        }
    }

    return 0;
}
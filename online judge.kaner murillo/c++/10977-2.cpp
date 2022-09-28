//https://onlinejudge.org/external/109/10977.pdf
//10977

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cmath>

using namespace std;

float distance(float x1, float y1, float x2, float y2){

    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int arrRow[] = {0, -1, 0, 1}, arrColum[] = {-1, 0, 1, 0};

void moster(int row, int colum, int ttl, float minorDistance, vector<vector<int>>&iGrafo, vector<vector<int>>&visits){

    visits[row][colum] = 1;
    iGrafo[row][colum] = 1;
    queue<tuple<int, int>>q;
    tuple<int, int>level = make_tuple(-1, -1);
    tuple<int, int>aux = make_tuple(row, colum);
    int i, auxRow, auxColum;

    q.push(aux);
    q.push(level);

    while(!q.empty() && ttl > 0){

        aux = q.front();
        q.pop();

        for(i = 0; i<4; i++){

            auxRow = get<0>(aux) + arrRow[i];
            auxColum = get<1>(aux) + arrColum[i];

            //cout<<auxRow<<endl;
            //cout<<auxColum<<endl;

            if((auxRow > -1 && auxColum > -1) && (auxRow<iGrafo.size() && auxColum<iGrafo[0].size()) && visits[auxRow][auxColum] == 0 && distance(row, colum, auxRow, auxColum) <= minorDistance){
    
                visits[auxRow][auxColum] = 1;
                iGrafo[auxRow][auxColum] = 1;
                q.push(make_tuple(auxRow, auxColum));
            }
        }
    }
}

int bfs(int row, int colum, vector<vector<int>>&iGrafo, vector<vector<int>>&visits){

    queue<tuple<int, int>>q;
    tuple<int, int>tuple1;
    int i, auxRow, auxColum;
    bool ans = false;
    q.push(make_tuple(row, colum));

    if(iGrafo[row][colum] == 0){

        visits[row][colum] = 0;

        while(!q.empty() && ans == false){

            tuple1 = q.front();
            q.pop();

            //cout<<get<0>(tuple1)<<" "<<get<1>(tuple1)<<endl;

            if(get<0>(tuple1) == iGrafo.size()-1 && get<1>(tuple1) == iGrafo[0].size()-1){

                return visits[get<0>(tuple1)][get<1>(tuple1)];
                ans = true;
            }

            else{

                for(i = 0; i<4; i++){

                    auxRow = get<0>(tuple1) + arrRow[i];
                    auxColum = get<1>(tuple1) + arrColum[i];

                    //cout<<auxRow<<endl;
                    //cout<<auxColum<<endl;

                    if((auxRow > -1 && auxColum > -1) && (auxRow<iGrafo.size() && auxColum<iGrafo[0].size()) && iGrafo[auxRow][auxColum] == 0 && visits[auxRow][auxColum] == -1){
            
                        visits[auxRow][auxColum] = visits[get<0>(tuple1)][get<1>(tuple1)]+1;
                        q.push(make_tuple(auxRow, auxColum));
                    }
                }
            }
        } 
    }

    return -1;
}   

int main(){

    int rows, colums, rowNone, columNone, limitRow, limitColum, area, nones, i, n, monsters, res;
    
    while(scanf("%i %i", &rows, &colums) && rows!=0 || colums!=0){

        scanf("%i", &nones);

        vector<vector<int>>iGrafo;
        vector<vector<int>>visits;
        vector<vector<int>>visits2;

        for(i = 0; i<rows; i++){

            iGrafo.push_back(vector<int>(colums, 0));
            visits2.push_back(vector<int>(colums, 0));
            visits.push_back(vector<int>(colums, -1));

        }

        while(nones--){

            scanf("%i %i", &rowNone, &columNone);

            iGrafo[rowNone-1][columNone-1] = 1;
        }        

        scanf("%i", &monsters);

        while(monsters--){

            vector<vector<int>>visits2;

            for(i = 0; i<rows; i++){

                visits2.push_back(vector<int>(colums, 0));

            }

            scanf("%i %i %i", &limitRow, &limitColum, &area);
            moster(limitRow-1, limitColum-1, distance(limitRow, limitColum, limitRow+area, limitColum), area, iGrafo, visits2);

        }

        res = bfs(0, 0, iGrafo, visits);

        if(res == -1){

            printf("Impossible.\n");
        }

        else{

            printf("%i\n", res);
        }
    }

    return 0;
}
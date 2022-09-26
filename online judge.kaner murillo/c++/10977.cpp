//https://onlinejudge.org/external/109/10977.pdf
//10977

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<set>

using namespace std;

int arrRow[] = {0, -1, 0, 1}, arrColum[] = {-1, 0, 1, 0}, arrRow2[] = {-1, -1, -1, 0, 1, 1, 1, 0}, arrColum2[] = {-1, 0, 1, 1, 1, 0, -1, -1} ,min;

void moster(int row, int colum, int ttl, vector<vector<int>>&iGrafo, vector<vector<int>>&visits){

    visits[row][colum] = 1;
    iGrafo[row][colum] = 1;
    queue<vector<int>>q;
    vector<int>level = {-1, -1};
    vector<int>aux = {row, colum};
    int i, auxRow, auxColum;

    q.push(aux);
    q.push(level);

    while(!q.empty() && ttl > 1){

        aux = q.front();
        q.pop();

        if(aux[0] < 0){
            
            q.push(level);
            ttl-=1;
        }

        else{

            for(i = 0; i<8; i++){

                auxRow = aux[0] + arrRow2[i];
                auxColum = aux[1] + arrColum2[i];

                //cout<<auxRow<<endl;
                //cout<<auxColum<<endl;

                if((auxRow > -1 && auxColum > -1) && (auxRow<iGrafo.size() && auxColum<iGrafo[0].size()) && visits[auxRow][auxColum] == 0){
        
                    visits[auxRow][auxColum] = 1;
                    iGrafo[auxRow][auxColum] = 1;
                    vector<int>aux2 = {auxRow, auxColum};
                    q.push(aux2);
                }
            }
        }

    }
}

void bfs(tuple<int, int, int>tuple1, vector<vector<int>>&iGrafo, set<tuple<int, int, int>>&visits, int limitRow, int limitColum, int area){

    queue<tuple<int, int, int>>q;
    set<tuple<int, int, int>>::iterator it;
    int i, auxRow, auxColum;

    q.push(tuple1);
    visits.insert(tuple1);

    while(!q.empty()){

        tuple1 = q.front();
        q.pop();

        if(get<0>(tuple1) == iGrafo.size()-1 && get<1>(tuple1) == iGrafo[0].size()-1){

            cout<<get<2>(tuple1)<<endl;
        }

        else{

            for(i = 0; i<4; i++){

                auxRow = get<0>(tuple1) + arrRow[i];
                auxColum = get<1>(tuple1) + arrColum[i];

                //cout<<auxRow<<endl;
                //cout<<auxColum<<endl;

                for(it = visits.begin(); it!=visits.end() && (get<0>(*it)!=auxRow || get<1>(*it) != auxColum); it++);

                if((auxRow > -1 && auxColum > -1) && (auxRow<iGrafo.size() && auxColum<iGrafo[0].size()) && iGrafo[auxRow][auxColum] == 0 && it==visits.end()){
        
                    visits.insert(make_tuple(auxRow, auxColum, get<2>(tuple1)+1));
                    q.push(make_tuple(auxRow, auxColum, get<2>(tuple1)+1));
                }
            }
        }
    } 

}

int main(){

    int rows, colums, rowNone, columNone, limitRow, limitColum, area, nones, i, n, monsters;
    
    while(scanf("%i %i", &rows, &colums) && rows!=0 || colums!=0){

        scanf("%i", &nones);

        vector<vector<int>>iGrafo;
        set<tuple<int, int, int>>visits;
        vector<vector<int>>visits2;

        for(i = 0; i<rows; i++){

            iGrafo.push_back(vector<int>(colums, 0));
            visits2.push_back(vector<int>(colums, 0));

        }

        while(nones--){

            scanf("%i %i", &rowNone, &columNone);

            iGrafo[rowNone-1][columNone-1] = 1;
        }        

        scanf("%i", &monsters);

        while(monsters--){

            scanf("%i %i %i", &limitRow, &limitColum, &area);
            //moster(limitRow-1, limitColum-1, area, iGrafo, visits2);

            if((limitColum-1) - area > -1){

                iGrafo[limitRow-1][(limitColum-1) - area] = 1;
            }

            if((limitColum-1) + area < iGrafo[0].size()){

                iGrafo[limitRow-1][(limitColum-1) + area] = 1;
            }

            if((limitRow-1) - area > -1){

                iGrafo[(limitRow-1) - area][limitColum-1] = 1;
            }

            if((limitRow-1) + area < iGrafo.size()){

                iGrafo[(limitRow-1) + area][limitColum-1] = 1;
            }
        }
        
        tuple<int, int, int>tu = make_tuple(0, 0, 0);

        //bfs(tu, iGrafo, visits, limitRow, limitColum, area);

        /*for(i = 0; i<iGrafo.size(); i++){

            for(n = 0; n<iGrafo[0].size(); n++){

                cout<<iGrafo[i][n]<<" ";
            }

            printf("\n");
        }*/
    }

    return 0;
}
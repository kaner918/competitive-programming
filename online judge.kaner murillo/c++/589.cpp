//https://onlinejudge.org/external/5/589.pdf
//589

#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<tuple>

using namespace std;

char graph[21][21], playedOrientation[] = {'s', 'w', 'n', 'e'}, boxOrientation[] = {'S', 'W', 'N', 'E'};
int arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

struct State{

    int coste, coste2, rowPosition, columPosition, rowBox, columBox;
    string res;
    
    State(){}
    State(int coste, int coste2, int rowPosition, int columPosition, int rowBox, int columBox, string res){

        this->coste = coste;
        this->coste2 = coste2;
        this->rowPosition = rowPosition;
        this->columPosition = columPosition;
        this->rowBox = rowBox;
        this->columBox = columBox;
        this->res = res;
    }

    bool operator<(const State&other)const{

        if(coste == other.coste){

            return coste2 > other.coste2;
        }
        return coste > other.coste;
    }
};                                      

string dijkstra(int r, int c, int rowPlayed, int columPlayed, int rowBox, int columBox, int rowT, int columT){

    set<tuple<int, int, int, int>>conj;
    priority_queue<State>q;

    int i, auxRow, auxColum, coste2, auxBoxR, auxBoxC, coste, orientation;
    bool stateBox;
    string res, auxRes;
    tuple<int, int, int, int>aux = make_tuple(rowPlayed, columPlayed, rowBox, columBox);

    q.push(State(0, 0, rowPlayed, columPlayed, rowBox, columBox, ""));
    conj.insert(aux);

    while(!q.empty()){

        coste = q.top().coste;
        coste2 = q.top().coste2;
        rowPlayed = q.top().rowPosition;
        columPlayed = q.top().columPosition;
        rowBox = q.top().rowBox;
        columBox = q.top().columBox;
        res = q.top().res;

        if(rowBox == rowT && columBox == columT){

            return res; 
        }

        q.pop();

        for(i = 0; i<4; i++){

            auxRow = arrRow[i] + rowPlayed;
            auxColum = arrColum[i] + columPlayed;
            auxBoxR = rowBox + arrRow[i];
            auxBoxC = columBox + arrColum[i];

            if(auxRow == rowBox && auxColum == columBox &&  auxBoxR > -1 &&  auxBoxC > -1 && auxBoxR < r && auxBoxC < c && graph[auxBoxR][auxBoxC] != '#'){
                
                aux = make_tuple(auxRow, auxColum, auxBoxR, auxBoxC);
                auto it = conj.find(aux);

                if(it == conj.end()){

                    conj.insert(aux);
                    q.push(State(coste + 1, coste2, auxRow, auxColum, auxBoxR, auxBoxC, res+boxOrientation[i]));
                }
            }

            if((auxRow != rowBox || auxColum != columBox) && auxRow > -1 &&  auxColum > -1 && auxRow < r && auxColum < c && graph[auxRow][auxColum] != '#'){         
                
                aux = make_tuple(auxRow, auxColum, rowBox, columBox);
                auto it = conj.find(aux);

                if(it == conj.end()){

                    conj.insert(aux);
                    q.push(State(coste, coste2 + 1, auxRow, auxColum, rowBox, columBox, res+playedOrientation[i]));
                }              
            }
        }
    }

    return "Impossible.";
}

int main(){

    int counter = 1, r, c, i, n, rowPlayed, columPlayed, rowBox, columBox, rowT, columT;

    while(scanf("%i %i", &r, &c) && (r || c)){

        for(i = 0; i<r; i++){
            
            cin.ignore();

            for(n = 0; n<c; n++){

                scanf("%c", &graph[i][n]);
                if(graph[i][n] == 'S'){
                    rowPlayed = i;
                    columPlayed = n;
                }

                else if(graph[i][n] == 'T'){
                    rowT = i;
                    columT = n;
                }

                else if(graph[i][n] == 'B'){
                    rowBox = i;
                    columBox = n;
                }
            }
        }    

        cin.ignore();    

        cout<<"Maze #"<<counter++<<endl<<dijkstra(r, c, rowPlayed, columPlayed, rowBox, columBox, rowT, columT)<<endl<<endl;
    }

    return 0;
}
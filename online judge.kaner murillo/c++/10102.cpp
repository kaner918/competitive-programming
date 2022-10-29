//https://onlinejudge.org/external/101/10102.pdf
//10102

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};

int bfs(int row, int colum, vector<string>&graph, vector<vector<int>>visits){

    queue<pair<int, int>>q;
    visits[row][colum] = 0;

    pair<int, int>aux = make_pair(row, colum);
    q.push(aux);

    int i, auxRow, auxColum;

    while(!q.empty()){


        aux = q.front();
        q.pop();

        if(graph[aux.first][aux.second] == '3'){

            return visits[aux.first][aux.second];
        }

        for(i = 0; i<4; i++){

            auxRow = aux.first + arrRow[i];
            auxColum = aux.second + arrColum[i];

            if((auxRow > -1 && auxColum > -1) && (auxRow < graph.size() && auxColum < graph.size()) && visits[auxRow][auxColum] == -1){

                visits[auxRow][auxColum] = visits[aux.first][aux.second] + 1; 
                q.push(make_pair(auxRow, auxColum));
            }
        }
    }
}

int main(){

    int size, n, m, higer, sum;
    string cad;

    while(scanf("%i", &size) != EOF){

        vector<string>graph;
        vector<vector<int>>visits;
        cin.ignore();

        for(n = 0; n<size; n++){

            getline(cin, cad);
            graph.push_back(cad);
            visits.push_back(vector<int>(size, -1));
        }

        higer = 0;

        for(n = 0; n<graph.size(); n++){

            for(m = 0; m<graph.size(); m++){

                if(graph[n][m] == '1'){

                    sum = bfs(n, m, graph, visits);

                    if(sum > higer){

                        higer = sum;
                    }
                }
            }
        }

        printf("%i\n", higer);
    }

    return 0;
}
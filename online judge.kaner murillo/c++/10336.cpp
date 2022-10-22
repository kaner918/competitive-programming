//https://onlinejudge.org/external/103/10336.pdf
//10336

#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<set>

using namespace std;

struct comp{

    template <typename T>

    bool operator()(const T& l, const T& r) const{

        if(l.second != r.second){

            return l.second > r.second;
        }

        return l.first < r.first;
    }

};

int arrRow[] = {1,0,-1,0}, arrColum[] = {0, -1, 0, 1};

void dfs(int row, int colum, vector<string>&graph, vector<vector<int>>&visits){

    visits[row][colum] = 1;

    int i, auxRow, auxColum;

    for(i = 0; i<4; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow>-1 && auxColum>-1) && (auxRow<graph.size() && auxColum<graph[0].size()) && graph[auxRow][auxColum] == graph[row][colum] && visits[auxRow][auxColum] == 0){

            dfs(auxRow, auxColum, graph, visits);
        }
    }
}

int main(){

    int cases, row, colum, i, n, m;
    string cad;

    scanf("%i", &cases);

    for(i = 1; i<cases+1;i++){

        vector<string>graph;
        vector<vector<int>>visits;
        map<char, int>letters;
        map<char, int>::iterator it;

        scanf("%i %i", &row, &colum);    
        cin.ignore();

        for(n = 0; n<row; n++){

            getline(cin, cad);
            graph.push_back(cad);
            visits.push_back(vector<int>(colum, 0));
        }

        for(n = 0; n<row; n++){

            for(m = 0; m<colum; m++){

                if(visits[n][m] == 0){

                    dfs(n, m, graph, visits);

                    for(it = letters.begin(); it!= letters.end() && it->first != graph[n][m]; it++);

                    if(it != letters.end()){

                        letters[graph[n][m]]+=1;
                    } 

                    else{

                        letters[graph[n][m]] = 1;
                    }
                }
            }
        }                      

        set<pair<char, int>, comp>conj(letters.begin(), letters.end());

        printf("World #%i\n", i);

        for(auto& it : conj){

            printf("%c: %i\n", it.first, it.second);
        }
    }

    return 0;
}
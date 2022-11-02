#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

int arrRow[] = {1, 1, 0, -1, -1, -1, 0, 1}, arrColum[] = {0, -1, -1, -1, 0, 1, 1, 1}, space[203];

int calculation(int n){

    int i, size = 0;

    while(n > 0){
        
        size++;
        n/=10;
    }

    return size;
}

void dfs(int row, int colum, vector<vector<int>>&visits, vector<vector<string>>&graph, int counter){
    
    int i, auxRow, auxColum, auxCounter;

    visits[row][colum] = counter;
    auxCounter = calculation(visits[row][colum]);

    if( auxCounter > space[colum]){

        space[colum] = auxCounter;
    }

    for(i = 0; i<8; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if((auxRow > -1 && auxColum > -1) && (auxRow < graph.size() && auxColum < graph[0].size()) && visits[auxRow][auxColum] == -1 && graph[auxRow][auxColum] == graph[row][colum]){

            dfs(auxRow, auxColum, visits, graph, counter);
        }
    }
}

int main(){

    string cad,letter;
    int n, m, counter, x=4, position;
    
    while(getline(cin, cad)){

        vector<vector<string>>graph;
        vector<vector<int>>visits;
        counter = 1;
        
        do{

            position = 0;
            stringstream stk(cad);
            vector<string>line;
            vector<int>lineAux;

            while(stk>>letter){

                line.push_back(letter);
                lineAux.push_back(-1);
                space[position] = 1;
                position++;
            }

            graph.push_back(line);
            visits.push_back(lineAux);

        }while(getline(cin, cad) && cad!="%");    
        
        for(n = 0; n<graph.size(); n++){

            for(m = 0; m<graph[0].size(); m++){

                if(visits[n][m] == -1){

                    dfs(n, m, visits, graph, counter);
                    counter++;
                }
            }
        }

        for(n = 0; n<graph.size(); n++){

            printf("%*d", space[0], visits[n][0]);

            for(m = 1; m<graph[0].size(); m++){
                
                printf("%*d", space[m]+1, visits[n][m]);
            }

            printf("\n");
        }
        cout<<"%"<<endl;
    }

    return 0;
}
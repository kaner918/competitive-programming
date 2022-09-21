//https://onlinejudge.org/external/119/11902.pdf
//11902
//solucion implementada con puntos de articulacion y puentes de articualaicon.

#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<string>

using namespace std;

void bfs(int i, int none, int f, vector<vector<int>>&grafo, vector<bool>&visits){

    queue<int>cola;
    visits[i] = true;
    cola.push(i);

    while(cola.size() > 0){

        i = cola.front();
        cola.pop();
        //cout<<i<<endl;

        if(i != none && i!= f){

            for(int u = 0; u<grafo.size(); u++){
            
                if(grafo[i][u] == 1 && visits[u] == false && u!=none){

                    visits[u] = true;

                    if(u!= f){
                        cola.push(u);
                    }
                }
            }
        }
    }
}

int main(){

    int cases, size, i, n, m, v;
    string cad, cad2, cad3;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i", &size);
        vector<vector<int>>grafo(size);
        vector<vector<int>>res(size);
        vector<bool>visits2(size, false);

        cin.ignore();
        cad2 = "+";

        for(n = 0; n<(size*2)-1; n++){

            if(n<size){

                getline(cin,cad);
                stringstream stk(cad);
            
                while(stk>>v){

                    grafo[n].push_back(v);
                    res[n].push_back(0);
                }
            }
            cad2+="-";
        }

        cad2+="+";
        bfs(0, 10000000, 10000000, grafo, visits2);
        res[0][0] = 1;

        for(n = 0; n<size; n++){

            vector<bool>visits(size, false);
            bfs(0, n, m, grafo, visits);

            for(m = 0; m<size; m++){

                if(visits[m] == false && visits2[m] == true){

                    res[n][m] = 1;
                }
            }
        }

        printf("Case %i:\n%s\n", i,cad2.c_str());

        for(n = 0; n<size; n++){

            cad3 = "|";

            for(m = 0; m<size; m++){

                if(res[n][m]==1){

                    cad3+="Y|";
                }

                else{

                    cad3+="N|";
                }
            }
            printf("%s\n", cad3.c_str());
            printf("%s\n", cad2.c_str());
        }
    }

    return 0;
}
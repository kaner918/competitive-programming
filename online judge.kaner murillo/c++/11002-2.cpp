//https://onlinejudge.org/external/110/11002.pdf
//11002

#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

int tab[61][31][2501];

int main(){

    int size, val, i, j, k, counter, flag;

    while(scanf("%i", &size) && size){
        flag = 1;
        counter = 0;
        vector<vector<int>>table;
        for(i = 0; i<size*2-1; i++){
            vector<int>aux;
            if(flag){
                counter+=1;
            }
            else{
                counter-=1;
            }
            for(j = 0; j<counter; j++){
                scanf("%i", &val);
                aux.push_back(abs(val)); 
            }

            table.push_back(aux);
            
            if(counter == size){
                flag = 0;
            }
        }   

        tab[0][0][0] = table[0][0];
        tab[0][0][1] = table[0][0];
        tab[0][0][2] = table[0][0];
        tab[0][0][3] = table[0][0];

        for(i = 1; i<size*2-1; i++){
            if(flag){
                counter+=1;
            }
            else{
                counter-=1;
            }
            for(j = 0; j<counter; j++){
                
                if (i <= size){
                    tab[i][j][0] = INT_MAX;
                    tab[i][j][1] = INT_MAX;
                    tab[i][j][2] = INT_MAX;
                    tab[i][j][3] = INT_MAX;

                    if(j < counter-1){

                        tab[i][j][0] = tab[i-1][j][0] + table[i][j];
                        tab[i][j][1] = tab[i-1][j][1] + table[i][j];
                    }

                    if (colum - 1 > -1){

                    }
                }

                else{

                }
            }

            if(counter == size){
                flag = 0;
            }
        }

        printf("%i\n", dp(2*size-1, 0, 0, table));
    }


    return 0;
}
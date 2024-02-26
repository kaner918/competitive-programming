//https://onlinejudge.org/external/110/11002.pdf
//11002

#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

int mem[61][31][2501];

int dp(int row, int colum, int min_sum, vector<vector<int>>&table){

    int ans;
    min_sum = abs(min_sum);

    if(mem[row][colum][min_sum] != INT_MAX-1){
        ans = mem[row][colum][min_sum];
    } 

    else{

        if(!row && !colum){
            ans = min_sum;
        }

        else{

            int left = INT_MAX, right = INT_MAX;

            if (row >= (table.size()+1)/2){

                left = min(dp(row-1, colum, min_sum+table[row-1][colum], table),
                dp(row-1, colum, min_sum-table[row-1][colum], table));

                if (colum+1 < table[row-1].size()){
                    right = min(dp(row-1, colum+1, min_sum+table[row-1][colum+1], table),
                    dp(row-1, colum+1, min_sum-table[row-1][colum+1], table));
                }
            }  

            else{
                if (colum < table[row-1].size()){
                    right = min(dp(row-1, colum, min_sum+table[row-1][colum], table),
                    dp(row-1, colum, min_sum-table[row-1][colum], table));
                }

                if (colum - 1 > -1){
                    left = min(dp(row-1, colum-1, min_sum+table[row-1][colum-1], table),
                    dp(row-1, colum-1, min_sum-table[row-1][colum-1], table));
                }
            }
                

            ans = min(left, right);
        }
        mem[row][colum][min_sum] = ans;
    }
    
    return ans;
}

int main(){

    int size, val, i, j, k, counter, flag;

    while(scanf("%i", &size) && size){
        flag = 1;
        counter = 0;
        vector<vector<int>>table;
        for(i = 0; i<size*2; i++){
            vector<int>aux;
            if(flag){
                counter+=1;
            }
            else{
                counter-=1;
            }
            for(j = 0; j<counter+1; j++){
                if(i<size*2-1 && j<counter){
                    scanf("%i", &val);
                    aux.push_back(abs(val));
                }
                
                for(k = 0; k<2501; k++){
                    mem[i][j][k] = INT_MAX-1;
                }
            }
            
            if(i<size*2-1){
                table.push_back(aux);
            }
            if(counter == size){
                flag = 0;
            }
        }

        printf("%i\n", dp(2*size-1, 0, 0, table));
    }

    return 0;
}
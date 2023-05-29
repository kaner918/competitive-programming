//https://onlinejudge.org/external/109/10957.pdf
//10957

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;
int counter;

bool comp(vector<vector<int>>&doku, int row, int colum, int val){

    int i, j;

    for(i = row-1; i>-1; i--){

        if(doku[i][colum] == val){
            return false;
        }
    }

    for(j = colum-1; j>-1; j--){

        if(doku[row][j] == val){
            return false;
        }
    }

    return true;
}

void solved(vector<vector<int>>&doku, int index, int index2){

    if(counter<2){

        int i, j;

        if(index == 10){

            counter++;
            cout<<endl;
        
            for(i = 0; i<9; i++){
                for(j = 0; j<9; j++){
                    cout<<doku[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        else{
    
            if(index2 == 10){
                index2 = 0;
                index++;
            }

            if(!doku[index][index2]){

                for(i = 1; i<10; i++){

                    doku[index][index2] = i;

                    if(comp(doku, index, index2, i)){

                        solved(doku, index, index2+1);
                    }
                }
            }

            else if(doku[index][index2] && comp(doku, index, index2, doku[index][index2])){

                solved(doku, index, index2+1);
            }
        }
    }
}

int main(){

    int i, n, m, num;
    string line;
    bool flag = true;

    while(getline(cin, line) && flag){
        
        vector<vector<int>>doku(9);
        counter = 0;
        stringstream stk(line);
        while(stk>>num){
            doku[0].push_back(num);
        }

        for(i = 1; i<9; i++){

            getline(cin, line);
            stringstream stk(line);
            while(stk>>num){
                doku[i].push_back(num);
            }
        }

        solved(doku, 0, 0);

        if(!getline(cin, line)){
            flag = false;
        }
    }

    return 0;
}
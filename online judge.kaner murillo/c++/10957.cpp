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

    int i, j, flag = 0;

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

    for(i = row+1; i<9; i++){

        if(doku[i][colum] == val){
            return false;
        }
    }

    for(j = colum+1; j<9; j++){

        if(doku[row][j] == val){
            return false;
        }
    }

    while((colum+1)%3 != 0){
        colum++;
    }
    
    while((row+1)%3 != 0){
        row++;
    }

    for(i = row; ((i+1)%3 != 0 || i == row); i--){

        for(j=colum; ((j+1)%3 != 0 || j == colum); j--){

            if(doku[i][j] == val){
                flag++;
            }

            if(flag == 2){
                return false;
            }
        }
    }
    return true;
}

void solved(vector<vector<int>>&doku, int index, int index2){

    if(counter<2){

        int i, j;

        if(index == 8 && index2 == 9){

            counter++;
        }

        else{
    
            if(index<8 && index2 == 9){
                index2 = 0;
                index++;
            }

            if(!doku[index][index2]){

                for(i = 1; i<10; i++){

                    doku[index][index2] = i;

                    if(comp(doku, index, index2, i)){
                        solved(doku, index, index2+1);
                    }

                    doku[index][index2] = 0;
                }
            }

            else if(doku[index][index2]){
                solved(doku, index, index2+1);
            }
        }
    }
}

int main(){

    int i, n, m, num, counter2 = 1;
    string line;
    bool flag = true, flag2;

    while(getline(cin, line) && flag){
        
        flag2 = true;
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

        for(i = 0; i<9 && flag2; i++){

            for(n = 0; n<9 && flag2; n++){
                if(doku[i][n]){
                    flag2 = comp(doku, i, n, doku[i][n]);
                }
            }
        }

        printf("Case %i: ", counter2++);

        if(!flag2){

            printf("Illegal.\n");
        }

        else{

            solved(doku, 0, 0);

            if(!counter){
                printf("Impossible.\n");
            }
            else if(counter == 1){
                printf("Unique.\n");
            }
            else{
                printf("Ambiguous.\n");
            }
        }

        if(!getline(cin, line)){
            flag = false;
        }
    }

    return 0;
}
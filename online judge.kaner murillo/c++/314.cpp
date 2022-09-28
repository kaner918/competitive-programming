//https://onlinejudge.org/external/3/314.pdf
//314

#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

int arrRow[] = {}, arrColum[]=;

int main(){

    int row, colum, i, n, number, rowIni, columIni, rowFinish, columFinish;
    string orientation;

    while(scanf("%i %i", &row, &colum) && (row!= 0 || colum != 0)){

        vector<vector<int>>iGrafo;

        for(i = 0; i<row; i++){

            vector<int>vec;

            for(n = 0; n<colum; n++){
                
                scanf("%i", &number);

                vec.push_back(number);
            }

            iGrafo.push_back(vec);
        }

        cin>>rowIni>>columIni>>rowFinish>>columFinish>>orientation;

    }

    return 0;
}
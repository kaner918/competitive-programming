//https://onlinejudge.org/external/112/11297.pdf
//11297

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int size;

vector<vector<int>>A(501, vector<int>(501));
vector<vector<int>>tree(501*4, vector<int>(501*4, 0));

int main(){

    int size, consults, i, j;
    char consult;

    scanf("%i", &size);

    for(i = 0; i<size; i++){
        for(j = 0; j<size; j++){
            scanf("%i", &A[i][j]);
        }
    }
    
    scanf("%i", &consults);

    for(i = 0; i<consults; i++){
        cin.ignore();
        scanf("%c", &consult);

        if(consult == 'q'){
            scanf("%i %i %i %i");
        }

        else{
            scanf("%i %i %i");
        }   
    }

    return 0;
}
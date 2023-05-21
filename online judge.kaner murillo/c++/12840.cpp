//https://onlinejudge.org/external/128/12840.pdf
//12840

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int arrows[501], flag, position;
vector<int>res; 

void solved(int index, int limit, int sum, int find, vector<int>&comb){

    if(sum == find){

        if(index<position){

            flag = 1;
            position = index;
            res = comb;
        }
    }

    else{

        if(sum > find || index+1 > position){
            return;
        }

        int i;
        for(i = limit-1; i>-1; i--){

            comb[index] = arrows[i];
            solved(index+1, limit, sum+arrows[i], find, comb);
        }
    }
}

int main(){

    int cases, sizeArrows, points, i, n;

    scanf("%i", &cases);

    for(i = 1; i<= cases; i++){

        scanf("%i %i", &sizeArrows, &points);

        for(n = 0; n<sizeArrows; n++){
            scanf("%i", &arrows[n]);            
        }
        
        flag = 0;
        vector<int>comb(502);
        position = 502;
        solved(0, sizeArrows, 0, points, comb);

        printf("Case %i: ", i);

        if(flag){

            printf("[%i]", position);
            for(n = 0; n<position; n++){
                printf(" %i", res[n]);
            }
            printf("\n");

        }

        else{
            printf("impossible\n");
        }

    }

    return 0;   
}
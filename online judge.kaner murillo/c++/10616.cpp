//https://onlinejudge.org/external/106/10616.pdf
//10616

#include<cstdio>
#include<iostream>

using namespace std;

int nums[201], tab[202][12][22];

int solve(int size_numbers, int d, int m){

    int i, j, k, cal;

    for(i = 1; i<=m; i++){
        for(j = 0; j<=d; j++){
            tab[size_numbers][i][j] = 0;
        }
    }

    for(i = size_numbers-1; i>-1; i--){
        for(j = 0; j<=m; j++){
            for(k = 0; k<d; k++){
                cal = (k+nums[i])%d;
                if(cal<0){
                    cal+=d;
                }
                tab[i][j][k] = tab[i+1][j][k];
                if(j){
                    tab[i][j][k]+= tab[i+1][j-1][cal];
                }
            }
        }
    }
    
    return tab[0][m][0];
}

int main(){ 
    
    int size_numbers, queries, num, i, j, d, m, counter = 1;

    while(scanf("%i %i", &size_numbers, &queries) && size_numbers){
        
        printf("SET %i:\n", counter);
        for(i = 0; i<size_numbers; i++){
            scanf("%i", &nums[i]);
        }   

        for(i = 1; i<queries+1; i++){
            scanf("%i %i", &d, &m);
            tab[size_numbers][0][0] = 1;
            printf("QUERY %i: %i\n", i, solve(size_numbers, d, m));
        }

        counter+=1;
    }

    return 0;
}
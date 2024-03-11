//https://onlinejudge.org/external/106/10688.pdf
//10688

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int tab[502][502];

int main(){

    int cases, j, m, x, l, i, k, apples, index, mini;
    
    tab[1][0] = 0;
    scanf("%i", &cases);

    for(i = 1; i<=cases; i++){

        scanf("%i %i", &apples, &k);
        tab[apples+1][apples] = 0; 
        for(j = 1; j<=apples; j++){
            if((apples - j + 1)>=3){
                tab[j][j] = 0;
                tab[j][j+1] = (j+k)*2;
                tab[j][j+2] = (j+1+k)*3;  
            }
            else if((apples - j + 1)==2){
                tab[j][j] = 0;
                tab[j][j+1] = (j+k)*2;
            }
            else{
                tab[j][j] = 0; 
            }
        }

        for(j = 4; j<=apples; j++){
            x = j;
            for(m = 1; x<=apples; m++, x++){
                mini = INT_MAX;
                for(l = m; l<=x; l++){
                    mini = min((l+k)*(x-m+1)+tab[m][l-1]+tab[l+1][x], mini);    
                }
                tab[m][x] = mini;
            }
        }

        printf("Case %i: %i\n", i, tab[1][apples]);
    }

    return 0;
}
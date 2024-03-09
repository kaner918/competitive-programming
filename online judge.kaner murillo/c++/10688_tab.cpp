//https://onlinejudge.org/external/106/10688.pdf
//10688

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int tab[102][102];

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
            for(m = 1; m<=apples; m++, x++){
                mini = INT_MAX;
                for(l = m; l<=j+m-1; l++){
                    cout<<m<<" "<<m+j-1<<" "<<l<<endl;
                    mini = min((l+k)*(j+m-l)+tab[m][l-1]+tab[m+1][j+m-1], mini);    
                }
                tab[m][j+m-1] = mini;
            }
        }
        for(j = 1; j<=apples; j++){
            for(m = 1; m<=apples; m++){
                printf("%i\t", tab[j][m]);
            }
            cout<<endl;
        }
        
    }

    return 0;
}
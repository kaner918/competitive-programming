//https://onlinejudge.org/external/113/11341.pdf
//11341

#include<cstdio>
#include<iostream>

using namespace std;

int courses[12][102], mem[12][102], flag;

int dp(int i, int n, int chance){

    int ans;
    
    if(mem[i][chance] != -1){
        ans = mem[i][chance];
    }

    else{

        if(i == n || !chance){
            if(i == n){
                flag = 1;
            }
            ans = 0;
        }

        else{

            int j, maxi = 0;

            for(j = 0; j<chance; j++){
                if(chance-(j+1) >= 0 && courses[i][j] > 4){
                    maxi = max(maxi, dp(i+1, n, chance-(j+1))+courses[i][j]);
                }
            }
            
            ans = maxi;
        }

        mem[i][chance] = ans;
    }
    
    return ans;
}   

int main(){

    int cases, n, m, i, j, ans;

    scanf("%i", &cases);

    while(cases--){
        
        scanf("%i %i", &n, &m);

        for(i = 0; i<=n; i++){
            for(j = 0; j<=m; j++){
                if(i < n && j < m){
                    scanf("%i", &courses[i][j]);
                }
                mem[i][j] = -1;
            }
        }
        
        flag = 0;
        ans = dp(0, n, m);

        if(flag && ans >= 5*n){
            printf("Maximal possible average mark - %.2f.\n", (double)(1e-9+ans)/n);
        }
        else{
            printf("Peter, you shouldn't have played billiard that much.\n");
        }
    }
    return 0;
}
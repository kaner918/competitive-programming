//https://onlinejudge.org/external/126/12621.pdf
//12621

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int mem[101][2500], calories[101];

int dp(int n, int min_calories){

    int ans;

    if(mem[n][min_calories] != INT_MAX){
        ans = mem[n][min_calories];
    }

    else{

        if(!n){

            if(min_calories>0){
                ans = INT_MIN;
            }
            else{
                ans = min_calories;
            }
        }

        else{
            ans = dp(n-1, min_calories);

            if(calories[n-1] <= min_calories){
                ans = max(ans, dp(n-1, min_calories-calories[n-1]));
            }
            else{
                ans = max(ans, min_calories-calories[n-1]);
            }
        }

        mem[n][min_calories] = ans;
    }
    return ans;
}


int main(){

    int cases, ans, min_calories, size_calories, i, j, x;

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){

        scanf("%i", &min_calories);
        scanf("%i", &size_calories);

        for(j = 0; j<size_calories+1; j++){
            if(j<size_calories){
                scanf("%i", &calories[j]);
            }
            for(x = 0; x<2501; x++){
                mem[j][x] = INT_MAX;
            }
        }
        ans = dp(size_calories, min_calories);


        if(ans != INT_MIN){
            printf("%i\n", min_calories+(ans*-1));
        }

        else{
            printf("NO SOLUTION\n");
        }
    }

    return 0;
}
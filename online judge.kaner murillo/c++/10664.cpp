//https://onlinejudge.org/external/106/10664.pdf
//10664

#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int arr[22], tab[22][202];

int knapsack(int size, int max_sum){

    int i, j;

    for(i = 0; i<=max_sum; i++){
        tab[size][i] = i;
    }

    for(i = size-1; i>-1; i--){
        for(j = max_sum; j>-1; j--){
            if(j+arr[i] <= max_sum){
                tab[i][j] = max(tab[i+1][j], tab[i+1][j+arr[i]]);
            }
            else{
                tab[i][j] = tab[i+1][j];
            }
        }
    }

    return tab[0][0];
}

int main(){

    int cases, max_sum, ans, i, j;
    string cad;

    scanf("%i", &cases);
    cin.ignore();

    for(i = 0; i<cases; i++){
        max_sum = 0;
        getline(cin, cad);
        stringstream stk(cad);
        j = 0;

        while(stk>>arr[j]){
            max_sum+=arr[j];
            j+=1;
        }

        ans = knapsack(j, max_sum/2);

        if(ans * 2 == max_sum){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
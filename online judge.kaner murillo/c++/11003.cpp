//https://onlinejudge.org/external/110/11003.pdf
//11003

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int weight[1002], load[1002], mem[1002][3002];

int dp(int n, int sums, int maxi){

    int ans;

    if(mem[n][sums] != -1){
        ans = mem[n][sums];
    }

    else{
        if(!n){
            ans = 0;
        }

        else{

            int a, b = 0;

            a = dp(n-1, sums, maxi);

            if(sums <= load[n-1]){
                b = 1;
                if(sums+weight[n-1]<=maxi){
                    b = dp(n-1, sums+weight[n-1], maxi) + 1; 
                }
            }
            ans = max(a, b);
        }

        mem[n][sums] = ans;
    }

    return ans;
}

int main(){

    int size_boxes, i, j, maxi;

    while(scanf("%i", &size_boxes) && size_boxes){
        maxi = 0;
        for(i = 0; i<size_boxes; i++){
            scanf("%i %i", &weight[i], &load[i]);
            maxi = max(maxi, load[i]);
        }

        for(i = 0; i<=size_boxes; i++){
            for(j = 0; j<=maxi; j++){
                mem[i][j] = -1;
            }
        }

        printf("%i\n", dp(size_boxes, 0, maxi));

        /* for(i = 0; i<=size_boxes; i++){
            for(j = 0; j<=maxi; j++){
                printf("%i\t", mem[i][j]);;
            }
            cout<<endl;
        } */
    }

    return 0;
}
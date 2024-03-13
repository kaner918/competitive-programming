//https://onlinejudge.org/external/129/12996.pdf
//12996

#include<cstdio>
#include<iostream>

using namespace std;

int arr[11];

int main(){

    int cases, j, i, num, sum1, flag, size, maxi;

    scanf("%i", &cases);

    for(i = 1; i<= cases; i++){

        scanf("%i %i", &size, &maxi);
        sum1 = 0;
        flag = 1;

        for(j = 0; j<size; j++){
            scanf("%i", &arr[j]);
            sum1+=arr[j];
        }

        for(j = 0; j<size; j++){
            scanf("%i", &num);
            if(num < arr[j]){
                flag = 0;
            }
        }
        printf("Case %i: ", i);
        if(sum1 > maxi || !flag){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }

    }

    return 0;
}
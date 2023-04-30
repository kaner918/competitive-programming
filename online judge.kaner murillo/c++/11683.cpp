//https://onlinejudge.org/external/116/11683.pdf
//11683

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int arr[10001];

int main(){

    int a, c, i, sum1, counter;

    while(scanf("%i", &a) && a){

        scanf("%i", &c);

        sum1 = 0;

        for(i = 0; i<c; i++){

            scanf("%i", &arr[i]);
            sum1+=arr[i];
        }

        if(!sum1){

            counter = a-arr[0];
        }

        else{

            counter = a-arr[0];

            /* while(sum2!=sum1){ O(n^2)

                sum2 = 0;
                flag = false;

                for(i = 0; i<c; i++){

                    if(arr2[i] > arr[i]){

                        arr2[i]-=1;

                        if(!flag){
                            counter++;
                        }

                        flag = true;
                    }

                    else{
                        flag = false;
                    }

                    sum2+=arr2[i];
                }
            } */

            // o(n)

            for(i = 1; i<c; i++){

                if(arr[i]<arr[i-1]){

                    counter+=arr[i-1]-arr[i];
                }
            }
        }

        printf("%i\n", counter);
    }
}
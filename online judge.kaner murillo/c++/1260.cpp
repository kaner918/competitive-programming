//https://onlinejudge.org/external/12/1260.pdf
//1260

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int cases, size, i, n, sum, counter;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i", &size);
        int arr[size];
        sum = 0;

        for(i = 0; i<size; i++){

            cin>>arr[i];
        }

        for(i = 1; i<size; i++){

            counter = 0;
            
            for(n = i-1; n>-1; n--){

                if(arr[i] >= arr[n]){

                    counter++;
                }
            }

            sum+=counter;

        }

        printf("%i\n", sum);

    }
    return 0;
}
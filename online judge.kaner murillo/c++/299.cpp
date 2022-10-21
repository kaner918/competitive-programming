//https://onlinejudge.org/external/2/299.pdf
//299

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int cases, size, inversions, i, n, arr[50], aux;

    scanf("%i", &cases);

    while(cases--){

        inversions = 0;
        scanf("%i", &size);

        for(i = 0; i<size; i++){

            scanf("%i", &arr[i]);
        }

        for(i = 0; i<size-1; i++){

            for(n = i+1; n<size; n++){

                if(arr[i] > arr[n]){

                    inversions++;
                }
            }
        }

        printf("Optimal train swapping takes %i swaps.\n", inversions);
    }
    return 0;
}
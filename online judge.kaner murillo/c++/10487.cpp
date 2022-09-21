//https://onlinejudge.org/external/104/10487.pdf
//10487

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int sizeNumbers, consults, distance, sum, i, n, counter,m, val;

    counter = 1;

    while(scanf("%i", &sizeNumbers) && sizeNumbers != 0){

        int arr[sizeNumbers];

        for(i = 0; i<sizeNumbers; i++){

            scanf("%i", &val);
            arr[i] = val;
        }

        scanf("%i", &consults);
        printf("Case %i:\n", counter);

        while(consults--){

            scanf("%i", &val);

            distance = abs(val - (arr[0]+ arr[1]));
            sum = arr[0]+ arr[1];

            i = 0;

            while(i < sizeNumbers && distance != 0){

                n = i+1;

                while(n  < sizeNumbers && distance != 0){

                    if(abs(val - (arr[i]+ arr[n])) < distance){

                        sum = arr[i] + arr[n];
                        distance = abs(val - (arr[n] + arr[i]));
                    }

                    n+=1;
                }
                i+=1;
            }

            printf("Closest sum to %i is %i.\n", val, sum);
        }

        counter+=1;
    }

    return 0;
}
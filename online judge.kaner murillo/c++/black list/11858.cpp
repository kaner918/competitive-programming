//https://onlinejudge.org/external/118/11858.pdf
//11858

#include<cstdio>
#include<iostream>
#include<algorithm>

int counter;

bool comparador(int a, int b){

    bool ans = true;

    if(a > b){

        ans = false;
        counter+=1;
    }

    return ans;
}

using namespace std;

int main(){

    int size, i;

    while(scanf("%i", &size) != EOF){

        int *arr = (int*) malloc(size*sizeof(int));
        counter = 0;

        for(i = 0; i<size; i++){

            scanf("%i", &arr[i]);
        }

        sort(arr, arr+size, comparador);

        printf("%i\n", counter);
        
        for(i = 0; i<size; i++){

            cout<<arr[i]<<" ";
        }
        printf("\n");
    }

    return 0;
}
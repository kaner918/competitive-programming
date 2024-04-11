//https://cses.fi/problemset/task/1083/

#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int arr[200001];

int main(){

    int size, i;
    scanf("%i", &size);
    
    for(i = 0; i<size-1; i++){
        scanf("%i", &arr[i]);
    }

    sort(arr, arr+size-1);
    i = 1;
    
    while(arr[i-1] == i){
        i++;
    }
    
    printf("%i\n", i);

    return 0;
}
//https://cses.fi/problemset/task/1746

#include<cstdio>
#include<iostream>

using namespace std;

const int M = 1e9+7;

int arr[100002];
long long int tab[100002];

int main(){

    int i, j, n, m, mini;

    scanf("%i %i", &n, &m);

    for(i = 0; i<n; i++){
        scanf("%i", &arr[i]);
    }

    for(i = 1; i<n; i++){
        tab[i] = tab[i-1];
        mini = arr[i-1];

        if(i<n-1){
            mini = min(mini, arr[i+1]);
        }
        if(!arr[i]){

        }
    }
    return 0;
}

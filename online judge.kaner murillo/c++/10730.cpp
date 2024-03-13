//https://onlinejudge.org/external/107/10730.pdf
//10730

#include<cstdio>
#include<iostream>

using namespace std;

int arr[10001], diferents[10001][10001], diferents2[10001][10001];

int main(){

    int size, i, j, ans, priority;

    while(scanf("%i", &size) && size){
        cin.ignore();
        ans = 0;
        for(i = 0; i<size; i++){
            scanf("%i", &arr[i]);
        }

        for(i = 0; i<size; i++){
            for(j = 0; j<size; j++){
                diferents[i][j] = 0;
                diferents2[i][j] = 0;
            }
        }

        i = 0;
        while(i < size-2 && !ans){
            j = i+1;
            while(j < size && !ans){
                
                if(arr[i] > arr[j]){
                    diferents[i][arr[i]-arr[j]]++;
                    ans = diferents[i][arr[i]-arr[j]] == 2;
                }

                else{
                    cout<<arr[i]<<" "<<arr[j]<<endl;
                    diferents2[i][arr[j]-arr[i]]++;
                    ans = diferents2[i][arr[j]-arr[i]] == 2;
                }
                j+=1;
            }
            i+=1;
        }

        if(!ans){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }

    }

    return 0;
}
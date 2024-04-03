//https://onlinejudge.org/external/107/10730.pdf
//10730

#include<cstdio>
#include<iostream>

using namespace std;

int arr[10001], diferents[10001], diferents2[10001];

int main(){

    int size, i, j, ans, priority;
    char c;

    while(scanf("%i", &size) && size){

        scanf(":");

        ans = 0;
        for(i = 0; i<size; i++){
            scanf("%i", &arr[i]);
        }

        for(i = 0; i<size+2; i++){
            diferents[i] = 0;
            diferents2[i] = 0;    
        }

        i = 0;
        
        while(i < size && !ans){
            j = i+1;
             
            diferents[arr[i]] = 1; 
            diferents2[arr[i]] = 1;

            while(j < size && !ans){ 
                if(arr[i] < arr[j] && arr[i] > (arr[j]-arr[i]) && diferents[arr[i]-(arr[j]-arr[i])]){
                    ans = 1;
                }
                else if(arr[i] > arr[j] && arr[i]+(arr[i]-arr[j]) < size && diferents[arr[i]+(arr[i]-arr[j])]){
                    ans = 1;
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
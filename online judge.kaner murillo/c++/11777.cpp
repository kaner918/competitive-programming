//https://onlinejudge.org/external/117/11777.pdf
//11777

#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int cases, i, sum,v,counter=1;
    char result;

    scanf("%i", &cases);

    while(cases--){
            
        int arr[3];
        sum = 0;

        for(i = 0; i<7; i++){
            
            cin>>v;

            if(i<4){

                sum+=v;
            }
            else{
                arr[i-4] = v;

            }
        } 

        sort(begin(arr), end(arr));

        if ( sum + (arr[1] + arr[2])/2 >= 90){
            
            result = 'A';
        }

        else if(sum + (arr[1] + arr[2])/2 >= 80){

            result = 'B';
        }

        else if(sum + (arr[1] + arr[2])/2 >= 70){
            
            result = 'C';
        }

        else if(sum + (arr[1] + arr[2])/2 >= 60){

            result = 'D';
        }

        else{

            result = 'F';
        }

        printf("Case %i: %c\n", counter, result);

        counter++;
    }

    return 0;
}
//https://onlinejudge.org/external/9/957.pdf
//957

#include<cstdio>
#include<iostream>

using namespace std;

int arr[1000001];

int main(){

    int i, popes, period, year, l, h, mid, ans, first, last, find;

    while(cin>>period){
        cin>>popes;
        ans = 0;

        for(i = 0; i<popes; i++){
            cin>>arr[i];
        }
        
        for(i = 0; i<popes; i++){
            
            l = i;
            h = popes;
            find = arr[i] + period - 1;

            while (l+1 < h){

                mid = l+ ((h-l)>>1);

                if(arr[mid] <= find){
                    l = mid;
                }
                else{
                    h = mid;
                }
            }

            if((l - i + 1) > ans){
                ans = (l - i + 1);
                first = arr[i];
                last = arr[l];
            }
        }

        printf("%i %i %i\n", ans, first, last);
    }


    return 0;
}
//https://onlinejudge.org/external/104/10474.pdf
//10474

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n, q, num, i, low, hight, mid, position, counter = 1;

    while(scanf("%i %i", &n, &q) && (n || q)){

        printf("CASE# %i:\n", counter++);
        
        vector<int>arr(n);
        
        for(i = 0; i<n; i++){
            scanf("%i", &num);
            arr[i] = num;
        }

        sort(arr.begin(), arr.end());

        for(i = 0; i<q; i++){

            scanf("%i", &num);
            position = -1;

            low = 0;
            hight = n-1;
            mid = low + ((hight-low)>>1);

            while(low<=hight){

                if(arr[mid] == num){
                    position = mid;
                    hight = mid-1;
                }

                else if(num > arr[mid]){
                    low = mid+1;
                }

                else{
                    hight = mid-1;
                }

                mid = low + ((hight-low)>>1);
            }

            if(position == -1){
                printf("%i not found\n", num);
            }

            else{

                printf("%i found at %i\n", num, position+1);
            }
        }
    }

    return 0;
}
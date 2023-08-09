//https://onlinejudge.org/external/106/10611.pdf
//10611

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main(){

    int size, queries, num, i, low, hight, mid, mid2, target, target2;

    scanf("%i", &size);
    vector<int>arr(size);
    for(i = 0; i<size; i++){
        scanf("%i", &num);
        arr[i] = num;
    }

    scanf("%i", &queries);

    while(queries--){

        scanf("%i", &num);

        if(num<=arr.front()){
            printf("X ");
        }

        else{

            low = 0;
            hight = size-1;
            mid = low + ((hight-low)>>1);

            while(low <= hight){
                
                if(num > arr[mid]){
                    low = mid+1;
                    target = mid;
                }

                else{

                    hight = mid-1;
                }

                mid = low + ((hight-low)>>1);
            }

            printf("%i ", arr[target]);
        }

        if(num>=arr.back()){
            printf("X\n");
        }

        else{

            low = 0;
            hight = size-1;
            mid = low + ((hight-low)>>1);

            while(low <= hight){

                if(num >= arr[mid]){
                    low = mid+1;
                }

                else{

                    target = mid;
                    hight = mid-1;
                }

                mid = low + ((hight-low)>>1);
            }

            printf("%i\n", arr[target]);
        }
    }
    return 0;
}
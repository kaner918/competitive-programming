//https://onlinejudge.org/external/110/11057.pdf
//11057

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){

    int size, i, mid, num, num1, num2, low, hight;

    while(scanf("%i", &size) != EOF){

        vector<int>arr(size);
        num1 = 0, num2 = INT_MAX;

        while(size--){

            scanf("%i", &num);
            arr[size] = num;
        }
        scanf("%i", &num);

        sort(arr.begin(), arr.end());

        for(i = 0; i<arr.size(); i++){

            low = 0;
            hight = arr.size()-1;
            mid = low + ((hight-low)>>1);

            while(arr[mid] + arr[i] != num && low<hight){

                if(arr[mid] + arr[i] > num){

                    hight = mid-1;
                }

                else if(arr[mid] + arr[i] < num){

                    low = mid+1;
                }

                mid = low + ((hight-low)>>1);
            }

            if(mid != i && arr[mid] + arr[i] == num && abs(arr[mid] - arr[i]) < abs(num1-num2)){

                num1 = min(arr[mid], arr[i]);
                num2 = max(arr[mid], arr[i]);
            }
        }

        printf("Peter should buy books whose prices are %i and %i.\n\n", num1, num2);
        cin.ignore();
    }

    return 0;
}
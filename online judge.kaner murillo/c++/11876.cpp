//https://onlinejudge.org/external/118/11876.pdf
//11876

#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int lowBound(int low, int hight, vector<int>&numbers, int find){

    int mid;

    while (low < hight){

        mid = low + ((hight - low) >> 1);

        if(find <= numbers[mid]){
            hight = mid;
        }

        else{
            low = mid + 1;
        }
    }

    return low;
    
}

int upperBound(int low, int hight, vector<int>&numbers, int find){

    int mid;

    while (low < hight){

        mid = low + ((hight - low) >> 1);

        if(find < numbers[mid]){
            hight = mid;
        }

        else{
            low = mid + 1;
        }
    }

    return low;
    
}

int main(){

    int cases, a, i, counter, j, b, root, low, hight;
    vector<int>numbers = {1};

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){

        scanf("%i %i", &a, &b);

        while(b > numbers.back()){

            counter = 0;
            j = 1;
            root = sqrt(numbers.back());

            while(j<= root){

                counter+= (!(numbers.back() % j))*2;
                j++;
            }

            if(pow(root, 2) == numbers.back()){
                counter-=1;
            }

            numbers.push_back(numbers.back() + counter);
        }

        low = lowBound(0, numbers.size(), numbers, a);
        hight = upperBound(0, numbers.size(), numbers, b);

        printf("Case %i: %i\n", i+1, hight - low);
    }

    return 0;
}
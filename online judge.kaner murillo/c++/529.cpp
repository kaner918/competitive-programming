//https://onlinejudge.org/external/5/529.pdf
//529

#include<cstdio>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int flag;
vector<int>numbers(10001);

void solved(int index, int limit, vector<int>&res){

    int i;

    if(numbers[index] == limit){

        res = numbers;
        flag = index;
    } 

    else{

        int j, sum, counter = index;
        
        if(flag != limit){ //podamos las secuancias donde su maxima suma, llega con mas pasos a la ya encontrada

            for(j = numbers[index]; j<limit; j*=2){
                counter++;
            }

            if(counter >= flag){
                return;
            }
        }

        for(i = index; i>-1 && numbers[i] + numbers[i] > numbers[index]; i--){

            for(j = i; j>-1 && numbers[i] + numbers[j] > numbers[index]; j--){

                sum = numbers[i] + numbers[j];

                if(sum <= limit and sum > numbers[index] && index+1<flag){

                    numbers[index + 1] = sum;
                    solved(index+1, limit, res);
                } 
            }
        }
    }
}

int main(){

    int size, i;

    while(scanf("%i", &size) && size){
        vector<int>vec(size, -1);
        flag = size;
        numbers[0] = 1;
        solved(0, size, vec);

        printf("1");
        for(i = 1; i<flag+1; i++){
            printf(" %i", vec[i]);
        }
        printf("\n");
    }

    return 0;
}
//https://onlinejudge.org/external/117/11753.pdf
//11753

#include<cstdio>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int flag, sizeRes;

void solved(int index2, int index, int size, int limit, vector<int>&nums, vector<int>&comb, unordered_set<int>&numbers){

    if(index == nums.size()){

        int n, auxFlag = 1;


        for(n = 0; n<comb.size()/2 && auxFlag; n++){

            if(comb[n]!=comb[limit-1-n]){
                auxFlag = 0;
            }
        }

        /* cout<<"combi"<<endl;
        for(n = 0; n<limit; n++){
            cout<<comb[n]<<" ";
        }

        cout<<endl; */
        
        if(auxFlag){
            sizeRes = min(sizeRes, size);
        }
    }

    else{

        int i;
        comb[index2] = nums[index];
        if(index2 < comb.size()){

            solved(index2+1, index+1, size, limit, nums, comb, numbers);
        }

        for(auto it = numbers.begin(); it!=numbers.end(); it++){

            if(index2 < comb.size() && size+1 <= limit){
                comb[index2] = *it;
                solved(index2+1, index, size+1, limit+1, nums, comb, numbers);
            }
        }
    }
}

int main(){

    int cases, size, limit, i, n, num;

    scanf("%i", &cases);
    
    for(i = 1; i<=cases; i++){

        scanf("%i %i", &size, &limit);
        
        vector<int>nums(size);
        unordered_set<int>numbers;
        vector<int>comb(size*2-1, 0);

        flag = 1;
        sizeRes = limit;

        for(n = 0; n<size; n++){

            scanf("%i", &num);
            nums[n] = num; 
            numbers.insert(num);
        }

        for(n = 0; n<size/2 && flag; n++){

            if(nums[n]!=nums[size-1-n]){
                flag = 0;
            }
        }

        printf("Case %i: ", i);

        if(flag){
            printf("Too easy\n");
        }

        else{
            
            
            solved(0, 0, 0, size, nums, comb, numbers);

            if(sizeRes <= limit){
                printf("%i\n", sizeRes);
            }
            else{
                printf("Too difficult\n");
            }
        }
    }
    return 0;
}
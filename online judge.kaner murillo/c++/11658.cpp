//https://onlinejudge.org/external/116/11658.pdf
//11658

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

float arr[102];

float dp(int i, int n, int index, float sum, map<pair<int, float>, float>&mem){

    float ans;

    if(mem.count({i, sum})){
        ans = mem[{i, sum}];
    }
    
    else{

        if(i == n){

            if(sum<=50.00){
                ans = 100.00;
            }
            else{

                ans = sum;
            }
        }

        else{

            float a, b = 100.00;

            a = dp(i+1, n, index, sum, mem);

            if(i!=index){
                b = dp(i+1, n, index, sum+arr[i], mem);
            }

            ans = min(a, b);
        }

        mem[{i, sum}] = ans;
    }

    return ans;
}

int main(){

    int size, index, i;

    while(scanf("%i %i", &size, &index) && (size || index)){
        
        index--;

        for(i = 0; i<size; i++){
            scanf("%f", &arr[i]);
        }

        map<pair<int, float>, float>mem;
        printf("%.2f\n",(arr[index]/dp(0, size, index, arr[index], mem))*100.00);
    }

    return 0;
}
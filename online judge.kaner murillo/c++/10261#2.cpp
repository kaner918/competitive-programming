//https://onlinejudge.org/external/102/10261.pdf
//10261

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int dp(int i, int n, int sum1, int sum2, vector<int>&cars, vector<vector<int>>&ways, map<pair<int, int>, int>&mem){

    int ans;

    if(mem.count({i, abs(sum1-sum2)})){
        ans = mem[{i, abs(sum1-sum2)}];
    }
    else{

        if(i == n){
            ans = 0;
        }

        else{
            int a = 0, b = 0;

            if(sum1 - cars[i] >= 0){
                a = dp(i+1, n, sum1 - cars[i], sum2, cars, ways, mem) + 1;
            }

            if(sum2 - cars[i] >= 0){
                b = dp(i+1, n, sum1, sum2 - cars[i], cars, ways, mem) + 1;
            }

            if(a >= b){
                ans = a;
                ways[i][abs(sum1-sum2)] = 0;
            }
            else{
                ans = b;
                ways[i][abs(sum1-sum2)] = 1;
            }
        }
        mem[{i, abs(sum1-sum2)}] = ans;
    }

    return ans;
}

int main(){

    int cases, i, size, sizeCar, car, ans, flag = 0, sums1, sums2;
    cin>>cases;
    cin.ignore();

    while(cases--){

        if(flag){
            printf("\n");
            cin.ignore();
        }
        flag = 1;
        vector<int>cars;
        map<pair<int, int>, int>mem;
        cin>>size;
        size*=100;
        sums1 = size;
        sums2 = size;
        while(cin>>sizeCar && sizeCar){
            cars.push_back(sizeCar);
        }
        vector<vector<int>>ways(cars.size()+1, vector<int>(size+1, 0));
        ans = dp(0, cars.size(), size, size, cars, ways, mem);

        printf("%i\n", ans);

        i = 0;
        while(i<cars.size() && (sums1 - cars[i] >= 0 || sums2 - cars[i]>=0)){
            if(!ways[i][abs(sums1-sums2)]){
                sums1-=cars[i];
                printf("port\n");
            }
            else{
                sums2-=cars[i];
                printf("starboard\n");
            }
            i+=1;
        }
    }

    return 0;
}
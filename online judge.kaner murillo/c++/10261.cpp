//https://onlinejudge.org/external/102/10261.pdf
//10261

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

pair<int, vector<int>>dp(int i, int n, int sum1, int sum2, vector<int>&cars, map<pair<int, int>, pair<int, vector<int>>>&mem){

    pair<int, vector<int>>ans;

    if(mem.count({i, abs(sum1-sum2)})){
        ans = mem[{i, abs(sum1-sum2)}];
    }
    else{

        if(i == n){
            ans.first = 0;
            ans.second = {-1};
        }

        else{
            pair<int, vector<int>>a = {0, {-1}};
            pair<int, vector<int>>b = {0, {-1}};

            if(sum1 - cars[i] >= 0){
                a = dp(i+1, n, sum1 - cars[i], sum2, cars, mem);
                a.first+=1;
                a.second.push_back(0);
            }

            if(sum2 - cars[i] >= 0){
                b = dp(i+1, n, sum1, sum2 - cars[i], cars, mem);
                b.first+=1;
                b.second.push_back(1);
            }

            if(a.first >= b.first){
                ans = a;
            }
            else{
                ans = b;
            }
        }
        mem[{i, abs(sum1-sum2)}] = ans;
    }

    return ans;
}

int main(){

    int cases, i, size, sizeCar, car, flag = 0;
    pair<int, vector<int>>ans;
    cin>>cases;
    cin.ignore();

    while(cases--){

        if(flag){
            printf("\n");
            cin.ignore();
        }
        flag = 1;
        vector<int>cars;
        map<pair<int, int>, pair<int, vector<int>>>mem;
        cin>>size;
        size*=100;
        
        while(cin>>sizeCar && sizeCar){
            cars.push_back(sizeCar);
        }
        ans = dp(0, cars.size(), size, size, cars, mem);

        printf("%i\n", ans.first);
        for(i = ans.second.size()-1; i>0; i--){
            if(!ans.second[i]){
                printf("port\n");
            }
            else{
                printf("starboard\n");
            }
        }
    }

    return 0;
}
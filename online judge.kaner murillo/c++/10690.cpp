//https://onlinejudge.org/external/106/10690.pdf
//10690

#include<cstdio>
#include<iostream>
#include<map>
#include<tuple>
#include<climits>

using namespace std;

int arr[102];

int dp1(int i, int n, int count, int sums, int find, map<tuple<int, int, int>, int>&mem){

    int ans;
    tuple<int, int, int>aux = make_tuple(i, count, find);

    if(mem.count(aux)){
        ans = mem[aux];
    }

    else{

        if(i == n || !count){
            
            ans = find*(sums-find);
            if(count){
                ans = 0;
            }
        }

        else{

            int a = 0, b = 0;

            a = dp1(i+1, n, count, sums, find, mem);

            if(count){
                b = dp1(i+1, n, count-1, sums, find+arr[i], mem);
            }

            ans = max(a, b);
        }

        mem[aux] = ans;
    }

    return ans;
}

int dp2(int i, int n, int count, int sums, int find, map<tuple<int, int, int>, int>&mem){

    int ans;
    tuple<int, int, int>aux = make_tuple(i, count, find);

    if(mem.count(aux)){
        ans = mem[aux];
    }

    else{

        if(i == n || !count){
            ans = find*(sums-find);
            if(count){
                ans = INT_MAX;
            }
        }

        else{

            int a = INT_MAX, b = INT_MAX;

            a = dp2(i+1, n, count, sums, find, mem);

            if(count){
                b = dp2(i+1, n, count-1, sums, find+arr[i], mem);
            }

            ans = min(a, b);
        }

        mem[aux] = ans;
    }

    return ans;
}

int main(){

    int n, m, i, sums, a, b;

    while(scanf("%i %i", &n, &m) != EOF){
        
        sums = 0;
        if(m<n){
            swap(n, m);
        }

        for(i = 0; i<n+m; i++){
            scanf("%i", &arr[i]);
            sums+=arr[i];
        }

        map<tuple<int, int, int>, int>mem;
        a = dp1(0, n+m, n, sums, 0, mem);
        mem.clear();
        b = dp2(0, n+m, n, sums, 0, mem);

        printf("%i %i\n", a, b);
    }

    return 0;
}
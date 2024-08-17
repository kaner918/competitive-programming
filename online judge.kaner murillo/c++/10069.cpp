//https://onlinejudge.org/external/100/10069.pdf
//10069

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int mem[10001][101];

int dp(int l, int r, string &cad1, string &cad2){

    int ans;
    if(mem[l][r]!=-1){
        ans = mem[l][r];
    }
    else{
        if(l == cad1.size() || r==cad2.size()){
            ans = 0;
            if(r==cad2.size()){
                ans = 1;
            }
        }
        else{
            ans = dp(l+1, r, cad1, cad2);
            if(cad1[l]==cad2[r]){
                ans += dp(l+1, r+1, cad1, cad2);
            }
        }
        mem[l][r] = ans;
    }

    return ans;
}

int main(){

    string cad1, cad2;
    int i, k, j, cases;

    cin>>cases;

    for(i = 0; i<cases; i++){
        cin>>cad1>>cad2;
        for(j = 0; j<=cad1.size(); j++){
            for(k = 0; k<=cad2.size(); k++){
                mem[j][k] = -1;
            }
        }
        printf("%i\n", dp(0, 0, cad1, cad2));
    }

    return 0;
}
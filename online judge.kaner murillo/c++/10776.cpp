//https://onlinejudge.org/external/107/10776.pdf
//10776

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void solved(int index, int change, int limit, vector<string>&res, string&s, string cad){

    if(change == limit){

        if(!(res.size()) || (res.back() != cad)){

            res.push_back(cad);
        }
    }

    else{

        if(index == s.length()){
            return;
        }

        solved(index+1, change, limit, res, s, cad);
        solved(index+1, change+1, limit, res, s, cad+s[index]);
    }
}

int main(){

    int limit, i;
    string cad;

    while(cin>>cad){

        cin>>limit;
        
        sort(cad.begin(), cad.end());
        vector<string>res;
        solved(0, 0, limit, res, cad, "");

        for(i = res.size()-1; i>-1; i--){
            cout<<res[i]<<endl;
        }
    } 

    return 0;
}
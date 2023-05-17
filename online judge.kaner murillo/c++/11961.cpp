//https://onlinejudge.org/external/119/11961.pdf
//11961

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

char arr[] = {'A', 'C', 'G', 'T'};

void solved(int limit, int change, map<vector<char>, int>&memo, vector<vector<char>>&res, vector<char>&comb){


    if(change == limit){

        auto it = memo.find(comb);

        if(it == memo.end()){

            res.push_back(comb);
            memo[comb] = 1;
        }
    }

    else{

        int i, n;
        char pre;
        
        /* solved(index+1, res, comb); */

        for(i = 0; i<4; i++){

            for(n = 0; n<comb.size(); n++){

                pre = comb[n];
                comb[n] = arr[i];
                solved(limit, change+1, memo, res, comb);
                comb[n] = pre;
            }
        }
    }
}

int main(){

    int cases, size, i, n, power;
    string cad;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i\n", &size, &power);    
        getline(cin, cad);
        vector<char>comb;
        vector<vector<char>>res;

        for(i = 0; i<cad.length(); i++){

            comb.push_back(cad[i]);
        }
        map<vector<char>, int>memo;

        solved(power, 0, memo, res, comb);
        sort(res.begin(), res.end());

        cout<<res.size()<<endl;

        for(i = 0; i<res.size(); i++){

            for(n = 0; n<res[i].size(); n++){
                cout<<res[i][n];
            }
            cout<<endl;
        }
    }
    
    return 0;
}
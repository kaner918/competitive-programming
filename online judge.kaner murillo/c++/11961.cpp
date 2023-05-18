//https://onlinejudge.org/external/119/11961.pdf
//11961

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

char arr[] = {'A', 'C', 'G', 'T'};

void solved(int index, int change, int limit, vector<vector<char>>&res, vector<char>&comb){

    if(change == limit){

        res.push_back(comb);
    }

    else{

        if(index == comb.size()){
            return;
        }

        int i, n;
        char pre;

        solved(index+1, change, limit, res, comb);
        
        for(i = 0; i<4; i++){

            pre = comb[index];
            comb[index] = arr[i];
            solved(index+1, change+1, limit, res, comb);
            comb[index] = pre;
            
        }
    }
}

int main(){

    int cases, size, i, n, power,counter;
    string cad;

    scanf("%i", &cases);

    while(cases--){

        counter = 1;
        scanf("%i %i\n", &size, &power);    
        getline(cin, cad);
        vector<char>comb;
        vector<vector<char>>res;

        for(i = 0; i<cad.length(); i++){

            comb.push_back(cad[i]);
        }
        
        solved(0, 0, power, res, comb);

        sort(res.begin(), res.end());
        
        for(i = 1; i<res.size(); i++){

            if(res[i] != res[i-1]){

                counter++;
            }
        }

        cout<<counter<<endl;

        for(n = 0; n<res[0].size(); n++){
            cout<<res[0][n];
        }
        cout<<endl;
        
        for(i = 1; i<res.size(); i++){

            if(res[i] != res[i-1]){

                for(n = 0; n<res[i].size(); n++){
                    cout<<res[i][n];
                }
                cout<<endl;
            }
        }
    }
    
    return 0;
}
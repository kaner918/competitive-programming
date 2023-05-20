//https://onlinejudge.org/external/107/10776.pdf
//10776

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void solved(int change, map<char, int>&freq, int limit, vector<string>&res, string&s, string cad){

    if(change == limit){

        res.push_back(cad);
    }

    else{

        for(auto it = freq.begin(); it!=freq.end(); it++){

            if(it->second && (!cad.length() || it->first >= cad.back())){

                it->second--;
                solved(change+1, freq, limit, res, s, cad+it->first);
                it->second++;
            }
        }
    }
}

int main(){

    int limit, i, counter;
    string cad, aux;

    while(cin>>cad){

        cin>>limit;
        
        sort(cad.begin(), cad.end());
        vector<string>res;
        map<char, int>freq;

        freq[cad[0]] = 1;

        for(i = 1; i<cad.length(); i++){

            if(cad[i] == cad[i-1]){
                freq[cad[i]]++;
            }
            
            else{
                freq[cad[i]] = 1;
            }
        }

        solved(0, freq, limit, res, cad, "");

        for(i = 0; i<res.size(); i++){
            cout<<res[i]<<endl;
        }
    } 

    return 0;
}
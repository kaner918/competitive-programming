//https://onlinejudge.org/external/109/10905.pdf
//10905

#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class comparador{

    public:

    bool operator()(string a, string b){

        return a + b > b + a;
    }
};

int main(){

    int size, i;
    string word;

    while(scanf("%i", &size) && size != 0){

        vector<string>cads;

        for(i = 0; i<size; i++){

            cin>>word;

            cads.push_back(word);
        }

        sort(cads.begin(), cads.end(), comparador());

        for(i = 0; i<cads.size(); i++){

            cout<<cads[i];
        }
        printf("\n");
    }

    return 0;
}
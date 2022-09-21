//https://onlinejudge.org/external/4/482.pdf
//483

#include<vector>
#include<string>
#include<cstdio>
#include<iostream>
#include<sstream>

using namespace std;

int main(){

    int cases, i, v;
    string cad, number;

    scanf("%i", &cases);
    cin.ignore();

    while(cases--){
    
        cin.ignore();

        vector<int>positions;
        vector<string>numbers;

        getline(cin,cad);
        stringstream stk(cad);

        while(stk>>v){

            positions.push_back(v);
        }

        getline(cin,cad);
        stringstream stk2(cad);

        while(stk2>>number){

            numbers.push_back(number);
        }

        vector<string>results(numbers.size());

        for(i = 0; i<results.size(); i++){

            results[positions[i]-1] = numbers[i];
        }

        for(vector<string>::iterator it = results.begin(); it!=results.end(); ++it){

            cout<<*it<<endl;
        }

        if(cases>0){
            printf("\n");
        }
        
    }

    return 0;
}
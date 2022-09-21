//https://onlinejudge.org/external/4/469.pdf
//469

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main(){

    int cases, row, colum;
    string cad;

    scanf("%i", &cases);

    while(cases--){

        cin.ignore();
        vector<string>home;

        while(getline(cin, cad) && (cad[0] == "L" || cad[0] == "W")){

            home.push_back(cad);
        }

        while(getline(cin, cad) && cad!=""){

            stringstream stk(cad);

            stk>>row;
            stk>>colum;
        }
    }

    return 0;
}
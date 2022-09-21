//https://onlinejudge.org/external/113/11340.pdf
//11340

#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main(){

    int cases, page, lines, i, total;
    double cents;
    char letter;
    string cad;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i", &page);
        map<char, double> dic;
        total = 0;

        while(page--){

            cin>>letter>>cents;
            dic[letter] = cents;
        }

        scanf("%i", &lines);
        cin.ignore();

        while(lines--){

            getline(cin, cad);
            
            for(i = 0; i<cad.length(); i++){

                if(dic.find(cad[i]) != dic.end()){

                    total+=dic[cad[i]];
                }
            }
        }

        if(total % 100 < 10){

            printf("%i.0%i$\n", total/100, total%100);
        }

        else{
             
            printf("%i.%i$\n", total/100, total%100);
            
        }     
    }
    return 0;
}
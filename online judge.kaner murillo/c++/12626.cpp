//https://onlinejudge.org/external/126/12626.pdf
//12626

#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){

    int cases, i, counter;
    string line;

    scanf("%i", &cases);
    cin.ignore();

    while(cases--){

        map<char, int> dic = {{'A',0}, {'R',0},{'G',0},{'I',0},{'T',0}, {'M', 0}};

        getline(cin, line);
        counter = 0;

        for(i = 0; i<line.size(); i++){

            if(dic.find(line[i]) != dic.end()){

                dic[line[i]]+=1;
            }
        }   

        while(dic['A'] >= 3 && dic['M'] >= 1 && dic['R'] >= 2 && dic['G'] >= 1 && dic['I'] >= 1 && dic['T'] >= 1){

            counter+=1;

            dic['A']-=3;
            dic['M']-=1;
            dic['R']-=2;
            dic['G']-=1;
            dic['I']-=1;
            dic['T']-=1;
        }

        printf("%i\n", counter);
    }
    
    return 0;
}
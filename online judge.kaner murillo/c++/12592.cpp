//https://onlinejudge.org/external/125/12592.pdf
//12592

#include<cstdio>
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){

    int sizeWord, sizeCommands;
    string slogan, slogan2;
    map<string, string> dic;

    scanf("%i", &sizeWord);
    cin.ignore();

    while(sizeWord--){

        getline(cin, slogan);
        getline(cin, slogan2);

        dic[slogan] = slogan2;
        
    }

    scanf("%i", &sizeCommands);
    cin.ignore();

    while(sizeCommands--){

        getline(cin, slogan);
        printf("%s\n", dic[slogan].c_str());
        
    }

    return 0;   
}
//https://onlinejudge.org/external/103/10340.pdf
//10340

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    string cad1, cad2;
    int i, index;
    bool flag;

    while(cin>>cad1){

        cin>>cad2;
        i = 0;
        index = 0;  
        
        for(i = 0; index < cad1.length() && i<cad2.length(); i++){

            if(cad2[i] == cad1[index]){
                index++;
            }
        }

        if(index == cad1.length()){
            printf("Yes\n");
        } 

        else{

            printf("No\n");
        }
    }

    return 0;
}

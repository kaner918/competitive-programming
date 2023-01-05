//https://onlinejudge.org/external/9/902.pdf
//902

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main(){

    string cad, auxCad, auxCad2;
    int size, i, m, higer;

    while(cin>>size>>cad){

        i = 0;
        higer = 0;
        map<string, int>dic;

        while(i<= cad.length()-size){

            auxCad = cad.substr(i, size);

            m = ++dic[auxCad];

            if(dic[auxCad] > higer){

                higer = dic[auxCad];
                auxCad2 = auxCad;
            }

            i++;
        }
    
        cout<<auxCad2<<endl;
    }
}
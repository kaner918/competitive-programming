//https://onlinejudge.org/external/4/444.pdf
//444

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

    int i, letter, index;
    string cad, line, letter2;
    char a;

    while(getline(cin,line)){

        a = line[0];
        letter = a;

        if(letter > 47 and letter<58){
            
            cad = "";
            letter2 = "";

            for(i = line.length()-1; i>-1; i--){

                letter2+=line[i];

                if((letter2.length() == 2 && stoi(letter2)>31) || letter2.length() == 3){
            
                    a = stoi(letter2);
                    cad+=a;
                    letter2 = "";
                }
            }
            
            printf("%s\n", cad.c_str()); 
             
        }

        else{

            index = -1;
            vector<int>vec;

            for(i = line.length(); i>-1; i--){

                letter = line[i];
                
                while(letter>0){

                    vec.push_back(letter%10);
                    letter/=10;
                }
            }

            for(i = 0; i<vec.size(); i++){

                printf("%i", vec[i]);
            }

            printf("\n");
        }
    }

    return 0;
}
//https://onlinejudge.org/external/117/11716.pdf
//11716

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main(){

    int cases, i, n, counter, m;
    string line, cad;
    bool ans;

    scanf("%i", &cases);
    cin.ignore();

    while(cases--){

        getline(cin,line);
        vector<string>matrix;
        cad = "";
        counter = 0;
        m = 1;
        ans = false;

        while (m<=sqrt(line.length()) && ans == false){

            if(m * m == line.length()){

                ans = true;

            }
            m+=1;
        }


        if(ans == true){

            m-=1;

            for(i = 0; i<line.length(); i++){

                cad+=line[i];
                counter++;

                if(m * counter == line.length()){

                    matrix.push_back(cad);
                    cad="";
                    counter = 0;
                }
            }


            for(i = 0; i<matrix[0].length();i++){

                for(n = 0; n<matrix[0].length(); n++){

                    cad+=matrix[n][i];
                }    
            }
            
            printf("%s\n", cad.c_str());
        }

        else{

            printf("INVALID\n");
        }
    }


    return 0;
}
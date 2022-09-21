//https://onlinejudge.org/external/130/13026.pdf
//13026

#include<vector>
#include<string>
#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int cases, size, i, n, m, counter;
    string cad, number;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i", &size);
        vector<string>strings;
        vector<string>respuesta;

        cin.ignore();

        for(n = 0; n<size; n++){
    
            getline(cin,cad);
            strings.push_back(cad);
        }

        getline(cin,number);

        for(n = 0; n<strings.size(); n++){

            counter = 0;

            for(m = 0; m<strings[n].size(); m++){

                if(strings[n][m] != number[m]){

                    counter+=1;
                }
            }

            if(counter <= 1){
                
                respuesta.push_back(strings[n]);
            }
        }

        printf("Case %i:\n", i);

        for(n = 0; n<respuesta.size(); n++){

            printf("%s\n", respuesta[n].c_str());
        }
    }


    return 0;
}
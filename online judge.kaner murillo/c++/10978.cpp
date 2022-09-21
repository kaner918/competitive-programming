//https://onlinejudge.org/external/109/10978.pdf
//10978

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    int size, i, n, position;
    string cad1, cad2;

    while(scanf("%i", &size) && size != 0){

        string arr1[size], arr2[size], response[size];

        for(i = 0; i<size; i++){

            cin>>cad1>>cad2;
            arr1[i] = cad1;
            arr2[i] = cad2;
            response[i] = "?";
        }

        position = 0;

        for(i = 0; i<size; i++){

            for(n = 0; n<arr2[i].length();){

                if(position>size-1){
                    position = 0;
                }

                if(response[position] == "?"){

                    position+=1;
                    n+=1;
                }

                else{

                    position+=1;
                
                }
            }

            response[position-1] = arr1[i];
        }

        for(i = 0; i<size-1; i++){

            printf("%s ", response[i].c_str());
        }

        printf("%s\n", response[size-1].c_str());
    }

    return 0;
}
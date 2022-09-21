#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    string cad, subCad;
    int i, n, power, posCad, p;
    bool ans;

    while(getline(cin,cad) && cad != "."){

        subCad = cad[0];
        ans = false;

        for(i = 1; i<(cad.length()/2)+1 && ans == false; i++){

            if(cad.length()%i == 0){
                
                posCad = 0;
                p = 1;
                //cout<<subCad<<endl;
                for(n = i; n<cad.length() && cad[n] == subCad[posCad]; n++){

                    posCad+=1;
                    if(posCad == subCad.length()){
                        posCad = 0;
                        p+=1;
                    }
                }

                if(n == cad.length()){

                    ans = true;
                }
            }

            subCad+=cad[i];
        }

        if(ans == true){

            printf("%i\n", p);
        }

        else{

            printf("1\n");
        }
    }

    return 0;
}
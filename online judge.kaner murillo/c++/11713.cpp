#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main(){

    int casos, i;
    string cadena1, cadena2;
    bool ans;
    char letra1, letra2;

    scanf("%i", &casos);

    while(casos--){

        cin>>cadena1>>cadena2;
        ans = true;
        i = 0;

        if(cadena1.length() == cadena2.length()){

            while(i<cadena1.length() && ans == true){

                letra1 = cadena1[i];
                letra2 = cadena2[i];

                if(((letra1 != 'a' && letra1 != 'e' && letra1 != 'i' && letra1 != 'o' && letra1 != 'u') || (letra2 != 'a' && letra2 != 'e' && letra2 != 'i' && letra2 != 'o' && letra2 != 'u')) && letra1 != letra2){
                    
                   ans = false;

                }

                i+=1;
            }
        }
        
        else{
            ans = false;
        }
        
        if(ans == true){
            printf("Yes\n");
        }

        else{
            printf("No\n");
        }
    }
    return 0;
}
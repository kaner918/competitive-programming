#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    int casos, i;  
    string cadena1, cadena2;
    char letra1, letra2;

    scanf("%i", &casos);
    cin.ignore();

    for(i = 1; i<casos+1; i++){
        
        getline(cin,cadena1);
        getline(cin,cadena2);
        
        if(cadena1.length() == cadena2.length() && cadena1 == cadena2){

            printf("Case %i: Yes\n", i);
        }

        else if(cadena1.length() == cadena2.length() && cadena1 != cadena2){

            printf("Case %i: Wrong Answer\n",i);
        }
        else{

            printf("Case %i: Output Format Error\n", i);
        }
    }
    return 0;
}
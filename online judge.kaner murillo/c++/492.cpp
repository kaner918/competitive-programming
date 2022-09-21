#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    int i;
    string cadena, cadena2;
    bool ans, flag1, flag2;
    char letra, letra2;

    while(getline(cin,cadena)){

        ans = false;
        flag1 = false;
        cadena2 = "";

        for(i = 0; i<cadena.length(); i++){

            letra = tolower(cadena[i]);

            if((letra >= 'b' && letra <= 'z') && letra != 'i' && letra!='e' && letra!='o' && letra!= 'u' && ans == false){
                
                letra2 = cadena[i];
                flag1 = true;
                ans = true;
            }

            else if((letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') && ans == false){
                
                cadena2+=cadena[i];
                flag1 = false;
                ans = true;

            }

            else if(letra >= 'a' && letra <= 'z' && ans == true){

                cadena2+=cadena[i];
            } 

            else{

                if(ans == true){

                    if(flag1 == true){

                        cadena2+=letra2;
                        cadena2+="ay";
                        cadena2+=cadena[i];
                    }

                    else{

                        cadena2+="ay";
                        cadena2+=cadena[i];
                    }

                    ans = false;
                }

                else{
                    cadena2+=cadena[i];
                }
            }

        }

        if(ans == true){

            if(flag1 == true){

                cadena2+=letra2;
                cadena2+="ay";
            }

            else{

                cadena2+="ay";
            }

            ans = false;
        }

        cout<<cadena2<<endl;

    }

    return 0;
}
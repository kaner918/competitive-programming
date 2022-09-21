//https://onlinejudge.org/external/16/1610.pdf
//1610

#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){

    int cInvitados, i, diferencia,posicion;
    vector<string>invitados;
    string cadena, cCadena;
    char letra,letra2;
    bool ans, ans2;

    while(scanf("%d", &cInvitados) && cInvitados!=0){
        
        invitados.clear();

        posicion = 0;
        ans  = false;
        ans2 = false;
        cCadena = "";

        for(i = 0; i < cInvitados; i++){

            cin>>cadena;
            invitados.push_back(cadena);
        }

        if(cInvitados == 2 && invitados[0]==invitados[1]){
            printf("%s\n", invitados[0].c_str());
        }
    
        else{

            sort(invitados.begin(), invitados.end());

            while(ans == false && posicion<invitados[(cInvitados/2)-1].length()){
                
                if(invitados[(cInvitados/2)-1][posicion]== invitados[cInvitados/2][posicion] && ans2 == false){
                    
                    cCadena+=invitados[(cInvitados/2)-1][posicion];
                    
                } 

                else{

                    ans2 = true;
                    
                    if(cCadena>= invitados[(cInvitados/2)-1] && cCadena <invitados[(cInvitados/2)]){
        
                        ans = true;
                    }

                    else{
                        
                        if(invitados[(cInvitados/2)-1][posicion] == 'Z'){
                            cCadena+='Z';
                        }

                        else{

                            letra = invitados[(cInvitados/2)-1][posicion]+1;
                            letra2 = invitados[(cInvitados/2)-1][posicion];
                            
                            if(cCadena+letra2>= invitados[(cInvitados/2)-1] && cCadena+letra2<invitados[(cInvitados/2)]){
                            
                                cCadena+=letra2;
        
                            }

                            else if(cCadena+letra>= invitados[(cInvitados/2)-1] && cCadena+letra<invitados[(cInvitados/2)]){
                    
                                cCadena+=letra;
        
                            }

                            else{
                                
                                cCadena+=letra2;

                            }
                            
                        }
                    }
                    
                }
                
                posicion+=1; 
            }
            printf("%s\n", cCadena.c_str());
    
        }
    }

    return 0;
}
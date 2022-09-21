//https://onlinejudge.org/external/5/514.pdf
//514

#include<stack>
#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){

    string cadena;
    int v,cantidad,i,n;
    vector<int>orden;

    bool ans;

    while(scanf("%i", &cantidad) && cantidad!=0){

        cin.ignore();

        while(getline(cin,cadena) && cadena != "0"){

            orden.clear();

            stack<int>estacion;
        
            stringstream stk(cadena);
            ans = true;

            while(stk>>v){
                orden.push_back(v);
            }

            i = 0;
            n = 1;

            
            while(n<orden.size()+1){

                estacion.push(n);

                if(estacion.top() == orden[i]){

                    while(!estacion.empty() && estacion.top() == orden[i]){

                        estacion.pop();
                        i+=1;

                    }    
                }

                n+=1;
            }

            while(!estacion.empty() && ans == true){
                
                if(estacion.top() == orden[i]){

                    estacion.pop();
                    i+=1;
                }

                else{
                    ans = false;
                }
                
            }

            if(ans == true){

                printf("Yes\n");
            }

            else{
                printf("No\n");
            }
        }

        printf("\n");
    }

    return 0;
}
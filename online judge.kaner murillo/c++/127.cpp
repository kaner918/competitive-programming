#include<stack>
#include<vector>
#include<string>
#include<cstdio>
#include<iostream>
#include<sstream>

using namespace std;

struct Pila{

    stack<string>cartas;

    Pila(){}
    Pila(string cade){

        cartas.push(cade);
    }

};

int main(){

    int i,n;
    vector<Pila>v;
    bool ans;

    string cadena1, cadena2, carta;

    while(getline(cin,cadena1) && cadena1 != "#"){

        v.clear();
        getline(cin,cadena2);
        cadena1+=" ";
        cadena1+=cadena2;

        stringstream stk(cadena1);

        while(stk>>carta){
            
            ans = false;

            if(v.size() >= 3 && (v[v.size()-3].cartas.top()[0] == carta[0] || v[v.size()-3].cartas.top()[1] == carta[1])){
                v[v.size()-3].cartas.push(carta);
                ans = true;
            }

            else if(v.size()>0 && (v.back().cartas.top()[0] == carta[0] || v.back().cartas.top()[1] == carta[1])){

                v.back().cartas.push(carta);
                ans = true;
            }

            else{
                
                v.push_back(Pila(carta));
            }

            if(ans == true){

                i = 0;

                while (i<v.size()){

                    if(i>=3 && (v[i].cartas.top()[0] == v[i-3].cartas.top()[0] || v[i].cartas.top()[1] == v[i-3].cartas.top()[1])){

                        v[i-3].cartas.push(v[i].cartas.top());
                        v[i].cartas.pop();

                        if(v[i].cartas.empty()){

                            auto remove = v.begin()+i;
                            v.erase(remove);
                        }

                        i = 0;
                    }

                    else if(i>0 && (v[i].cartas.top()[0] == v[i-1].cartas.top()[0] || v[i].cartas.top()[1] == v[i-1].cartas.top()[1])){

                        v[i-1].cartas.push(v[i].cartas.top());
                        v[i].cartas.pop();

                        if(v[i].cartas.empty()){

                            auto remove = v.begin()+i;
                            v.erase(remove);
                        }

                        i = 0;
                    }

                    else{
                        i+=1;
                    }
                }
                
            }
            
        }
        
        if(v.size() > 1){

            printf("%i piles remaining: ", v.size());
        }
        
        else{

            printf("%i pile remaining: ", v.size());
        }

        for(i = 0; i<v.size()-1; i++){

            printf("%i ", v[i].cartas.size());
        }
        
        printf("%i\n", v.back().cartas.size());
    }
    
    return 0;
}
//https://onlinejudge.org/external/126/12667.pdf
//12667

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Problemas{

    char letra;
    int tiempo = 0;
    vector<int>ids;

    Problemas(){}
    Problemas(char letr){
        letra = letr;
    }

};

int main(){

    int problemas, equipos, envios, id, tiempo, i, n, letra;
    string veredicto;
    char letrica, letra2;
    bool ans;
    vector<Problemas>vec;

    scanf("%i %i %i", &problemas, &equipos, &envios);

    for(i = 65; i<91; i++){
        letrica = i;
        vec.push_back(Problemas(letrica));
    }
    
    for(i = 0; i<envios; i++){

        cin>>tiempo>>id>>letra2>>veredicto;
        ans = true;

        letra2 = tolower(letra2);
        letra = letra2-97;

        if(veredicto == "Yes" && tiempo >= vec[letra].tiempo){

            for(n = 0; n<vec[letra].ids.size(); n++){

                if(vec[letra].ids[n] == id){
                    ans = false;
                }
            }

            if(ans == true){

                vec[letra].ids.push_back(id);
                vec[letra].tiempo = tiempo;
            }
        }
    }

    for(i = 0; i<problemas; i++){

        if(vec[i].ids.size() > 0){
            printf("%c %i %i\n", vec[i].letra, vec[i].tiempo, vec[i].ids.back());
        }

        else{
            printf("%c - -\n", vec[i].letra);
        }
    }

    return 0;
}
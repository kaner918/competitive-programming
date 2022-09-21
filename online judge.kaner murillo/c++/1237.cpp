//https://onlinejudge.org/external/12/1237.pdf
//1237

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Comp{

    string nombre;
    int inferior;
    int superior;

    Comp(){}
    Comp(string nomb, int inf, int sup){

        nombre = nomb;
        inferior = inf;
        superior = sup;
    }
};
int main(){

    int casos, companias, precios, precio, inferior, superior, i, contador;
    string nombre;
    vector<Comp>comp;
    bool ans;

    scanf("%i", &casos);

    while(casos--){

        scanf("%i", &companias);
        comp.clear();

        while(companias--){

            cin>>nombre>>inferior>>superior;

            comp.push_back(Comp(nombre,inferior,superior));
        }

        scanf("%i", &precios);

        while(precios--){

            scanf("%i", &precio);
            nombre = "";
            ans = false;
            contador = 0;
            i = 0;

            while(i<comp.size() && contador < 2){

                if(precio>= comp[i].inferior && precio<= comp[i].superior){

                    nombre = comp[i].nombre;
                    contador+=1;
                }
                i+=1;
            }

            if(contador>0 && contador<2){

                printf("%s\n", nombre.c_str());
            }

            else{

                printf("UNDETERMINED\n");
            }
            
        }

        if(casos>0){
            printf("\n");
        }
    }
    return 0;
}
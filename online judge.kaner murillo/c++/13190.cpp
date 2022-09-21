//https://onlinejudge.org/external/131/13190.pdf
//13190

#include<cstdio>
#include<iostream>
#include<deque>
#include<string>

using namespace std;

struct Pastilla{

    string nombre;
    int horario;
    int acomulado;

    Pastilla(){}

    Pastilla(string nom, int hor){

        nombre = nom;
        horario = hor;
        acomulado = hor;
    }
};

int main(){

    int i, n, contador, casos, cantidad, totalSuministradas, horario, menor;
    string nombre;


    scanf("%i", &casos);

    while(casos--){
        
        menor = 0;
        deque<Pastilla>reseta;
        scanf("%i %i", &cantidad, &totalSuministradas);

        while(cantidad--){

            cin>>nombre>>horario;

            if(horario<menor){

                menor = horario;
            }
            reseta.push_back(Pastilla(nombre,horario));
        }

        contador = menor;
        i = 0;

        while(i<totalSuministradas){

            for(n = 0; n<reseta.size() && i<totalSuministradas; n++){

                if(contador == reseta[n].acomulado){

                    printf("%i %s\n", contador, reseta[n].nombre.c_str());
                    reseta[n].acomulado+=reseta[n].horario;
                    i+=1;
                }

            }
            
            contador+=1;
        }
        
    }

    return 0;
}
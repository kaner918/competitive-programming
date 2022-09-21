//https://onlinejudge.org/external/116/11629.pdf
//11629

#include<cstdio>
#include<iostream>
#include<deque>
#include<string>

using namespace std;

struct Candidato{

    string nombre;
    double votos;

    Candidato(){}

    Candidato(string nom, double vot){

        nombre = nom;
        votos = vot*10;
    }
};

using namespace std;

int main(){

    int candidatos, suposiciones, i, n, m, suposicion;
    double promedio;
    char nombre[21];
    string cadena, nombre2 = "", comparador, numero;
    deque<Candidato>votaciones;
    bool ans, flag;

    scanf("%i %i", &candidatos, &suposiciones);

    for(i = 0; i<candidatos; i++){

        scanf("%s %lf\n", nombre, &promedio);
        votaciones.push_back(Candidato(nombre, promedio));
        
    }
    
    for(i = 1; i<suposiciones+1; i++){

        getline(cin,cadena);
        promedio = 0;
        flag = false;
        nombre2 = "";
        numero = "";

        for(n = 0; n<cadena.length(); n++){

            while(cadena[n] != '<' && cadena[n] != '>' && cadena[n] != '=' && flag == false){
                
                if((cadena[n] >= 'a' && cadena[n] <= 'z') || (cadena[n] >= 'A' && cadena[n] <= 'Z') || (cadena[n] >= '0' && cadena[n] <= '9')){
                    
                    nombre2+=cadena[n];
                }

                else if(cadena[n] == 32){

                    ans = false;

                    for(m = 0; m<votaciones.size() && ans == false; m++){

                        if(votaciones[m].nombre == nombre2){
                            promedio+= votaciones[m].votos;
                            nombre2 = "";
                            ans = true;
                        }
                    }
                }

                n+=1;
            }
            flag = true;
    
            if(cadena[n] == '<' && cadena[n+1] != 32 && ans == true){
                    
                    comparador = "<=";
                    ans = false;
                }

            else if(cadena[n] == '>' && cadena[n+1] != 32 && ans == true){

                    comparador = ">=";
                    ans = false;
            }

            else if((cadena[n] == '<' || cadena[n] == '>' || cadena[n] == '=') && ans == true){
                    comparador = cadena[n];
                    ans = false;
                }

            else if(cadena[n]>= '0' && cadena[n]<='9'){

                    numero+=cadena[n];
            }
            
        }

        suposicion = stoi(numero);
        
        //cout<<i<<"--"<<promedio<<" "<<suposicion<<" "<<comparador<<endl;

        if(comparador == "<" && promedio<suposicion*10){

            flag = false;
        }

        else if(comparador == ">" && promedio>suposicion*10){

            flag = false;
        }

        else if(comparador == ">=" && promedio>=suposicion*10){

            flag = false;
        }

        else if(comparador == "<=" && promedio<=suposicion*10){

            flag = false;
        }

        else if(comparador == "=" && promedio==suposicion*10){

            flag = false;
        }

        if(flag == false){

            printf("Guess #%i was correct.\n", i);
        }

        else{
            printf("Guess #%i was incorrect.\n", i);
        }
    }

    return 0;

}
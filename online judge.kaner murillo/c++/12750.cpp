//https://onlinejudge.org/external/127/12750.pdf
//12750

#include<cstdio>
#include<iostream>

using namespace std;

int main(){

    int casos, partidos, contador, suma, i;
    char resultado;
    bool ans;

    scanf("%i", &casos);

    for(i = 1; i<casos+1; i++){

        scanf("%i", &partidos);
        ans = true;
        suma = 0;
        contador = 0;

        while(partidos--){

            cin.ignore();

            scanf("%c", &resultado);

            contador++;

            if(ans == true){
                suma++;
            }

            if(resultado == 'W'){
                contador = 0;
            }

            else if(contador == 3){
                ans = false;
            }

        }

        if(ans == false){
            printf("Case %i: %i\n", i,suma);
        }

        else{
            printf("Case %i: Yay! Mighty Rafa persists!\n", i);
        }
        
    }
   
    return 0;
}
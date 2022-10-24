//https://onlinejudge.org/external/124/12488.pdf
//12488

#include<cstdio>
#include<iostream>

using namespace std;

int init[24], finish[24];

int main(){

    int size, n, m, counter, aux;

    while(scanf("%i", &size) != EOF){

        for(n = 0; n<(size*2); n++){

            if(n<size){

                scanf("%i", &init[n]);
            }

            else{

                scanf("%i", &finish[n-size]);
            }
        }

        counter = 0;

        for(n = 0; n<size; n++){

            m = n+1;

            while(m<size && init[n] != finish[n]){
                
                aux = init[n];

                init[n] = init[m];
                init[m] = aux;

                counter++;
                m+=1;
            }
        }

        printf("%i\n", counter);
    }


    return 0;
}

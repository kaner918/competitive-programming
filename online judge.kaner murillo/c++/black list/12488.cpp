//https://onlinejudge.org/external/124/12488.pdf
//12488

#include<cstdio>
#include<iostream>

using namespace std;

int overtakes(int *arr1, int *arr2, int size){

    int moviments = 0, aux;

    while(arr1[size] != arr2[size]){

        aux = arr1[size];
        arr1[size] = arr1[size-1];
        arr1[size-1] = aux;
        moviments++;
        size--;
    }

    return moviments;
}


int main(){

    int size, moviments, counter, position, i, v;

    while(scanf("%i", &size) != EOF){

        int arr1[size], arr2[size];
        counter = 0;
        position = 1;

        for(i = 0; i<size; i++){

            cin>>v;
            arr1[i] = v;
            
        }

        for(i = 0; i<size; i++){

            cin>>v;
            arr2[i] = v;

        }

        for(i = 0; i<size; i++){

            moviments = overtakes(arr1, arr2, size-position);

            if(moviments == 0){
                position++;
            }

            counter+= moviments; 
        }

        printf("%i\n", counter);
    }

    return 0;
}
//https://onlinejudge.org/external/123/12356.pdf
//12356

#include<cstdio>
#include<iostream>

using namespace std;

int lefts[100100], rights[100100];

int main(){

    int army, consults, i, n, low, hight;

    while(scanf("%i %i", &army, &consults) && (army || consults)){

        for(i = 0; i<army; i++){

            lefts[i] = i-1;
            rights[i] = i+1;           
        }

        lefts[0] = -1;
        rights[army-1] = -1;

        for(n = 0; n<consults; n++){

            scanf("%i %i", &low, &hight);
            
            low--;
            hight--;
             
            lefts[rights[hight]] = lefts[low]; 
            rights[lefts[low]] = rights[hight];

            if(lefts[rights[hight]] == -1){
                printf("*");
            }

            else{

                printf("%i", lefts[rights[hight]]+1);
            }

            if(rights[lefts[low]] == -1){
                printf(" *\n");
            }

            else{

                printf(" %i\n", rights[lefts[low]]+1);
            }
        }

        printf("-\n");
    }

    return 0;
}
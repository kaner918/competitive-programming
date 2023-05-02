//https://onlinejudge.org/external/123/12356.pdf
//12356

#include<cstdio>
#include<iostream>

using namespace std;

int lefts[100100], rights[100100], lives[100100];

int main(){

    int army, consults, i, n, low, hight, aux1, aux2, aux3, aux4;

    while(scanf("%i %i", &army, &consults) && (army || consults)){

        for(i = 0; i<army; i++){

            lefts[i] = i-1;
            rights[i] = i+1; 
            lives[i] = 1;           
        }

        lefts[0] = -1;
        rights[army-1] = -1;

        for(n = 0; n<consults; n++){

            scanf("%i %i", &low, &hight);
            
            low--;
            hight--;

            aux1 = low;
            aux2 = hight;

            aux3 = low;
            aux4 = hight;
            
            lives[low] = 0;
            lives[hight] = 0;

            lefts[hight] = lefts[low];
            rights[low] = rights[hight];

            cout<<lefts[low]+1<<" vida "<<lives[lefts[low]]<<" "<<rights[low]+1<<" vida "<<lives[rights[low]]<<endl;

            while(!lives[rights[aux1]] &&  hight<army-1){
                
                /* cout<<"peo"<<endl; */

                aux2 = rights[aux1];
                rights[aux1] = rights[aux2];
            }

            aux1 = rights[aux1];

            /* cout<<"holaaaaa"<<endl; */

            while(aux3 > 0 && !lives[lefts[aux4]] && aux3 != -1){
                
                /* cout<<"holi"<<endl; */

                aux3 = lefts[aux4];
                lefts[aux4] = lefts[aux3];
            }

            aux2 = lefts[aux4];

            if(aux1 == -1){
                aux2 = -1;
            }


            if(aux2 == -1){
                printf("*");
            }

            else{

                printf("%i", aux2+1);
            }

            if(aux1 == -1){
                printf(" *\n");
            }

            else{

                printf(" %i\n", aux1+1);
            }
        }

        printf("-\n");
    }

    return 0;
}
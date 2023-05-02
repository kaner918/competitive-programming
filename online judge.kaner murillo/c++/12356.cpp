//https://onlinejudge.org/external/123/12356.pdf
//12356

#include<cstdio>
#include<iostream>

using namespace std;

int lefts[100100], rights[100100], lives[100100];

int main(){

    int army, consults, i, n, low, hight, aux1, aux2, aux3, aux4;

    while(scanf("%i %i", &army, &consults) && (army || consults)){

        for(i = 1; i<army; i++){

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

            aux1 = lefts[low];
            aux2 = rights[hight];

            aux3 = low;
            aux4 = hight;
            
            lives[low] = 0;
            lives[hight] = 0;

            /* if(hight<army-1){

            } */

            /* if(low>0){

            } */

            if(low != hight){
                
                lefts[rights[hight]] = lefts[low]; 
                aux1 = lefts[rights[hight]];
                rights[lefts[low]] = rights[hight];
                aux2 =  rights[lefts[low]];
            }

            else{
                
                if(low){

                    lefts[rights[low]] = lefts[low]; 
                    aux1 = lefts[rights[low]];
                }

                else{

                    cout<<"hol"<<endl;
                    lefts[rights[low]] = -1; 
                    aux1 = lefts[rights[low]];
                }

                if(hight<army-1){

                    rights[lefts[hight]] = rights[hight];
                    aux2 =  rights[lefts[low]];
                }

                else{

                    rights[lefts[hight]] = -1;
                    aux2 =  rights[lefts[low]];
                }
            }

            if(aux1 == -1){
                printf("*");
            }

            else{

                printf("%i", aux1+1);
            }

            if(aux2 == -1){
                printf(" *\n");
            }

            else{

                printf(" %i\n", aux2+1);
            }

            for(i = 0; i<army; i++){

                cout<<lefts[i]<<" ";
            }

            cout<<endl;

            for(i = 0; i<army; i++){

                cout<<rights[i]<<" ";
            }

            cout<<endl;
        }

        printf("-\n");
    }

    return 0;
}
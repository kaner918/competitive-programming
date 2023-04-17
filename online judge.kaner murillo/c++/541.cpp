//https://onlinejudge.org/external/5/541.pdf
//541

#include<cstdio>
#include<iostream>

int arr[101][101];

int main(){

    int size, i, n, counter, counter3, counter4, row, colum, row2, colum2, las1, las2, las3, las4, sum1, sum2;

    while(scanf("%i", &size) && size){

        counter = 0;
        counter3 = 0;
        counter4 = 0;

        for(i = 0; i<size; i++){

            for(n = 0; n<size; n++){
                
                scanf("%i", &arr[i][n]);
            }
        }

        for(i = 0; i<size; i++){

            sum1 = 0;
            sum2 = 0;

            for(n = 0; n<size; n++){
                
                sum1+=arr[i][n];
                sum2+=arr[n][i];
            }

            if(sum1%2){

                if(counter <= 1){
                    
                    row = i;
                    colum = n;
                }

                counter3 ++;
                counter++;
            }

            if(sum2%2 ){

                if(counter <= 1){
                    
                    row2 = n;
                    colum2 = i;
                }

                counter4++;
                counter++;
            }
        }

        if(!counter){

            printf("OK\n");
        }

        else if(counter == 2 && counter3 == counter4){

            printf("Change bit (%i,%i)\n", row+1, colum2+1);
        }

        else{

            printf("Corrupt\n");
        }

    }

    return 0;
}
//https://onlinejudge.org/external/9/946.pdf
//946

#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int boxs[101];

int main(){

    int size, i, sum, maxi, res, index, auxIndex, sizeBox;

    while(scanf("%i", &size) != EOF){

        sum = 0;
        index = 0;

        while(size--){

            scanf("%i", &sizeBox);

            if(!index){
                sum+=sizeBox;
                boxs[index] = sizeBox;
            }

            else{   
                
                res = -1;
                maxi = INT_MAX;

                for(auxIndex = 0; auxIndex<index; auxIndex++){

                    if(sizeBox <= boxs[auxIndex]){

                        if(boxs[auxIndex] <= maxi){
                            maxi = boxs[auxIndex];
                            res = auxIndex;
                        }
                    }

                }
                
                if(res == -1){
                    sum+=sizeBox;
                }                

                else{

                    boxs[res]-=sizeBox;
                }    

                boxs[index] = sizeBox;
            }

            index++;
        }

        printf("%i\n", sum);
    }

    return 0;
}
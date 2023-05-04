//https://onlinejudge.org/external/9/946.pdf
//946

#include<cstdio>
#include<iostream>

using namespace std;

int boxs[101], auxBox[101];

int main(){

    int size, i, sum, index, sizeBox;

    while(scanf("%i", &size) != EOF){

        sum = 0;
        index = 0;

        while(size--){

            scanf("%i", &sizeBox);


            if(!index){
                sum+=sizeBox;
                boxs[index] = sizeBox;
                auxBox[index] = 0;
                index++;
            }

            else{

                
                if(sizeBox <= auxBox[index-1]){

                    boxs[index] = boxs[index-1];
                    auxBox[index] = auxBox[index-1] - sizeBox;
                }

                else if(sizeBox <= boxs[index-1]){

                    boxs[index] = boxs[index-1] - sizeBox;
                    auxBox[index] = sizeBox;
                }

                else{

                    sum+=sizeBox;
                    boxs[index] = sizeBox;
                    auxBox[index] = 0;
                }
                
                index++;
            }
        }

        printf("%i\n", sum);
    }

    return 0;
}
#include<cmath>
#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int cases, cases2, size, i, x1, y1, x2, y2, res1, res2;

    scanf("%i", &cases);
    cin.ignore();

    for(i = 0; i<cases; i++){

        scanf("%i", &cases2);
        scanf("%i", &size);

        while(cases2--){

            scanf("%i %i %i %i", &x1, &y1, &x2, &y2);
        
            res1 = abs(x1-x2);
            res2 = abs(y1-y2);

            if(x1<1 || x1 > size || y1<1 || y1 > size || x2<1 || x2 > size || y2<1 || y2 > size){

                printf("no move\n");
            }

            else if(x1 == x2 && y1 == y2){

                printf("0\n");
            }

            else if(res1 == res2){

                printf("1\n");
            }

            else if((res1 % 2 == 0 && res2 % 2 == 0) || (res1 % 2 == 1 && res2%2 == 1)){

                printf("2\n");
            }

            else{

                printf("no move\n");
            }
        }

        if(i<cases-1){

            cin.ignore();
        }
    }
}
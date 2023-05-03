//https://onlinejudge.org/external/6/665.pdf
//665

#include<cstdio>
#include<iostream>

int coins[110], consult[110];

using namespace std;

int main(){

    int cases, size, n, i, querys, number;
    char res;
    bool flag;

    scanf("%i", &cases);

    while(cases--){

        cin.ignore();
        flag = true;   
        number = -1; 
        scanf("%i %i", &size, &querys);

        for(i = 0; i<size; i++){

            coins[i] = 0;    
        }

        while(querys--){

            scanf("%i", &n);

            for(i = 0; i<n*2; i++){
                scanf("%i", &consult[i]);
            }

            cin.ignore();
            scanf("%c", &res);

            if(res == '='){

                for(i = 0; i<n*2; i++){
                    coins[consult[i]-1] = 1;
                }
            }
        }

        for(i = 0; i<size && flag; i++){

            if(!coins[i]){

                if(number == -1){
                    
                    number = i+1;
                }
                
                else{

                    flag = false;
                }
            }
        }

        if(flag){

            printf("%i\n", number);
        }

        else{

            printf("0\n");
        }

        if(cases){
            printf("\n");
        }
    }

    return 0;
}
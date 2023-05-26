//https://onlinejudge.org/external/106/10651.pdf
//10651

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;
int mini;

void solved(vector<char>&cad){

    int i, counter = 0;

    for(i = 0; i<12; i++){

        if(cad[i] == 'o'){
            counter++;
        }
    }

    mini = min(mini, counter);

    for(i = 0; i<12; i++){

        if(i + 2 < 12 && cad[i] == '-' && cad[i+1] == 'o' && cad[i+2] == 'o'){

            cad[i] = 'o';
            cad[i+1] = '-';
            cad[i+2] = '-';
            solved(cad);
            cad[i] = '-';
            cad[i+1] = 'o';
            cad[i+2] = 'o';
        }

        if(i - 2 > -1 && cad[i] == '-' && cad[i-1] == 'o' && cad[i-2] == 'o'){

            cad[i] = 'o';
            cad[i-1] = '-';
            cad[i-2] = '-';
            solved(cad);
            cad[i] = '-';
            cad[i-1] = 'o';
            cad[i-2] = 'o';
        }
    }
}

int main(){

    int cases, i;
    char letter;
    scanf("%i", &cases);

    while(cases--){

        vector<char>cad(12);
        mini = 12;
        cin.ignore();
        
        for(i = 0; i<12; i++){

            scanf("%c", &letter);
            cad[i] = letter;
        }

        solved(cad);

        printf("%i\n", mini);
    }

    return 0;
}

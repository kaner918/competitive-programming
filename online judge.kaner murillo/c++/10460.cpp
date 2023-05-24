//https://onlinejudge.org/external/104/10460.pdf
//10460

#include<cstdio>
#include<iostream>
#include<deque>
#include<string>

using namespace std;

int counter;
deque<char>last;

void solved(int index, string&cad, deque<char>&comb){

    if(counter){

        if(index == cad.length()){

            last = comb;
            counter--;

            /* int i;
            for(i = 0; i<comb.size(); i++){
                printf("%c", comb[i]);
            }
            printf("\n");

            if(!counter){
                int i;
                for(i = 0; i<comb.size(); i++){
                    printf("%c", comb[i]);
                }
                printf("\n");
            } */
        }
 
        else{

            int i;

            comb.push_front(cad[index]);
            solved(index+1, cad, comb);

            for(i = 0; i<comb.size()-1; i++){   
                swap(comb[i], comb[i+1]);
                solved(index+1, cad, comb);
                /* swap(comb[i], comb[i+1]); */
            }

            comb.pop_back();
        }
    }
}

int main(){ 

    int cases, i;
    string cad;

    scanf("%i", &cases);

    while(cases--){

        cin.ignore();
        getline(cin, cad);
        scanf("%i", &counter);
        deque<char>comb = {cad[0]};

        solved(1, cad, comb);

        for(i = 0; i<last.size(); i++){
            cout<<last[i];
        }
        printf("\n");
    }

    return 0;
}

//https://onlinejudge.org/external/104/10460.pdf
//10460

#include<cstdio>
#include<iostream>
#include<deque>
#include<string>

using namespace std;


int counter;
unsigned long long int factorial;
unsigned long long int low;

deque<char>last;

void calFactorial(int size){

    int i;
    factorial = 1;

    for(i = 1; i<= size; i++){
        factorial*=i;
    }
}

void solved(int index, int find, string&cad, deque<char>comb){

    if(counter){

        int i;
        cout<<low<<" "<<factorial<<endl;

        if(comb.size() == cad.length()-1){

            int i = 0;
            comb.push_front(cad[index]);
            for(i = 0; i<comb.size(); i++){
                cout<<comb[i];
            }
            printf("\n");
            i = 0;
            while(low < find-1){
                swap(comb[i], comb[i+1]);
                
                low++;
                i++;
            }

            last = comb;
        }
 
        else{

            int i;

            comb.push_front(cad[index]);

            unsigned long long int aux = low;
            unsigned long long int sum = factorial/comb.size();
            unsigned long long int pre = factorial/comb.size();

            if(find <= factorial/comb.size()){
                factorial /= comb.size();
                solved(index+1, find, cad, comb);
            } 

            else{

                i = 0;
                while(find > aux+sum){
                    swap(comb[i], comb[i+1]);
                    pre = aux;
                    aux+=sum;
                    i++;    
                }

                low = aux;
                solved(index+1, find, cad, comb);
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
        
        calFactorial(cad.length());
        low = 0;

        solved(1, counter, cad, comb);

        for(i = 0; i<last.size(); i++){
            cout<<last[i];
        }
        printf("\n");
    }

    return 0;
}

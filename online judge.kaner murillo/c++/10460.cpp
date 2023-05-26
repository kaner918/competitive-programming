//https://onlinejudge.org/external/104/10460.pdf
//10460

#include<cstdio>
#include<iostream>
#include<deque>
#include<string>
#include<cmath>

using namespace std;

long long int counter;
long double factorial;
long double low;

deque<char>last;

void calFactorial(int size){

    int i;
    factorial = 1;

    for(i = 1; i<= size; i++){
        factorial*=i;
    }
}

void solved(int index, int find, string&cad, deque<char>&comb){

        int i;

        if(comb.size() == cad.length()-1){
   
            comb.push_front(cad[index]);
            
            i = 0;
            while(low < find-1){
                swap(comb[i], comb[i+1]);
                
                low++;
                i++;
            }

            last = comb;
        }
 
        else{

            comb.push_front(cad[index]);

            long double aux = low;
            long double sum = (factorial-low)/(comb.size()*1.0);

            i = 0;
            while(find > aux+sum){
                swap(comb[i], comb[i+1]);
                aux+=sum;
                i++;    
            }

            low = aux;
            factorial = aux + sum;
            solved(index+1, find, cad, comb);
    
        }
}

int main(){ 

    int cases, i;
    string cad;

    scanf("%i", &cases);

    while(cases--){

        cin>>cad>>counter;

        if(cad.length() <= 1){
            cout<<cad<<endl;
        }

        else{

            deque<char>comb = {cad[0]};
            
            calFactorial(cad.length());
            low = 0;

            solved(1, counter, cad, comb);

            for(i = 0; i<last.size(); i++){
                cout<<last[i];
            }
            printf("\n");
        }
    }

    return 0;
}

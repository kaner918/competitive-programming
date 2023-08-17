//https://onlinejudge.org/external/116/11687.pdf
//11687

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int count(long long int number){

    if(!number){
        return 1;
    }
    
    int counter = 0;
    while(number>0){
        number/=10;
        counter++;
    }
    return counter;
}

int solved(long long int number, int sum){

    int digits = count(number);

    if(number == digits){
        return sum+1;
    }

    else{
        return solved(digits, sum+1);
    }
}

int main(){

    string line;
    int i, counter;
    long long int number;

    while(getline(cin, line) && line != "END"){

        cout<<line<<endl;
        number = 0;
        counter = 0;

        for(i = 0; i<line.length(); i++){
            number = number * 10 + line[i]-48;
        }

        printf("%i\n", solved(number, 0));
    }    

    return 0;
}